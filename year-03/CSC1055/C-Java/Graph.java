import java.util.*;

public abstract class Graph{
    protected Map<Vertex, List<Arc>> graph = new HashMap<>();
    protected int vertexCount = 0;
    protected int arcCount = 0;
    
    //abstarct methods to develop in the subclass
    public abstract Vertex addVertex(Integer value);
    public abstract Arc addArc(Integer start, Integer end, Integer cost);
    public abstract Vertex deleteVertex(Integer value);
    public abstract Arc deleteArc(Integer start, Integer end, Integer time);
    public abstract boolean cyclic();
    public abstract List<Vertex> shortesPath();
    public abstract String allShortestPahts();

    //actual methods
    public int getVertexCount(){
        return vertexCount;
    }

    public int getArcCount(){
        return arcCount;
    }

    public boolean isEmpty(){
        return vertexCount == 0;
    }

    public List<Arc> getNeighbors(Vertex v){
        return graph.getOrDefault(v, new ArrayList<Arc>());
    }

    @Override
    public String toString() {
        return graph.toString();
    }
} 
