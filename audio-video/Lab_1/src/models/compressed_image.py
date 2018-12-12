import math

from .matrix import Matrix
from .pixel_block import PixelBlock

class CompressedImage:
    def __init__(self, width, height):
        self.image_blocks = [ PixelBlock(-1, -1) for i in range(image_block_size) ]
        self.compact_matrix = Matrix(width, height)

    def get_block_at_position(self, x, y): 
        # for block in self.image_blocks:
        #     if block.x == x and block.y == y:
        #         return block
        return self.compact_matrix.m[x][y]
    
    def add_image_block(self, image_block):
        self.image_blocks.append(image_block)
    
    def set_pixel_block(self, pixel_block, x, y):
        self.compact_matrix.m[x][y] = pixel_block