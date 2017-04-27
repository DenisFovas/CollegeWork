
/*
 * File name : 
 *
 * Creation Date :
 *
 * Last Modified :
 *
 * Created By: Fovas Denis
 */

#ifndef __LAB5_5_DOGCONTROLLER__
#define __LAB5_5_DOGCONTROLLER__


#include "dog.h"
class DogController {

public:
	DogController();
	~DogController();

	bool isValidDogData(std::string, std::string, std::string, int);
};
#endif
