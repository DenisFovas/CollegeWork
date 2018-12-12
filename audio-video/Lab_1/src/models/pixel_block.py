from .matrix import Matrix


class PixelBlock:

    def __init__(self, x, y):
        self.block = Matrix(8, 8) 
        self.x = x
        self.y = y

    def get_matrice(self, x, y):
        return self.block

    def set_matrice(self, x, y, m):
        self.block = m
        self.x = x
        self.y = y

    def print(self):
        self.block.print()