//
// Created by denis on 5/5/17.
//

#ifndef LAB5_6_REPOSITORY_H
#define LAB5_6_REPOSITORY_H


#include <iostream>
#include "DynamicArray.h"

template <typename T>
class Repository {
private:
    DynamicVector<T> storage;

public:
    Repository();
    ~Repository();
    void add(T element);
    void update(T element, int position);
    void deleteElement(T element);
    int getSize() { return this->storage.getSize(); }
    T& getElement(int position) {return this->storage[position];}
};


template <typename T>
Repository<T>::Repository() {
}

template <typename T>
Repository<T>::~Repository() {
}

template <typename T>
void Repository<T>::add(T element) {
    this->storage.add(element);
}

template <typename T>
void Repository<T>::update(T element, int position) {
    this->storage.update(element, position);
}

template <typename T>
void Repository<T>::deleteElement(T element) {
    this->storage.deleteElement(element);
}
#endif //LAB5_6_REPOSITORY_H
