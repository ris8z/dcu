import java.util.*;

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

    private void promptMessage(Integer start, Integer end, List<Vertex> result){
        String output;
        if(result == null){
            output = "(" + start + "," + end + ") : No paths";
        }else{
            output = "(" + start + "," + end + ") : " + result; 
        }
        System.out.println(output);
    }

    public List<Vertex> shortesPath(Integer start, Integer end){
        Dijkstra dij = new Dijkstra(this, new Vertex(start));
        List<Vertex> result = dij.getPathTo(new Vertex(end));
        promptMessage(start, end, result);
        return result;
    }

    public Map<VertexPair, List<Vertex>> allShortestPahts(){
        Map<VertexPair, List<Vertex>> result = new HashMap<>();

        for(Vertex i: getAllVertexs()){
            Dijkstra dij = new Dijkstra(this, i);
            for(Vertex j: getAllVertexs()){
                if(i.equals(j))
                    continue;
                List<Vertex> lst = dij.getPathTo(j);
                result.put(new VertexPair(i,j), lst);
                promptMessage(i.getValue(), j.getValue(), lst);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        var mygraph = new WeightedGraph();

        mygraph.addArc(1, 2, 10);
        mygraph.addArc(1, 4, 30);
        mygraph.addArc(1, 5, 100);
        mygraph.addArc(2, 3, 50);
        mygraph.addArc(3, 5, 10);
        mygraph.addArc(4, 3, 20);
        mygraph.addArc(4, 5, 60);

        System.out.println(mygraph);
        
        System.out.println(mygraph.cyclic());

        mygraph.allShortestPahts();
    }
}
