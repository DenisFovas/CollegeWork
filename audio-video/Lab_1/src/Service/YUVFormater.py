from Models import Matrix, YUVPixel, CompressedImage

class YUVFormater:
    def __init__(self, width = 0, height = 0):
        self.y = Matrix.Matrix(width, height)
        self.u = Matrix.Matrix(width, height)
        self.v = Matrix.Matrix(width, height)
        self.y_compressed_image = []
        self.u_compressed_image = []
        self.v_compressed_image = []

    # This will 
    def insertPixels(self, image):
        for i in range(0, self.y.height):
            for j in range(0, self.y.width):
                rgb = image[i][j]
                yuv_pixel = YUVPixel.YUVPixel()
                yuv_pixel.computeValues(rgb.red, rgb.green, rgb.blue)
                self.y.m[i][j] = yuv_pixel.y
                self.u.m[i][j] = yuv_pixel.u
                self.v.m[i][j] = yuv_pixel.v

    def downsapling(self):
        self.y_compressed_image = self.downsapling_matrix(self.y)
        self.u_compressed_image = self.downsapling_matrix(self.u)
        self.v_compressed_image = self.downsapling_matrix(self.v)

    def downsapling_matrix(self, matrix):
        compressed_image_width = matrix.width / 8
        compressed_image_height = matrix.height / 8
        compressed_image = CompressedImage.CompressedImage(compressed_image_width, compressed_image_height)
        temp = Matrix.Matrix(8, 8)
        x, y = 0, 0
        for i in range(0, matrix.height):
            for j in range(0, matrix.width):
                temp.m[i % 8][j % 8] = matrix.m[i][j]
                if x % 8 == 0 and y % 8 == 0:
                    compressed_image.set_matrice(x, y, temp)
                    x += 1
                    y += 1
        return compressed_image

   