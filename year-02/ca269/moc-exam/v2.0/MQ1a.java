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
}