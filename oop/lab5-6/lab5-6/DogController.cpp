
/*
 * File name : 
 *
 * Creation Date :
 *
 * Last Modified :
 *
 * Created By: Fovas Denis
 */

#include "DogController.h"

bool DogController::isValidDogData(std::string name, std::string breed, std::string url, int age) {
	if (age < 20)
		if (name.length() > 0 and breed.length() > 0 and url.length() > 0)
			return true;
	return false;
}

DogController::DogController() {

}

DogController::~DogController() {
	
}
