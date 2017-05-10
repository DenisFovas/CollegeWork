from Graph.graph_class import BFSsearch

class Console:
    def __init__(self, graph, file):
        self.__graph = graph
        self.__file = file

    def printMenu(self):
        print("==========================")
        print("1. Print the number of vertices")
        print("2. Check if it exists an edge")
        print("3. Print the in degree of a vertex")
        print("4. Print the out degree of a vertex")
        print("5. Get cost of a edge")
        print("6. Get in bound edges")
        print("7. Get out bound edges")
        print("8. BFS on 2 points")
        print("0. Exit the program")

    def getUserInput(self):
        userInput = int(input("Please insert a number: "))
        if userInput == "":
            return -100
        return userInput


    def run(self):
        self.__graph.readVertices(self.__file)
        print("The file was loaded with success!")
        while True:
            self.printMenu()
            userInput = self.getUserInput()
            if userInput == 1:
                a = self.__graph.getNumberOfVertices()
                print("The number of vertices is: ", a)
            elif userInput == 2:
                print("First vertex:")
                firstNumber = self.getUserInput()
                print("Second vertex:")
                secondNumber = self.getUserInput()
                a = self.__graph.checkIfEdge(firstNumber, secondNumber)
                if a == 1:
                    print("There exist a connection")
                else:
                    print("There is no connection")
            elif userInput == 3:
                print("Insert the vertex")
                userInput = self.getUserInput()
                a = self.__graph.getInDegree(userInput)
                if a != -1:
                    print("The in degree is: ", a)
                else:
                    print("Invalid number")
            elif userInput == 4:
                print("Insert the vertex:")
                userInput = self.getUserInput()
                a = self.__graph.getOutDegree(userInput)
                if a != -1:
                    print("The out degree is: ", a)
                else:
                    print("Invalid number")
            elif userInput == 5:
                print("Insert the first vertex:")
                x = self.getUserInput()
                print("Insert the second vertex: ")
                y = self.getUserInput()
                a = self.__graph.getCost(x, y)
                print("The cost is: ", a)
            elif userInput == 6:
                print("Insert the vertex number:")
                userInput = self.getUserInput()
                a = self.__graph.iterateThroughInboundVertex(userInput)
                print("We have the in bounded vertices:")
                for vertex in a:
                    print("\t", vertex)
            elif userInput == 7:
                print("Please insert the vertex number: ")
                userInput = self.getUserInput()
                a = self.__graph.iterateThroughOutboundVertex(userInput)
                print("We have the out bounded vertices: ")
                for vertex in a:
                    print("\t", vertex)
            elif userInput == 8:
                print("Please insert the starting vertex:")
                firstVertex = self.getUserInput()
                print("Please insert the ending vertex:")
                secondVertex = self.getUserInput()
                path = BFSsearch(self.__graph, firstVertex, secondVertex)

                if path is None:
                    print("We didn't had any connections with these verteces.")
                else:
                    print(path)
            elif userInput == 0:
                return None
            else:
                print("Invalid number.")
