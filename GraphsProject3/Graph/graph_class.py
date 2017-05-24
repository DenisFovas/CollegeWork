from Graph.vertece import Vertex


class DirectedGraph:
    def __init__(self):
        self.__vertices = []
        self.__numberOfVertices = 0
        self.__numberOfEdges = 0

    '''Will read the file and set all the edges that are connected in the file
     Input:
        string - the path to the file
    '''
    def readVertices(self, fileToRead):
        # Open the file to read
        file = open(fileToRead, "r")
        # Get the number of vertices and of the edges
        numbers = file.readline()
        # Separate them into a list
        numbers = numbers.strip(" ").split()
        # Set them into their positions
        self.__numberOfVertices = int(numbers[0])
        self.__numberOfEdges = int(numbers[1])
        # Set them to an empty list
        for i in range(self.__numberOfVertices):
            self.__vertices.append(Vertex())
        # Set the edges, for all vertices in the file
        for i in range(self.__numberOfEdges):
            tmp = file.readline()
            tmp = tmp.strip(" ").split()
            # We add a edge, and we create it on the place using the constructor
            self.__vertices[int(tmp[0])].addEdge(tmp[1], tmp[2])
            # We increase the in degree of that vertex
            self.__vertices[int(tmp[1])].increaseInDegree()
            self.__vertices[int(tmp[1])].addInboundEdge(int(tmp[0]))
        file.close()

    '''Will return the number of vertices in the graph'''
    def getNumberOfVertices(self):
        return self.__numberOfVertices

    '''Will check if there exists a connection from x to y
    Input:
        x - edge starting point (integer)
        y - edge end point (integer)
    Output:
        -1 - if the x/y is not a valid start point/end point
        1 - if exists a connection between x and y
    '''
    def checkIfEdge(self, x, y):
        if x >= self.__numberOfVertices:
            return -1
        # Will get a list of integers, representing the vertices to which x has a connection
        edges = self.__vertices[x].getEdges()
        for i in range(len(edges)):
            if edges[i].getEndPoint() == y:
                # We did found a connection. We return 1
                return 1
        # We did not found a connection. We return -1
        return -1

    '''Returns the out degree of a vertex (the number of edges that start from point i)
    Input:
        i - the starting point
    Return:
        -1 - if i is not valid
        length of the vertex i'''
    def getOutDegree(self, i):
        if i > self.__numberOfVertices:
            return -1
        return self.__vertices[i].getOutDegree()

    '''Returns the in degree of a vertex (the number of edges that end in point i
    Input:
        i - the end point
    Return:
        -1 - if the end point is not valid
        the number of vertices that go to i'''
    def getInDegree(self, i):
        if i > self.__numberOfVertices:
            return -1
        return self.__vertices[i].getInDegree()

    '''Will go to each position of the given argument, vertexPosition, and will yield it
    Input:
        vertexPosition - the position for which we try to iterate
    Return:
        None - if the position is invalid
        edge.getEndPoint - for each endPoint, it will yield the point, then will resume at the exact same position'''
    def iterateThroughOutboundVertex(self, vertexPosition):
        if vertexPosition > self.__numberOfVertices:
            return None
        vertex = self.__vertices[vertexPosition]
        for edge in vertex.getEdges():
            yield edge.getEndPoint()
    '''Will go to each position of the given argument, vertexPosition, and will yield it
    Input:
        vertexPosition - the position for which we try to iterate
    Return:
        None - if the position is invalid
        edge.getEndPoint - for each endPoint, it will yield the point, then will resume at the exact same position'''
    def iterateThroughInboundVertex(self, vertexPosition):
        if vertexPosition > self.__numberOfVertices:
            return None
        inboundVertex = self.__vertices[vertexPosition].getInboundEdge()
        for vertex in inboundVertex:
            yield vertex
    '''Will edit the cost from vertex corresponding to positionX and positionY
    Input:
        positionX - the position which we start
        positionY - the position which we end
        newCost - the new cost
    Return:
        None - if the positions are invalid
        1 - if the positions are valid'''
    def editCost(self, positionX, positionY, newCost):
        if positionX > self.__numberOfVertices or positionY > self.__numberOfVertices:
            return None
        if self.checkIfEdge(positionX, positionY) == 1:
            edges = self.__vertices[positionX].getEdges()
            edges[positionY].setCost(newCost)
            return 1
        return None

    '''Will get the cost of the vertex form positionX to positionY
    Input:
        positionX - the starting point of the vertex
        positionY - the ending point of the vertex
    Return:
        None - if the positions are invalid
        the cost of the edge'''
    def getCost(self, positionX, positionY):
        if positionX > self.__numberOfVertices or \
                        positionY > self.__numberOfVertices:
            return None
        if self.checkIfEdge(positionX, positionY) == 1:
            # WIll take all the connections from point x.
            edges = self.__vertices[positionX].getEdges()
            # returns the cost from x to y
            for edge in edges:
                if edge.getEndPoint() == positionY:
                    return edge.getCost()

