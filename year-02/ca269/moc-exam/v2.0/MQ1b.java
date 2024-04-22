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

class BookStore{
	List<Book> inventory;
	List<Collection> collections;

	BookStore(){
		this.inventory = new ArrayList<>();
		this.collections = new ArrayList<>();		
	}

	public hasMap<String, Integer> getCollectionSummary(){
		hashMap<String, Integer> result = new hashMap<>();

		for(Collection c: this.collections){
			result.put(c.name, c.mylist.size());
		}

		return result;
	}

	public void assignCollection(Book b, Collection c){
		if( c.mylist.contains(b) ) return;
		c.mylist.add(b);
	}

	public void removeCollection(Book b, Collection c){#
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
}