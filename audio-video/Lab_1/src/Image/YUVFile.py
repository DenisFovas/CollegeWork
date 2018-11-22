class YUVFile:
    def __init__(self) -> None:
        super().__init__()
        self.__width = 0
        self.__height = 0
        self.__y = []
        self.__u = []
        self.__v = []

    @property
    def y(self):
        return self.__y

    @property
    def u(self):
        return self.__u

    @property
    def v(self):
        return self.__v

    @property
    def width(self):
        return self.__width

    @property
    def height(self):
        return self.__height

    def __computeValues(self, red, green, blue):
        y, u, v = 0, 0, 0
        y = 0.299 * red + 0.587 * green + 0.114 * blue
        u = 128 - 0.1687 * red - 0.3312 * green + 0.5 * blue
        v = 128 + 0.5 * red - 0.4186 * green - 0.0813 * blue
        self.__y.append(y)
        self.__u.append(u)
        self.__v.append(v)

    def computeMatrices(self):
        pass
