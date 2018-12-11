class Matrix:
    def __init__(self, width = 0, height = 0):
        self.width = width
        self.height = height
        self.m = [ [None for j in range(self.width)] for i in range(self.height)]

    def print(self):
         for i in range(0, self.height):
            for j in range(0, self.width):
                print(self.m[i][j], end=" ")
            print()