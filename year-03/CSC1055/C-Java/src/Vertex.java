public class Vertex{
    private Integer value;

    Vertex(Integer value){
        this.value = value;
    }

    public Integer getValue(){
        return this.value;
    }

    public void setValue(Integer value){
        this.value = value;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;

        if(obj == null || !(obj instanceof Vertex))
            return false;

        Vertex other = (Vertex) obj;

        return this.getValue().equals(other.getValue());
    }

    @Override
    public int hashCode(){
        return (int) this.value;
    }

    @Override
    public String toString(){
        return this.value.toString();
    }
}
