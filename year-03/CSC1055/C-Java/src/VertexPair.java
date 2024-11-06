import java.util.Objects;

class VertexPair{ 
    private final Vertex v1;
    private final Vertex v2;

    public VertexPair(Vertex v1, Vertex v2){
        this.v1 = v1;
        this.v2 = v2;
    }

    public Vertex getV1() {
        return v1;
    }

    public Vertex getV2() {
        return v2;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;

        if(obj == null || !(obj instanceof VertexPair))
            return false;

        VertexPair other = (VertexPair) obj;

        return this.getV1().equals(other.getV1()) && this.getV2().equals(other.getV2());
    }

    @Override
    public int hashCode(){
        return Objects.hash(v1, v2);
    }

    @Override
    public String toString(){
        return "("+v1.toString()+","+v2.toString()+")";
    }
}
