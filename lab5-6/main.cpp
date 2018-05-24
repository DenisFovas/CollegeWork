#include <iostream>
#include "dog.h"
#include "DogController.h"
#include "Repository.h"
#include "DynamicArray.h"

int main() {
    Dog a = Dog("a", "a", "www.google.com", 2);
	DogController *controller = new DogController();
	DynamicArray <Dog> *array = new DynamicArray();
	Repository <Dog> repository = new <Dog> Repository(controller)
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
