/**
 * Book.java - Assignment 01
 * @author Harshvardhan Pandit
 */

enum BookMedium {
    PhysicalBook, EBook, AudioBook;
}

enum BookGenre {
    Fiction, NonFiction
}

enum BookRating {
    Rating1(1), Rating2(2), Rating3(3), Rating4(4), Rating5(5);

    private final int value;
    BookRating(int value) { this.value = value; }

    public int numberValue(){
        return this.value;
    }
}

class Book {
    // fields are private
    private String title = "";
    private String author = "";
    private int publishedDate = 0;
    private int readDate = 0;
    private BookMedium medium = null;
    private BookGenre genre = null;
    private BookRating rating = null;

    /**
     * Default constructor takes title, author, and genre
     */
    public Book(String title, String author, BookGenre genre){
        setTitle(title);
        setAuthor(author);
        setBookGenre(genre);
    }

    /**
     * Additional constructor also takes published date
     */
    public Book(String title, String author, BookGenre genre, int publishedDate){
        setTitle(title);
        setAuthor(author);
        setPublishedDate(publishedDate);
        setBookGenre(genre);
    }

    /**
     * Additional constructor also takes published date,
     * read date, read medium, and rating
     */
    public Book(String title, String author, BookGenre genre, int publishedDate, int readDate, BookMedium medium,  BookRating rating){

        setTitle(title);
        setAuthor(author);
        setPublishedDate(publishedDate);
        setReadDate(readDate);
        setBookMedium(medium);
        setBookGenre(genre);
        setBookRating(rating);
    }

    // getters <---------------------------------------
    public String getTitle(){
        return this.title;
    }

    public String getAuthor(){
        return this.author;
    }

    public int getPublishedDate(){
        return this.publishedDate;
    }

    public int getReadDate(){
        return this.readDate;
    }

    public BookMedium getMedium(){
        return this.medium;
    }

    public BookGenre getGenre(){
        return this.genre;
    }

    public BookRating getRating(){
        return this.rating;
    }

    // setters <---------------------------------------
    public void setTitle(String title){
        this.title = title;
    }

    public void setAuthor(String author){
        this.author = author;
    }

    public void setPublishedDate(int publishedDate){
        this.publishedDate = publishedDate;
    }

    public void setReadDate(int readDate){
        this.readDate = readDate;
    }

    public void setBookMedium(BookMedium medium){
        this.medium = medium;
    }

    public void setBookGenre(BookGenre genre){
        this.genre = genre;
    }

    public void setBookRating(BookRating rating){
        this.rating = rating;
    }

    /**
     * toString implementation
     * Depends on available information
     * For title, an author, and a genre - Title by Author
     * If publication date is present - Title by Author (Year of Publication)
     * If read date, read medium, and rating is present -
     * Title by Author (Year of Publication) - read in Year of Reading, rated rating/5
     */

    public String toString(){
        String output = "";

        if(this.title != ""){
            output = output + this.title;
        }

        if(this.author != ""){
            output = output + " by " + this.author;
        }

        if(this.publishedDate != 0){
            output = output + " (" + this.publishedDate + ")";
        }

        if(this.readDate != 0){
            output = output + " - read in " + this.readDate + ",";
        }
        
        if(this.rating != null){
            output = output + " rated " + this.rating.numberValue() + "/5";
        }

        return output;
    }

    public static void main(String[] args) {
    }
}