//
// Created by denis on 10/06/17.
//

#ifndef PROJECTIMPLEMENTATION_SET_H
#define PROJECTIMPLEMENTATION_SET_H


#include "Book.h"
#include <string>

class Set {
private:
    Book *array;
    int size;
    int numberOfElements;
    /* long long hashFunction2(long long a) { */
    /*     long long code; */
    /*     code = a % this->size; */
    /*     return code; */
    /* } */
    long long hashFunction(long long a, long long i) {
        long long code;
        /* code = (i + this->hashFunction2(a)) % this->size; */
		code = (a + i) % this->size;
        return code;

    }
public:
    Set() {
        Book empty;
        this->size = 43;
        this->array = new Book [this->size];
        this->numberOfElements = 0;
        for (int i = 0; i < this->size; ++i) {
            this->array[i] = empty;
        }
    }
    ~Set() {
        delete []this->array;
    }
    int getNumberOfElements() { return this->numberOfElements; }
    int getSize() { return this->size; }
    Book getElement(int position) { return this->array[position]; }
    bool find(Book a) {
        Book none(-1);
        Book emptyElement;
        long long i = 0;
        long long position = this->hashFunction(a.getCode(), 0);
        while (i < this->size && this->array[position] != emptyElement && this->array[position] != a) {
            i++;
            position = this->hashFunction(a.getCode(), i);
        }
        return i < this->size && this->array[position] == a;
    }
    void remove(Book a) {
        Book none(-1);
        Book emptyElement;
        long long i = 0;
        long long position = this->hashFunction(a.getCode(), 0);
        long long lastPosition = this->hashFunction(a.getCode(), 0);
        if (!this->find(a))
            return;
        while (i < this->size && this->array[position] != emptyElement && this->array[position] != a) {
            i++;
            position = this->hashFunction(a.getCode(), i);
        }
        this->numberOfElements--;
        this->array[position] = none;
    }
    void addElement(Book a) {
        if (this->find(a))
            return;
        Book emptyElement;
        Book none(-1);
        long long i = 0;
        long long position = this->hashFunction(a.getCode(), 0);
        while (i < this->size && !(this->array[position] == emptyElement || this->array[position] == none)) {
            i++;
            position = this->hashFunction(a.getCode(), i);
        }
        if (i >= this->size) {
//             resize and rehash
        }
        else {
            this->array[position] = a;
        }
        this->numberOfElements++;
    }
};


#endif //PROJECTIMPLEMENTATION_SET_H

