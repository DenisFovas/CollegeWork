class Edge:
    def __init__(self, destination, cost):
        self.__cost = int(cost)
        self.__destination = int(destination)

    def setCost(self, newCost):
        self.__cost = newCost

    def getCost(self):
        return self.__cost

    def getEndPoint(self):
        return self.__destination
