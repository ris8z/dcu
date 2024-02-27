interface Order{
	public boolean lessThan(Order other);
	public boolean equal(Order other);
}

class Comparator <Thing extends Order>{
	public Thing getLesser(Thing a, Thing b){
		if( ((Order) a).equal((Order) b) ){
			return null;
		}

		if( ((Order) a).lessThan((Order) b) ){
			return a;
		}

		return b;
	} 
}

class Point implements Order{
	private double x;
	private double y;

	Point(double x, double y){
		this.x = x;
		this.y = y;
	}

	public double getX(){
		return this.x;
	}

	public double getY(){
		return this.y;
	}

	public String toString(){
		return "(" + x + " " + y + ")";
	}

	public boolean lessThan(Point p){
		if(this.getX() == p.getX()){
			return this.getY() < p.getY();
		}

		return this.getX() < p.getX();		
	}

	public boolean lessThan(Order other){
		if(!(other instanceof Order)){
			return false;
		}
		return lessThan((Point) other);
	}

	public boolean equal(Point p){
		return this.getX() == p.getX() && this.getY() == p.getY();
	}

	public boolean equal(Order other){
		if(!(other instanceof Order)){
			return false;
		}

		return equal((Point) other);
	}

	public static void main(String[] args) {
		// Assuming your class is called Comparator
		Comparator<Point> C = new Comparator<>();

		Point P1 = new Point(0, 0);
		Point P2 = new Point(1, 1);

		System.out.println(C.getLesser(P1, P2)); // (0.0, 0.0)
		System.out.println(C.getLesser(P2, P1)); // (0.0, 0.0)
		System.out.println(C.getLesser(P1, P1)); // null
	}
}