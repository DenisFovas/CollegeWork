
#include "DynamicArray.h"

/*
template <typename T>
DynamicVector<T>::DynamicVector()
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}
 */
//
//template <typename T>
//DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
//{
//	this->size = v.size;
//	this->capacity = v.capacity;
//	this->elems = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//}
//
//template <typename T>
//DynamicVector<T>::~DynamicVector()
//{
//	delete[] this->elems;
//}
//
//template <typename T>
//DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
//{
//	if (this == &v)
//		return *this;
//
//	this->size = v.size;
//	this->capacity = v.capacity;
//
//	delete[] this->elems;
//	this->elems = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//
//	return *this;
//}
//
//template <typename T>
//T& DynamicVector<T>::operator[](int pos)
//{
//	return this->elems[pos];
//}
//
//template <typename T>
//void DynamicVector<T>::add(const T& e)
//{
//	if (this->size == this->capacity)
//		this->resize();
//	this->elems[this->size] = e;
//	this->size++;
//}
//
//template <typename T>
//void DynamicVector<T>::resize(double factor)
//{
//	this->capacity *= static_cast<int>(factor);
//
//	T* els = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		els[i] = this->elems[i];
//
//	delete[] this->elems;
//	this->elems = els;
//}
//
//template <typename T>
//int DynamicVector<T>::getSize() const
//{
//	return this->size;
//}
