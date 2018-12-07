from Service import Matrix
from Image import YUVPixel

class YUVFormater:
    def __init__(self, width = 0, height = 0):
        self.y = Matrix.Matrix(width, height)
        self.u = Matrix.Matrix(width, height)
        self.v = Matrix.Matrix(width, height)

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

    def downsapling422(self):
        temp_u = Matrix.Matrix(int(self.y.width / 2), int(self.y.height /2))
        temp_v = Matrix.Matrix(int(self.y.width / 2), int(self.y.height /2))
        for i in range(0, self.y.height, 2):
            for j in range(0, self.y.width, 2):
        
                temp_u.m[int(i/2)][int(j/2)] = (self.u.m[i][j] + self.u.m[i][j + 1] + \
                        self.v.m[i + 1][j] + self.v.m[i + 1][j + 1])/4
                temp_v.m[int(i/2)][int(j/2)] = (self.v.m[i][j] + self.v.m[i][j + 1] + \
                        self.v.m[i + 1][j] + self.v.m[i + 1][j + 1])/4
        self.u, self.v = temp_u, temp_v
 