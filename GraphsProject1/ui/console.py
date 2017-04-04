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
        print("0. Exit the program")

    def getUserInput(self):
        userInput = int(input("Please insert a number: "))
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
            elif userInput == 0:
                return None
            else:
                print("Invalid number.")
