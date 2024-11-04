public class Arc{
    Vertex destination;
    Integer time;

    Arc(Vertex destination, Integer time){
        this.destination = destination;
        this.time = time;
    }    

    public Vertex getDestination() {
        return this.destination;
    }

    public Integer getTime() {
        return this.time;
    }

    public void setTime(Integer time) {
        this.time = time;
    }

    public void setDestination(Vertex destination) {
        this.destination = destination;
    }

    @Override
    public String toString() {
        return "(" +this.destination.toString() + "," + this.time.toString() + ")";
    }
}
