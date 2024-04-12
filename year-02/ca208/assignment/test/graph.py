import sys

class Vertex:
    def __init__(self, name):
        self.id = name
        self.adj = {}
    
    def __str__(self):
        result = str(self.id)
        result += " adjacent: "
        result += str([(x.id, self.get_dist(x), self.get_ways(x)) for x in self.adj])
        return result
    
    def add_neighbor(self, neighbor, dist, ways):
        self.adj[neighbor] = (dist, ways)

    def get_connections(self):
        return self.adj.keys()

    def get_id(self):
        return self.id

    def get_dist(self, neighbor):
        return self.adj[neighbor][0]

    def get_ways(self, neighbor):
        return self.adj[neighbor][1]

class Graph:
    def __init__(self):
        self.d = {}
        self.nV = 0

    def addVertex(self, name):
        if name in self.d:
            return None
        self.nV += 1
        self.d[name] = Vertex(name)

    def add_edge(self, From, To, dist, ways):
        if From not in self.d:
            self.addVertex(From)
        if To not in self.d:
            self.addVertex(To)
        self.d[From].add_neighbor(self.d[To], dist, ways)

    def dfs(self, name):
        startV = self.d[name]
        visited = []

        self.recDfs(startV, visited)
        print(name)
        for v in visited:
            print(v.id)
    
    def recDfs(self, node, visited):
        visited.append(node)

        for neighbor in node.get_connections():
            if neighbor not in visited:
                self.recDfs(neighbor, visited)
    
    def getBestSpeed(self, string):
        buffer = []
        if 'f' in string:
            buffer.append(5)
        if 'c' in string:
            buffer.append(80)
        if 't' in string:
            buffer.append(100)
        if 'p' in string:
            buffer.append(500)
        return max(buffer)

    # v = s/t --> t = s/v        
    def allpath(self, From, to):
        start = self.d[From]
        target = self.d[to]

        paths = []
        def getPaths(Node, visited, mypath, time):
            mypath.append(Node)
            visited.append(Node)

            if Node == target:
                tmp = mypath.copy()
                paths.append(tmp + [time])
                return

            for neighbor in Node.get_connections():
                if neighbor not in visited:
                    s = Node.get_dist(neighbor)
                    v = self.getBestSpeed(Node.get_ways(neighbor))
                    t = s / v

                    getPaths(neighbor, visited, mypath, time + t)
                    mypath.pop()
                    visited.pop()
        getPaths(start, [], [], 0)

        for p in paths:
            point = []
            for v in p:
                if type(v) is float:
                    point.append(str(v))
                else:
                    point.append(v.id)
            print("->".join(point))
                


def main():
    G = Graph()
    for line in sys.stdin:
        tokens = line.split()
        G.add_edge(tokens[0], tokens[1], int(tokens[2]), tokens[3])

    G.allpath("dublin", "rome")
    G.allpath("dublin", "cork")

if __name__ == "__main__":
    main()
