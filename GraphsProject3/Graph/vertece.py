from Graph.Edge import Edge


class Vertex:
    def __init__(self):
        # A list of edges
        self.__edges = []
        # A list of the inbound edges, those who are in this Vertex
        self.__inboundEdge = []
        # The number of out degree of the vertex
        self.__outDegree = 0
        # The number of in degree of the vertex
        self.__inDegree = 0

    '''Add an edge to the vertex
    Input:
        edgeDestination - the "id" of the edge, or the number which represents it
        edgecost - the cost of that edge'''
    def addEdge(self, edgeDestination, edgecost):
        e = Edge(edgeDestination, edgecost)
        self.__edges.append(e)
        self.__outDegree += 1

    '''Increase the in degree of the vertex'''
    def increaseInDegree(self):
        self.__inDegree += 1

    '''Will add the in bound vertices
    Input:
        incomeEdgePoint - the vertex from which the edge started'''
    def addInboundEdge(self, incomeEdgePoint):
        self.__inboundEdge.append(incomeEdgePoint)

    def getEdges(self):
        return self.__edges
    def getOutDegree(self):
        return self.__outDegree
    def getInDegree(self):
        return self.__inDegree
    def getInboundEdge(self):
        return self.__inboundEdge
