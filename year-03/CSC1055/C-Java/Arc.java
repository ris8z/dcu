public class Arc{
    Vertex destination;
    Integer time;

    Arc(Vertex destination, Integer time){
        this.destination = destination;
        this.time = time;
    }    

    Arc(Vertex destination){
        this.destination = destination;
        this.time = 0;
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
    public boolean equals(Object obj) {
        if(this == obj)
            return true;

        if(obj == null || !(obj instanceof Arc))
            return false;

        Arc other = (Arc) obj;

        if(!this.getDestination().equals(other.getDestination()))
            return false;

        return this.getTime().equals(other.getTime());
    }

    @Override
    public String toString() {
        return "(" +this.destination.toString() + "," + this.time.toString() + ")";
    }
}
