class CompressedImage:
    def __init__(self, width, height):
        self.width = int(width)
        self.height = int(height)
        self.matrices = [ [None for i in range(0, self.width)] for i in range(0, self.height) ]

    def get_matrice(self, x, y):
        return self.matrices[x][y]

    def set_matrice(self, x, y, m):
        self.matrices[x][y] = m

    def print(self):
        for i in range(0, self.height):
            for j in range(0, self.width):
                print("The list of matrices here: " + self.matrices[i][j].print(), end=" ")