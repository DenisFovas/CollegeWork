//
// Created by denis on 03.04.2017.
//

#ifndef LAB5_6_DYNAMICARRAY_H
#define LAB5_6_DYNAMICARRAY_H

template <typename T> class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();
    bool addElement(T element);
    bool deleteElement(T element);

private:
    T list[8];
    int capacity = 16;
    int length = 0;
};

#endif //LAB5_6_DYNAMICARRAY_H
