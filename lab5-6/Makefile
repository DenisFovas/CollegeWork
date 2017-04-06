TARGET=app
FLAGS=-Wall -Wextra -Werror -g

init: main.o DynamicArray.o dog.o repository.o
	g++ $(FLAGS) main.o DynamicArray.o dog.o -o $(TARGET)

main.o: main.cpp
	g++ -c main.cpp

DynamicArray.o: DynamicArray.cpp
	g++ -c DynamicArray.cpp


dog.o: dog.cpp
	g++ -c dog.cpp

repository.o: Repository.cpp
	g++ -c Repository.cpp

clean: 
	test -s $(TARGET) && rm $(TARGET)
	- rm *.o

.PHONY: run clean init
