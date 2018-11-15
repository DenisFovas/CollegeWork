class PPMImage:
    def __init__(self, imageFile) -> None:
        super().__init__()
        self.__imageFile = imageFile
        self.__image = None
        self.__width = 0
        self.__height = 0
        self.__red = []
        self.__green = []
        self.__blue = []
        self.__maxValue = 0
        self.__read_header()

    def __read_header(self):
        self.__image = open(self.__imageFile, "r")
        raw_lines = [line.rstrip('\n') for line in open(self.__imageFile)]

        if raw_lines[0] != "P3":
            raise Exception("Invalid file format. I mean, we don't accept it yet. Sorry.. :(")

        self.__get_header(raw_lines)
        raw_lines = raw_lines[4:]
        for i in range(0, len(raw_lines), 3):
            self.__red.append(raw_lines[i])
            self.__green.append(raw_lines[i + 1])
            self.__blue.append(raw_lines[i + 2])

    def __get_header(self, raw_lines):
        self.__extract_width_height(raw_lines)
        self.__maxValue = int(raw_lines[3])

    def __extract_width_height(self, raw_lines):
        width_height = raw_lines[2].split()
        self.__width = int(width_height[0])
        self.__height = int(width_height[1])

    @property
    def red(self):
        return self.__red

    @property
    def green(self):
        return self.__green

    @property
    def blue(self):
        return self.__blue
