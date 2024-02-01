/*interface Order {
    public boolean lessThan(Order other);
}

interface Comparable extends Order{
    public int compareTo(Object obj);
}*/

public class Point implements Comparable{
    private double x, y;

    public Point(double newX, double newY) {
        x = newX;
        y = newY;
    }
//<-------------------------------------------------getters
    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

//<-------------------------------------------------local function
    public String toString(){
        return "(" + x + ", " + y + ")";
    }

    public boolean lessThan(Point other){
        if(this.x == other.x){
            return this.y < other.y;
        }
        return this.x < other.x;
    }


    public boolean equals(Point other){
        if(this.x == other.x && this.y == other.y){
            return true;
        }
        return false;
    }
//<-------------------------------------------------interfaces functions
    public boolean lessThan(Order other){
        if(!(other instanceof Point)){
            return false;
        }
        Point ot = (Point) other;
        
        return lessThan(ot);
    }

    public int compareTo(Object obj){
        if(!(obj instanceof Point)){
            return 10;
        }
        Point ot = (Point) obj;
        
        if(equals(ot)){
            return 0;
        }

        if(lessThan(ot)){
            return -1;
        }

        return 1;
    }
//<-------------------------------------------------main
    public static void main(String[] argv){
        Order O1 = new Point(0, 0);
        Order O2 = new Point(1, 1);
        Order O3 = new Point(0, 1);
    
        System.out.println("O1 less than O2: " + O1.lessThan(O2)); // true
        System.out.println("O1 less than O3: " + O1.lessThan(O3)); // true
        System.out.println("O2 less than O3: " + O2.lessThan(O3)); // false
        System.out.println("O3 less than O3: " + O3.lessThan(O3)); // false

        Comparable P1 = new Point(0, 0);
        Comparable P2 = new Point(1, 1);
        Comparable P3 = new Point(0, 1);

        System.out.println("P1 less than P2: " + P1.compareTo(P2)); // -1
        System.out.println("P1 less than P3: " + P1.compareTo(P3)); // -1
        System.out.println("P2 less than P3: " + P2.compareTo(P3)); // 1
        System.out.println("P3 less than P3: " + P3.compareTo(P3)); // 0

        Point p_1 = new Point(1,2);
        System.out.println(p_1.getX() + p_1.getY()); // 3.0

    }
}
