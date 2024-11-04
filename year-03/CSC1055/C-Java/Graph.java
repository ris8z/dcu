import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

interface suitable{
    public boolean addVertex(Vertex vertex);
    public boolean addArc(Vertex start, Vertex end, Integer time);
    public boolean deleteVertex(Vertex target);
    public boolean deleteArc(Vertex start, Vertex end, Integer time); 
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
        return true;
    }

    public boolean addArc(Vertex start, Vertex end, Integer time){
        if(!this.graph.containsKey(start))
            return false;

        this.graph.get(start).addLast(new Arc(end, time));
        return true;
    }

    public boolean deleteVertex(Vertex target){
        //remove target from the map
        if(!this.graph.containsKey(target))
            return false;
        this.graph.remove(target);

        //remove all the arc that has target as destianation
        for(Vertex start: this.graph.keySet()){
            Iterator<Arc> iteretor = this.graph.get(start).iterator();
            while(iteretor.hasNext()){
                Arc arc = iteretor.next(); 
                if(arc.getDestination().equals(target)){
                    iteretor.remove();
                }
            }
        }
        return true;
    }

    public boolean deleteArc(Vertex start, Vertex end, Integer time){
        if(!this.graph.containsKey(start))
            return false;

        Arc target = new Arc(end, time);

        if(!this.graph.get(start).contains(target))
            return false;

        this.graph.get(start).remove(target);
        return true;
    } 

    public boolean cyclic(){
        Set<Vertex> visited = new HashSet<Vertex>();
        List<Vertex> currentPath = new LinkedList<Vertex>();

        for(Vertex v: this.graph.keySet()){
            if(!visited.contains(v) && this.dfs(v, currentPath, visited))
                return true;
        } 

        return false;
    } 

    private boolean dfs(Vertex current, List<Vertex> path, Set<Vertex> visited){
        if(path.contains(current))
            return true;
        
        path.addLast(current);

        for(Arc arc: this.graph.get(current)){
            Vertex next = arc.getDestination();
            if(this.dfs(next, path, visited))
                return true;
        }

        path.removeLast();
        visited.add(current);//we know that from this node do not start a cylce

        return false;
    }

    public List<Vertex> shortestPath(Vertex start, Vertex end){
        return null;
    }

    public String allShortestPaths(){
        return null;
    }

    public static void main(String[] args) {
        var mygraph = new Graph();
        var v1 = new Vertex(1); 
        var v2 = new Vertex(2);
        var v3 = new Vertex(3);
        var v4 = new Vertex(4);
        var v5 = new Vertex(5);

        mygraph.addVertex(v1);
        mygraph.addVertex(v2);
        mygraph.addVertex(v3);
        mygraph.addVertex(v4);
        mygraph.addVertex(v5);

        //from 1
        mygraph.addArc(v1, v2, 10);
        mygraph.addArc(v1, v4, 30);
        mygraph.addArc(v1, v5, 100);
        //from 2
        mygraph.addArc(v2, v3, 50);
        //from 3
        mygraph.addArc(v3, v5, 10);
        //from 4
        mygraph.addArc(v4, v3, 20);
        mygraph.addArc(v4, v5, 60);
        //from 5 nothing
        
        System.out.println(mygraph);
        System.out.println(mygraph.cyclic());
        //add a cyle
        mygraph.addArc(v5, v4, 5);
        System.out.println(mygraph.cyclic());

        }
}
