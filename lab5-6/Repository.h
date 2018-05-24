
/*
 * File name : 
 *
 * Creation Date :
 *
 * Last Modified :
 *
 * Created By: Fovas Denis
 */

#ifndef __LAB5_6__REPOSITORY__
#define __LAB5_6__REPOSITORY__

#include "DynamicArray.h"
#include "DogController.h"

template <typename T>
class Repository {
private:
	DynamicArray<T> *array;
	DogController dogController;

public:
	Repository(DogController);
	~Repository();

	bool createElement (std::string name, std::string breed, std::string url, int age);
	bool deleteElement (T element);
	bool updateElement (T element, int position);
};

#endif
