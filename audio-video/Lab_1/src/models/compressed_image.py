import math

from .matrix import Matrix
from .pixel_block import PixelBlock

class CompressedImage:
    def __init__(self, width, height):
        self.image_blocks = []

    def get_block_at_position(self, x, y):
        for block in self.image_blocks:
            if block.x == x and block.y == y:
                return block

    def add_image_block(self, image_block):
        self.image_blocks.append(image_block)

    def set_pixel_block(self, pixel_block, x, y):
        for i in range(len(self.image_blocks)):
            if self.image_blocks[i].x == x and self.image_blocks[i].y == y:
                self.image_blocks[i] = pixel_block
                return
