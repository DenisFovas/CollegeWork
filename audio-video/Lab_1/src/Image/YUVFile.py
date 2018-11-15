class YUVFile:
    def __init__(self) -> None:
        super().__init__()
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

    @y.setter
    def y(self, red, green, blue):
        pass
