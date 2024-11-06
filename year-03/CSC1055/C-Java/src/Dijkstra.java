import java.util.*;

class Dijkstra{

    Map<Vertex, Integer> time;
    Map<Vertex, Vertex> predecessor;
    Graph graph;
    Vertex start;

    Dijkstra(Graph graph, Vertex start){
        time = new HashMap<Vertex, Integer>();
        predecessor = new HashMap<Vertex, Vertex>();
        this.graph = graph;
        this.start = start;
        this.run();
    }

    public void run(){
        
        for(Vertex v: graph.getAllVertexs()){
            time.put(v, Integer.MAX_VALUE);
        }
        time.put(start, 0);

        PriorityQueue<Arc> minHeap = new PriorityQueue<Arc>();
        minHeap.add(new Arc(start, 0));

        while(!minHeap.isEmpty()){
            Arc arc = minHeap.poll();
            Vertex currentVertex = arc.getDestination();
            Integer currentTime = arc.getTime();

            if(currentTime > time.get(currentVertex))
                continue;

            for(Arc neighbourArc: graph.getNeighbors(currentVertex)){
                Vertex neighbour = neighbourArc.getDestination();
                Integer newTime = neighbourArc.getTime() + currentTime;

                if(newTime < time.get(neighbour)){
                    time.put(neighbour, newTime);                    
                    predecessor.put(neighbour, currentVertex);
                    minHeap.add(new Arc(neighbour, newTime));
                }
            }
        }
        //System.out.println(time);
        //System.out.println(predecessor);
    }

    public List<Vertex> getPathTo(Vertex end){
        List<Vertex> path = new LinkedList<>();
        Vertex lastV = new Vertex(-1);
        for(Vertex v=end; v!=null; v=predecessor.getOrDefault(v, null)){
            path.add(0, v);
            lastV = v;
        }

        if(lastV.equals(start))
            return path;
        return null;
    }
}
