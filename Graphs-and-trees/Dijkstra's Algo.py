import math

class Adjnode:
    def __init__(self, data, cost):  # constructor to set the data in a node and generate its branches
        self.vertex = data
        self.cost = cost
        self.next = None


class Graph:
    def __init__(self, vertices):  # constructor to set the total no. of nodes and create a graph of that many nodes
        self.V = vertices
        self.graph = [None] * self.V

    def add_edge(self, src, des, cost):  # adds edge to a node
        node = Adjnode(src, cost)  # creates an Adjnode with vertex(node value) as src
        node.next = self.graph[des]  # makes it point to the des node in the graph
        self.graph[des] = node  # the des nde in the graph contains the node

        node = Adjnode(des, cost)
        node.next = self.graph[src]
        self.graph[src] = node

    def print_graph(self):  # prints the graph, prints the nodes connected with the ith node
        for i in range(self.V):
            print("Adjacency list of {}\n head".format(i), end='')
            temp = self.graph[i]
            while temp:
                print("->{}".format(temp.vertex),f"({temp.cost})", end=' ')
                temp = temp.next
            print('\n')

    def printSolution(self, dist):
        print("Vertex \tDistance from Source")
        for node in range(self.V):
            print(node, "\t", dist[node])

    def minDist(self, dist, spt):
        min = math.inf

        for j in range(self.V):
            if dist[j] < min and spt[j] == False:
                min = dist[j]
                min_index = j

        return min_index

    def dijkstra(self, src):
        dist = [math.inf]*self.V
        dist[src] = 0
        spt = [False]*self.V

        for i in range(self.V):
            u = self.minDist(dist, spt)
            spt[u] = True

            temp = self.graph[u]
            while temp:
                if temp.cost > 0 and spt[temp.vertex] == False and dist[temp.vertex] > dist[u] + temp.cost:
                    dist[temp.vertex] = dist[u] + temp.cost
                temp = temp.next
        self.printSolution(dist)


g = Graph(9)
g.add_edge(0,1,4)
g.add_edge(0,7,8)
g.add_edge(1,2,8)
g.add_edge(1,7,11)
g.add_edge(2,3,7)
g.add_edge(2,5,4)
g.add_edge(2,8,2)
g.add_edge(3,4,9)
g.add_edge(3,5,14)
g.add_edge(4,5,10)
g.add_edge(5,6,2)
g.add_edge(6,7,1)
g.add_edge(7,8,7)
g.dijkstra(0)
#ST