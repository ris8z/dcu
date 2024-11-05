import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.util.Set;
import java.util.HashSet;

class WeightedGraph extends Graph{
    public Vertex addVertex(Integer value){
        Vertex v = new Vertex(value);

        if(graph.containsKey(v))
           return v;

        graph.put(v, new ArrayList<Arc>()); 
        vertexCount++;

        return v;
    }

    public Arc addArc(Integer start, Integer end, Integer cost){
        Vertex a = addVertex(start);
        Vertex b = addVertex(end);
        Arc result = new Arc(b, cost);

        graph.get(a).addLast(result);
        arcCount++;

        return result;
    }

    public Vertex deleteVertex(Integer value){
        Vertex target = new Vertex(value);

        if(isEmpty() || !graph.containsKey(target))
            return null;

        graph.remove(target);
        cleanArcs(target);
        vertexCount--;

        return target;
    }

    private void cleanArcs(Vertex target){
        for(Vertex v: graph.keySet()){
            Iterator<Arc> iter = graph.get(v).iterator(); 
            while(iter.hasNext()){
                Arc current = iter.next();
                if(current.getDestination().equals(target)){
                    iter.remove();
                    arcCount--;
                }
            }
        }
    }

    public Arc deleteArc(Integer start, Integer end, Integer time){
        Vertex a = new Vertex(start);
        Vertex b = new Vertex(end);

        if(isEmpty() || !graph.containsKey(a))
            return null;

        Arc target = new Arc(b, time);
        if(!graph.get(a).contains(target))
            return null;

        graph.get(a).remove(target);
        arcCount--;

        return target;
    }

    public boolean cyclic(){
        Set<Vertex> currentPath = new HashSet<>();  
        Set<Vertex> visited = new HashSet<>();

        for(Vertex v: graph.keySet()){
            if(dfs(v, currentPath, visited)) 
                return true;
        }
        return false;
    }

    private boolean dfs(Vertex current, Set<Vertex> path, Set<Vertex> visited){
        if(path.contains(current))
            return true;

        path.add(current);

        for(Arc arc: getNeighbors(current)){
            Vertex v = arc.getDestination();
            if(dfs(v, path, visited))
                return true;
        }
        
        path.remove(current);
        visited.add(current);

        return false;
    }
    public List<Vertex> shortesPath(){
        //assumption that we do not have negative number
        return null;
    }
    public String allShortestPahts(){return "";}

    public static void main(String[] args) {
        var mygraph = new WeightedGraph();
        System.out.println(mygraph);

        //from 1
        mygraph.addArc(1, 2, 10);
        mygraph.addArc(1, 4, 30);
        mygraph.addArc(1, 5, 100);
        //from 2
        mygraph.addArc(2, 3, 50);
        //from 3
        mygraph.addArc(3, 5, 10);
        //from 4
        mygraph.addArc(4, 3, 20);
        mygraph.addArc(4, 5, 60);
        //from 5 nothing

        System.out.println(mygraph);
        System.out.println(mygraph.cyclic());
        //let add a cycle
        mygraph.addArc(5, 4, 10);
        System.out.println(mygraph.cyclic());
    }
}
