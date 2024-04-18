import java.util.*;


class Book{
	private String title;
	private String author;
	private Integer year;

	Book(String t, String a, Integer y){
		this.title = t;
		this.author = a;
		this.year = y;
	}

	public String getTitle(){
		return this.title;
	}

	public String getAuthor(){
		return this.author;
	}

	public Integer getYear(){
		return this.year;
	}

	@Override
	public int hashCode(){
		return this.title.hashCode();
	}

	public String toString(){
		return this.title + "," + this.author + "," + this.year;
	}
}

class Collection{
	private String name;
	private List<Book> books;

	Collection(String n){
		this.name = n;
		this.books = new ArrayList<>();
	}

	public void addBook(Book b){
		if( this.books.contains(b) ) return;
		this.books.add(b);
	}

	public String getName(){
		return this.name;
	}

	public List<Book> getBooks(){
		return this.books;
	}
}

class BookStore{
	private HashMap<Book, Integer> books;
	private List<Collection> collections;

	BookStore(){
		this.books = new HashMap<>();
		this.collections = new ArrayList<>();
	}

	public void addBook(Book b){
		if( this.books.containsKey(b)){
			this.books.put(b, this.books.get(b) + 1);
		}else{
			this.books.put(b, 1);
		}
	}

	public void addCollection(Collection c){
		if( this.collections.contains(c) ) return;
		this.collections.add(c);
	}

	public List<String> getCollectionSummary(){
		List<String> output = new ArrayList<>();
		String buffer;
		int count;

		for(Collection c: this.collections){
			count = 0;
			for(Book b: c.getBooks()){
				count += this.books.get(b);
			}
			output.add("(" + c.getName() + ", " + count + ")");
		}

		return output;
	}
}







public class MQ1a{
	public static void main(String[] args) {
		var b1 = new Book("titlto", "auore", 1912);
		var b2 = new Book("titlto2", "auore", 1912);
		var b3 = new Book("titlto3", "auore", 1912);
		var Romanzi = new Collection("Romanzi");
		var Thriller = new Collection("Thriller");
		var myStore = new BookStore();
		myStore.addBook(b1);
		myStore.addBook(b2);
		myStore.addBook(b3);

		Romanzi.addBook(b1);
		Thriller.addBook(b2);
		Thriller.addBook(b3);

		myStore.addCollection(Romanzi);
		myStore.addCollection(Thriller);

		//myStore.getCollectionSummary();
		System.out.println(myStore.getCollectionSummary());
	}
}