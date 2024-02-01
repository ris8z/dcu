class Point implements GridQuadrant, CompareQuadrant{
    private double x, y;
    
    public Point(double x, double y) {
        setX(x);
        setY(y);
    }


    public double getX() {
        return this.x;
    }
    public double getY() {
        return this.y;
    }

    public void setX(double x){
        this.x = x;
    }
    public void setY(double y){
        this.y = y;
    }


    public String toString(){
        return "(" + x + ", " + y + ")";
    }


    public Quadrant getQuadrant(){
        if(this.x == 0 && this.y == 0){
            return null;
        }
        if(this.x > 0 && this.y > 0){
            return Quadrant.Q1;
        }else if(this.x > 0 && this.y < 0){
            return Quadrant.Q4;
        }else if(this.x < 0 && this.y > 0){
            return Quadrant.Q2;
        }else{
            return Quadrant.Q3;
        }
    }

    public boolean isInSameQuadrant(Point other){
        return this.getQuadrant() == other.getQuadrant();
    }
}

enum Quadrant {
    Q1, // x +ve, y +ve
    Q2, // x -ve, y +ve
    Q3, // x -ve, y -ve
    Q4; // x +ve, y -ve
}

interface GridQuadrant {
    Quadrant getQuadrant(); // return which quadrant the point is in
                            // if point is at (0,0) return null
}

interface CompareQuadrant {
    boolean isInSameQuadrant(Point other); // true if given point is
                                     // in the same quadrant as this point
}

interface PointMaker {
    Point makePoint(double x, double y); // returns point with given x,y
    int countPointsCreated(); // returns count of points created via factory
}

public class PointFactory implements PointMaker{

    private static int counter = 0;

    public Point makePoint(double x, double y){
        counter += 1;
        return new Point(x, y);
    }
    public int countPointsCreated(){
        return counter;
    }

    public static void main(String[] argv){
    //Point(1,1) gives Quadrant Q1, Point(-1,1) gives Q2, and so on
    Point p1 = new Point(1, 1);//Q1
    Point p2 = new Point(-1, 1);//Q2
    Point p3 = new Point(-1, -1);//Q3
    Point p4 = new Point(1, -1);//Q4

    System.out.println(p1.getQuadrant() == Quadrant.Q1);
    System.out.println(p2.getQuadrant() == Quadrant.Q2);
    System.out.println(p3.getQuadrant() == Quadrant.Q3);
    System.out.println(p4.getQuadrant() == Quadrant.Q4);


    //Point(1,1) is in the same quadrant as Point(2,2) but not as Point(-1,-1)
    Point p5 = new Point(1, 1);//Q1
    Point p6 = new Point(2, 2);//Q1
    Point p7 = new Point(-1, -1);//Q1

    System.out.println(p5.isInSameQuadrant(p6) == true);
    System.out.println(p5.isInSameQuadrant(p7) == false);


    //Point(1,1) gives the same X and Y values as PointFactory’s makePoint(1,1)
    PointMaker pm = new PointFactory();
    Point p8 = new Point(1,1);
    Point p9 = pm.makePoint(1,1);

    System.out.println(p8.getX() == p9.getX());
    System.out.println(p8.getY() == p9.getY());
    

    //Total number of Point instances created via PointFactory’s makePoint is correct
    Point p10 = pm.makePoint(1,1);
    Point p11 = pm.makePoint(1,1);

    System.out.println(pm.countPointsCreated() == 3);
    }
}
