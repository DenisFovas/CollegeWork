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
        if positionX > self.__numberOfVertices or positionY > self.__numberOfVertices:
            return None
        if self.checkIfEdge(positionX, positionY) == 1:
            edges = self.__vertices[positionX].getEdges()
            return edges[positionY].getCost()
