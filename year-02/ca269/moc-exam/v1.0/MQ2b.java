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

	@Override
	public boolean equals(Object obj){
		if( this == obj ) return true;
		if( !(obj instanceof Book)) return false;

		Book that = (Book) obj;

		return  this.title.equals(that.getTitle())   &&
				this.author.equals(that.getAuthor()) &&
				this.year.equals(that.getYear());
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

	public void removeBook(Book b){
		if( !this.books.contains(b) ) return;
		this.books.remove(b);
	}

	public String getName(){
		return this.name;
	}

	public List<Book> getBooks(){
		List<Book> result = new ArrayList<>(this.books);
		result.sort((one, two) -> one.getTitle().compareTo(two.getTitle()));
		return result;
	}
}

interface StoreTemplate{
	void addBook(Book b);
	void addCollection(Collection c);
	void assignCollection(Book b, Collection c);
	void removeCollection(Book b, Collection c);
	int checkBook(String title, String author, Integer year);
	List<String> getCollectionSummary();
	List<String> shelvingAssignment();
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

	public void assignCollection(Book b, Collection c){
		this.addBook(b);
		c.addBook(b);
	}

	public void removeCollection(Book b, Collection c){
		c.removeBook(b);
	}

	public int checkBook(String title, String author, Integer year){
		Book buffer = new Book(title, author, year);

		if( !this.books.containsKey(buffer)) return 0;

		return this.books.get(buffer);
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

	public List<String> shelvingAssignment(){
		List<String> output = new ArrayList<>();
		int count;
		int totShelvels;

		for(Collection c: this.collections){
			count = 0;
			for(Book b: c.getBooks())
				count += this.books.get(b);

			totShelvels = count / 5;
			if( count % 5 > 0 ){
				totShelvels += 1;
			}
			output.add(c.getName() + " has " + count + " books" +" displayed in " + totShelvels + " shelves");
			for(int i = 0; i < count / 5; i++){
				output.add(c.getName() + "-" + (i + 1) + " with 5 books");
			}

			if( count % 5 > 0 ){
				output.add(c.getName() + "-" + (count / 5 + 1) + " with " + (count % 5 ) + " books");
			}
		}

		return output;
	}


	public List<Exception> validateInventory(){
		List<Exception> output = new ArrayList<>();
		boolean found;
		for(Book b: this.books.keySet()){
			if( this.books.get(b) == 0 ){
				output.add(new BookNotFound(b));
			}

			found = false;
			for(Collection c: this.collections){
				if( c.getBooks().contains(b)){
					found = true;
					break;
				}
			}

			if(!found){
				output.add(new UnsortedBook(b));
			}
		}

		return output;
	}
}


class BookNotFound extends Exception{
	private Book book;
	BookNotFound(Book b){
		this.book = b;
	}

	public Book getBook(){
		return this.book;
	}
}

class UnsortedBook extends Exception{
	private Book book;
	UnsortedBook(Book b){
		this.book = b;
	}

	public Book getBook(){
		return this.book;
	}

	// public String toString(){
	// 	return book.toString();
	// }
}


public class MQ2b{
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

		var b4 = new Book("brimi", "auore", 1912);

		myStore.assignCollection(b4, Romanzi);
		System.out.println(myStore.getCollectionSummary());

		myStore.removeCollection(b4, Romanzi);
		System.out.println(myStore.getCollectionSummary());

		System.out.println(myStore.checkBook("titlto", "auore", 1912));

		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		myStore.assignCollection(new Book("Annasila","ann",789), Thriller);
		System.out.println(Thriller.getBooks());

		for(String line: myStore.shelvingAssignment()){
			System.out.println(line);
		}

		System.out.println(myStore.validateInventory());
	}
}