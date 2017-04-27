//
// Created by denis on 03.04.2017.
//

#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H

#include "vector"
#include "dog.h"

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector() {
        this->size = 0;
	    this->capacity = 8;
	    this->elems = new T[capacity];
    }
	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();
	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);
	DynamicVector& operator-(T &element);
	/*
		Overloading the subscript operator
		Input: pos - a valid position within the vector.
		Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);
	// Adds an element to the current DynamicVector.
	void add(const T& e);
    void deleteElement(T e);
    void update(T e, int position);
	int getSize() const;
	void setSize(int s) { size = s; }

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);

public:
	class iterator: public std::iterator<std::forward_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
	private:
		T* ptr;
	public:
		iterator(T* p) : ptr{ p } { }
		iterator operator++() { this->ptr++; return *this; }
		iterator operator++(int dummy) { iterator i = *this; this->ptr++; return i; }
		T& operator*() { return *this->ptr; }
		T* operator->() { return this->ptr; }
		bool operator!=(const iterator& it) { return this->ptr != it.ptr; }
	};

	iterator begin()
	{
		return iterator{ this->elems };
	}

	iterator end()
	{
		return iterator{ this->elems + this->size };
	}
};


template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
    return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(const T& e)
{
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}
template <typename T>
void DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);

    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
    return this->size;
}

template <typename T>
void DynamicVector<T>::deleteElement(T e) {
    DynamicVector<T> newRepo;
    for (int i = 0; i < this->size; ++i) {
        if (e == this->elems[i]) {
            continue;
        } else {
            newRepo.add(this->elems[i]);
        }
    }
    *this = newRepo;
}

template <typename T>
void DynamicVector<T>::update(T e, int position) {
    this->elems[position] = e;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator-(T &element) {
    this->deleteElement(element);
    return *this;
}

#endif //LAB5_6_DYNAMICARRAY_H
