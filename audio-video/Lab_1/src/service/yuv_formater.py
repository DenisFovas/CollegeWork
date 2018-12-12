from models.matrix import Matrix
from models.yuv_pixel import YUVPixel
from models.pixel_block import PixelBlock
from models.compressed_image import CompressedImage

class YUVFormater:

    def __init__(self, width=0, height=0):
        self.y = Matrix(width, height)
        self.u = Matrix(width, height)
        self.v = Matrix(width, height)
        self.y_compressed_image = CompressedImage(self.y.width * self.y.height // 64)
        self.u_compressed_image = CompressedImage(self.u.width * self.u.height // 64)
        self.v_compressed_image = CompressedImage(self.v.width * self.v.height // 64)
        
    def insertPixels(self, image):
        for i in range(0, self.y.height):
            for j in range(0, self.y.width):
                rgb = image[i][j]
                yuv_pixel = YUVPixel()
                yuv_pixel.computeValues(rgb.red, rgb.green, rgb.blue)
                self.y.m[i][j] = yuv_pixel.y
                self.u.m[i][j] = yuv_pixel.u
                self.v.m[i][j] = yuv_pixel.v

    def downsapling(self):
        '''Split all fo the images into the base blocks'''
        self.y_compressed_image = self.downsapling_matrix(self.y)
        self.u_compressed_image = self.downsapling_matrix(self.u)
        self.v_compressed_image = self.downsapling_matrix(self.v)

    def downsapling_matrix(self, matrix):
        '''Downsapling for a matrix. Will split the received matrix into 8x8 chungs and return those chunks.'''
        compressed_image_width = matrix.width / 8
        compressed_image_height = matrix.height / 8
        pixel_block = PixelBlock(compressed_image_width, compressed_image_height)
        a = CompressedImage(compressed_image_width * compressed_image_height // 64)
        temp = Matrix(8, 8)
        for i in range(0, matrix.height):
            for j in range(0, matrix.width):
                pixel_block = a.get_block_at_position(i // 8, j // 8)
                temp.m[i % 8][j % 8] = matrix.m[i][j]
                # pixel_block.set_matrice(i // 2, j // 2, temp)
                a.set_pixel_block(pixel_block, i//2, j //2)
        return a