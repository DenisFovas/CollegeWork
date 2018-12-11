from Models import PixelRGB
from Models.Matrix import Matrix

class PPMImage:
    def __init__(self, imageFile):
        self.__imageFile = imageFile
        self.__image = None
        self.width = 0
        self.height = 0
        self.__maxValue = 0
        self.__read_header()
        self.__imageMatrix = Matrix(self.width, self.height)
        self.__readImageContent(self.__image)

    def __read_header(self):
        raw_lines = [line.rstrip('\n') for line in open(self.__imageFile)]

        if raw_lines[0] != "P3":
            raise Exception("Invalid file format. I mean, we don't accept it yet. Sorry.. :(")

        self.__get_header(raw_lines)
        self.__image = raw_lines[4:]

    def __readImageContent(self, raw_lines):
        index = 0
        for i in range(0, self.height):
            for j in range(0, self.width):
                self.__imageMatrix.m[i][j] = PixelRGB.RGBPixel()
                self.__imageMatrix.m[i][j].red = int(raw_lines[index])
                self.__imageMatrix.m[i][j].green = int(raw_lines[index+1])
                self.__imageMatrix.m[i][j].blue = int(raw_lines[index+2])
                index += 3

    def __get_header(self, raw_lines):
        self.__extract_width_height(raw_lines)
        self.__maxValue = int(raw_lines[3])

    def __extract_width_height(self, raw_lines):
        width_height = raw_lines[2].split()
        self.width = int(width_height[0])
        self.height = int(width_height[1])
        # Make the padding to be multiple of 8.
        if self.width % 8 != 0:
            self.width += (8 - self.width % 8)
        if self.height % 8 != 0:
            self.height += (8 - self.height % 8)
    
    @property
    def image(self):
        return self.__imageMatrix.m