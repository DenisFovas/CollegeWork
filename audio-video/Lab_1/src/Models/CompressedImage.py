class CompressedImage:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.matrices = [ [None for i in range(0, width)] for i in range(0, height) ]

    def get_matrice(self, x, y):
        return self.matrices[x][y]

    def set_matrice(self, x, y, m):
        self.matrices[x][y] = m

    def print_structure(self):
        for i in range(0, self.height):
            for j in range(0, self.width):
                print(self.matrices)
    
    def compress_matrix(self, target_matrix):
        for i in range(self.height, 2):
            for j in range(self.width, 2):
                pass
        pass