'''Computes the BFS for 2 verteces.
Input:
    startingVertex - the starting point of the vertex
    enndingVertex - the ending point of the vertex
    graph - the directed graph on which we will do the search
Return:
    a list in which we have the traversal of the graph'''
# Problem 1
def BFSsearch(graph, startingVertex, endingVertex):
    # We set an array in which we have the value False for every vertex. It
    # will be an array to check if the vertex was visited.
    visited = [False]*(graph.getNumberOfVertices())
    visitedCheck = [True]*(graph.getNumberOfVertices())
    # Queue list for the bfs algorithm
    queue = []
    # For the predecesor
    pred = {}
    # Alghorithm:
    queue.append(startingVertex)
    visited[startingVertex] = True
    # We make the initiali value for the starting point of the search
    pred[startingVertex] = -1
    current  = startingVertex
    while (visited != visitedCheck) and (current != endingVertex) and \
        (queue != []):
        # We get first element of the queue
        current = queue.pop(0)
        # We iterate trough each Out bound edge
        for vertex in graph.iterateThroughOutboundVertex(current):
            # If they are not visited then we continue. Otherwise we go trough
            # the next element
            if visited[vertex] is False:
                # We mark the current vertex as visited.
                visited[vertex] = True
                # We add it as a key to the pred vector to can remmenber which
                # node was before the curent node.
                pred[vertex] = current
                # We add it to the queue, so that we can manage to contiue the
                # algorithm with the verteces that are connected.
                queue.append(vertex)
    # We set the current vertex as the destination vertex, so that we can go
    # trough each element from the predecesor elements.
    current = endingVertex
    # we make a list of the path, which will have the "best path"
    path = []
    # While we are not at the starting poing, we add the elements trough the
    # path. Then we set the curent element as the last element inserted.
    if not endingVertex in pred:
        return None
    while pred[current] != -1:
        path.append(current)
        current = pred[current]
    # We didn't had the first element inserted, so we add it to the path.
    path.append(startingVertex)
    # We reverse it, so we have a forward algorithm
    path.reverse()
    return path

#Write a program that, given a graph with positive costs and two vertices, finds
# a lowest cost walk between the given vertices, using the Dijkstra algorithm.

def Dijkstra(graph, startingVertex):
    # Array to store distances. Each index will store the shortes path from
    # starting vertex to the index vertex
    distance = {}
    # Initiate the distance for starting vertex
    distance[startingVertex] = 0
    # Queue to get the order in which we store the values
    queue = []
    # List to check the number of visited vertices
    visited = {}
    visited[startingVertex] = startingVertex

    prev = {}
    # We initiate the distances
    for vertex in range(graph.getNumberOfVertices()):
        # If we are not in the starting vertex, we initiate the distances
        if vertex != startingVertex:
            # With this we mark that we don't have a distance calculated yet.
            distance[vertex] = 10000000000000

    # While we still have vertexes, we continue
    queue.append(startingVertex)
    while queue != []:
        # We get the current element
        current = queue.pop(0)
        # For each vertex we will compute the cost
        for vertex in graph.iterateThroughOutboundVertex(current):
            # We have it already in the graph
            if not (vertex in visited) or distance[vertex] > distance[current] + graph.getCost(current, vertex):
                distance[vertex] = distance[current] + graph.getCost(current, vertex)
                visited[vertex] = vertex
                queue.append(vertex)
                prev[vertex] = current

    for i in range(graph.getNumberOfVertices()):
        if distance[i] == 10000000000000:
            distance[i] = None
    print(distance)
    return (distance, prev)

def DijkstraPth(graph, startingVertex, endingVertex):
    distance, previous = Dijkstra(graph, startingVertex)
    path = []
    if not endingVertex in previous:
        return None
    else:
        vertex = previous[endingVertex]
        path.append(endingVertex)
        path.append(vertex)
        # path.append(startingVertex)
        while vertex != startingVertex:
            vertex = previous[vertex]
            path.append(vertex)

    path.reverse()
    return (distance[endingVertex], path)


