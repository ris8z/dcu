import java.util.*;

class Book implements Comparable<Book>{
	public String title;
	public Integer pubYear;

	Book(String title, Integer pubYear){
		this.title = title;
		this.pubYear = pubYear;
	}

	public String toString(){
		return this.title + "(" + this.pubYear + ")";
	}

	public int compareTo(Book other){
		int r = this.pubYear.compareTo(other.pubYear);
		if(r == 0){
			return this.title.compareTo(other.title);
		} 
		return r;
	}
}


class BookByTitle implements Comparator<Book>{
	public int compare(Book one, Book two){
		return one.title.compareToIgnoreCase(two.title);
	}
}

class BookByYear implements Comparator<Book>{
	public int compare(Book one, Book two){
		return one.pubYear.compareTo(two.pubYear);
	}	
}

class lab{
	public static void main(String[] args) {
		List<Book> list = Arrays.asList(
			new Book("Mario",1997),
			new Book("Bros", 1887),
			new Book("jsusj", 87),
			new Book("me", 2003),
			new Book("annalisa", 2003)
		);

		System.out.println(list);
		
		Collections.sort(list);
		System.out.println(list);
		
		list.sort(new BookByTitle());
		System.out.println(list);

		list.sort(new BookByYear());
		System.out.println(list);
	}
}