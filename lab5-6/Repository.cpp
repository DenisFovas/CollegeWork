
/*
 * File name : 
 *
 * Creation Date :
 *
 * Last Modified :
 *
 * Created By: Fovas Denis
 */

#include "Repository.h"

template <typename T>
Repository<T>::Repository(DogController dogController) {
	this->dogController = dogController;
}

template <typename T>
bool Repository<T>::createElement(std::string name, std::string breed, std::string url, int age) {
	if (this->dogController.isValidDogData(name, breed, url, age)) {
		Dog dog = new Dog(name, breed, url, age);
		this->array.addElement(dog);
		return true;
	}
	return false;
}

template <typename T>
bool Repository<T>::deleteElement(T e) {
	for (int i = 0; i < this->array.getLength(); i++) {
		if (e == this->array.getElement(i))
			return this->array.deleteElement(i);
	}
	return false;
}

template <typename T>
bool Repository<T>::updateElement(T element, int position) {
	if (this->dogController.isValidDogData(element)) {
		T *aux = this->array.getElement(position);
		aux.setName(element.getName());			
		aux.setBreed(element.getBreed());
		aux.setPhoto(element.getPhoto());
		aux.setAge(element.getAge());
		return true;
	}
}
