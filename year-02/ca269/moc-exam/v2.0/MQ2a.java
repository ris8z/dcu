import java.util.*;

class Book{
	String title;
	String author;
	int year;
	int copy;
}

class Collection{
	 String name;
	 List<Book> mylist;

	 Collection(String n){
	 	this.name = n;
	 	this.mylist = new ArrayList<>();
	 }

	 public List<Book> getBooks(){
	 	List<Book> result = new ArrayList<>(this.mylist);
	 	result.sort((one, two) -> one.title.compareTo(two.title));
	 	return result;
	 }
}

interface StoreTemplate{
	Map<String, Integer> getCollectionSummary();
	void assignCollection(Book b, Collection c);
	void removeCollection(Book b, Collection c);
	int checkBook(String title, String author, int year);
	Map<String, List<Book>> shelvingAssignment();
}

class BookStore{
	List<Book> inventory;
	List<Collection> collections;

	BookStore(){
		this.inventory = new ArrayList<>();
		this.collections = new ArrayList<>();		
	}

	public Map<String, Integer> getCollectionSummary(){
		Map<String, Integer> result = new hashMap<>();

		for(Collection c: this.collections){
			result.put(c.name, c.mylist.size());
		}

		return result;
	}

	public void assignCollection(Book b, Collection c){
		if( c.mylist.contains(b) ) return;
		c.mylist.add(b);
	}

	public void removeCollection(Book b, Collection c){
		if( !c.mylist.contains(b) ) return;
		c.mylist.remove(b)
	}

	public int checkBook(String title, String author, int year){
		for(Book b: this.inventory){
			if( b.title.equals(title)  &&
				b.author.equals(author) &&
				b.year == year){
				return b.size();
			}
		}
		return 0;
	}

	public Map<String, List<Book>> shelvingAssignment(){
		
		Map<String, List<Book>> output = new hashMap<>();
		List<Book> lst;
		int labelCnt;

		for(Collection c: this.collections){
			lst = new ArrayList<>();
			labelCnt = 1;

			for(Book b: c.mylist){
				if( lst.size() == 5 ){
					output.put(c.name + " " + labelCnt, lst);
					labelCnt += 1;
					lst = new ArrayList<>();
				}
				lst.add(b);
			}

			if( lst.size() > 0 ){
				output.put(c.name + " " + labelCnt, lst);
			}
		}

		return output;	
	}

	public List<BookExecption> validateInventoiry(){
		List<BookExecption> output = new ArrayList<>();
		boolean found;

		for(Book b: this.inventory){
			if( b.copy == 0 ){
				output.add(new BookNotFound(b));
			}

			found = false;
			for(Collection c: this.collections){
				if(c.mylist.contains(b)){
					found = true;
					break;
				}
			}

			if(!found){
				output.add(new UnsortedBook(b))
			}
		}

		return output;
	}
}


class BookExecption extends Exception{
	Book cause;
	BookExecption(Book b){
		this.cause = b;
	}
}

class BookNotFound extends BookExecption{
	BookNotFound(Book b){
		super(b);
	}
}

class UnsortedBook extends BookExecption{
	UnsortedBook(book b){
		super(b);
	}
}



/*
import java.util.*;

class Book implements Comparable<Book>{
	private String title;
	private String author;


	Book(String t, String a){
		this.title = t;
		this.author = a;
	}


	public void setTitle(String t){
		this.title = t;
	}

	public void setAuthor(String a){
		this.author = a;
	}

	public String getTitle(){
		return this.title;
	}

	public String getAuthor(){
		return this.author;
	}



	@Override
	public boolean equals(Object obj){
		if ( this == obj ) return true;
		if ( !( obj instanceof Book ) ) return false;

		Book that = (Book) obj;
		
		return this.title == that.title && this.author == that.author;
	}

	@Override
	public int  hashCode(){
		return this.title.hashCode();
	}

	@Override
	public int compareTo(Book that){
		return this.title.compareTo(that.title);
	}


	public String toString(){
		return "(" + this.title + "," + this.author + ")";
	}
}

class AuthorCompareator implements Comparator<Book>{
	public int compare(Book one, Book two){
		return one.getAuthor().compareTo(two.getAuthor());
	}
}

class test{
	public static void main(String[] args) {
		System.out.println("main");
		List<Book> mylist = new ArrayList<Book>();
		mylist.add(new Book("GOT 1","Martin"));
		mylist.add(new Book("GOT 2","Martin"));
		mylist.add(new Book("MarioBros", "Arianna"));
		mylist.add(new Book("Amore amaro", "Luce"));
		//per sortare possiamo usare due cose
		//1) Collections.sort(List) {sorta la lista usando compareTo}
		//2) list.sort(Compartor){sorata usando comparotr o lambda}



		System.out.println(mylist);
		//Collections.sort(mylist);
		//mylist.sort(new AuthorCompareator());
		//mylist.sort((one, two) -> one.getTitle().compareTo(two.getTitle()));
		System.out.println(mylist);
	}
}

*/