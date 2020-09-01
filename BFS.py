class Adjnode:
    def __init__(self, data): #constructor to set the data in a node and generate its branches
        self.vertex = data
        self.next = None

class Graph:
    def __init__(self, vertices): #constructor to set the total no. of nodes and create a graph of that many nodes
        self.V = vertices
        self.graph = [None]*self.V

    def add_edge(self, src, des): #adds edge to a node
        node = Adjnode(src) #creates an Adjnode with vertex(node value) as src
        node.next = self.graph[des] #makes it point to the des node in the graph
        self.graph[des] = node #the des nde in the graph contains the node

        node = Adjnode(des)
        node.next = self.graph[src]
        self.graph[src] = node

    def print_graph(self): #prints the graph, prints the nodes connected with the ith node
        for i in range(self.V): 
            print("Adjacency list of {}\n head".format(i),end='')
            temp = self.graph[i]
            while temp:
                print("->{}".format(temp.vertex),end='')
                temp = temp.next
            print('\n')
    
    def BFS(self, v): 
        visited = [False]*self.V
        queue = []
        queue.append(v)
        visited[v] = True
        while queue:
            v = queue.pop(0)
            print(v, end=' ')
            temp = self.graph[v]
            while temp:
                if visited[temp.vertex] == False:
                    queue.append(temp.vertex)
                    visited[temp.vertex] = True
                temp = temp.next

graph = Graph(12)
graph.add_edge(0, 1)
graph.add_edge(0, 6)
graph.add_edge(0, 7)
graph.add_edge(1, 2)
graph.add_edge(1, 5)
graph.add_edge(2, 4)
graph.add_edge(2, 3)
graph.add_edge(7, 8)
graph.add_edge(7, 11)
graph.add_edge(8, 9)
graph.add_edge(8, 10)
#graph.print_graph()
print("\nPerforming BFS with root node 0")
graph.BFS(0)