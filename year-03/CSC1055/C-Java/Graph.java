import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

interface suitable{
    public boolean addVertex(Vertex vertex);
    public boolean addArc(Vertex start, Vertex end, Integer time);
    public Vertex deleteVertex(Vertex target);
    public Arc deleteArc(Arc target); 
    public boolean cyclic(); 
    public List<Vertex> shortestPath(Vertex start, Vertex end);
    public String allShortestPaths();
}

class Graph implements suitable{
    private HashMap<Vertex, List<Arc>> graph;

    Graph(){
        this.graph = new HashMap<Vertex, List<Arc>>();
    }

    @Override
    public String toString() {
        return this.graph.toString();
    }

    public boolean addVertex(Vertex vertex){
        if(this.graph.containsKey(vertex))
            return false;

        this.graph.put(vertex, new ArrayList<Arc>());
        return false;
    }

    public boolean addArc(Vertex start, Vertex end, Integer time){
        if(this.graph.containsKey(start))
            return false;

        this.graph.get(start).addLast(new Arc(end, time));
        return true;
    }

    public Vertex deleteVertex(Vertex target){
        return null;
    }

    public Arc deleteArc(Arc target){
        return null;
    } 

    public boolean cyclic(){
        return true;
    } 

    public List<Vertex> shortestPath(Vertex start, Vertex end){
        return null;
    }

    public String allShortestPaths(){
        return null;
    }

    public static void main(String[] args) {
        var v1 = new Vertex(1); 
        var v2 = new Vertex(2);
        var mygraph = new Graph();
        System.out.println(mygraph);
        mygraph.addVertex(v1);
        mygraph.addVertex(v2);
        mygraph.addArc(v1, v2, 10);
        System.out.println(mygraph);
    }
}
