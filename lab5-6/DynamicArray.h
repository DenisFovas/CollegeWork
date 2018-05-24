//
// Created by denis on 03.04.2017.
//

#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H

template <typename T> 
class DynamicArray {

public:
    DynamicArray();
    ~DynamicArray();

    void addElement(T *element);
    bool deleteElement(int position);
	int getLength() { return this->length; }
	int getCapacity() { return this->capacity; }
	void shrink();
	void increase();
	void setCapacity(int capacity) { this->capacity = capacity; }
	T *getElement(int position) { return this->list[position]; }
	void setElement(T a, int pos) { this->list[pos] = a; }
	T *getList() { return this->list; }

private:
    T *list;
    int capacity ;
    int length ;
};

#endif //LAB5_6_DYNAMICARRAY_H
