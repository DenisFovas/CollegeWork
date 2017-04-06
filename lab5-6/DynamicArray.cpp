//
// Created by denis on 03.04.2017.
//

#include "DynamicArray.h"


template <typename T>
DynamicArray<T>::DynamicArray() {
	this->length = 0;
	this->capacity = 0;
}

template <typename T>
bool DynamicArray<T>::deleteElement(int position) {
	if (position >= this.getLength())
		return false;
	for (int i = position; i < this.getLength(); i++) {
		this->list[i] = this->list[i + 1];
	}
	if (this.getLength() == this.getCapacity())
		this.shrink();
	return true;
}

template<typename T>
void DynamicArray<T>::addElement(T *element) {
	if (this.getLength() + 1 >= this.getCapacity())
		this.increase();
	this->list[this.length++] = element;
}

template <typename T>
void DynamicArray<T>::shrink() {
	this.setCapacity(this.getCapacity/2);
	T *aux = new T[this.getCapacity];
	for (int i = this.getLength() - 1; i >= 0; i++) {
		aux[i] = this.getElement(i);
	}
	delete[] this->list;
	list = aux;
}

template <typename T>
void DynamicArray<T>::increase() {
	this->capcity *= 2;
	T *aux = new T[this.getCapacity()];
	for (int i = 0; i < this.getLength(); i++) {
		aux[i] = this->list[i];
	}
	delete[] this->list;
	this->list = aux;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] this->list;
}
