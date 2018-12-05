class YUVPixel:
    def __init__(self):
        self.y = 0
        self.u = 0
        self.v = 0

    def computeValues(self, red, green, blue):
        self.y = 0.299 * red + 0.587 * green + 0.114 * blue
        self.u = 128 - 0.1687 * red - 0.3312 * green + 0.5 * blue
        self.v = 128 + 0.5 * red - 0.4186 * green - 0.0813 * blue
