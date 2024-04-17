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