//
// Created by denis on 03.04.2017.
//

#include "dog.h"
#include <iostream>

Dog::Dog(std::string breed, std::string name, std::string photo, int age) {
    this->breed = breed;
    this->name = name;
    this->photo = photo;
    this->age = age;
}

Dog::Dog() {
    this->breed = "";
    this->name = "";
    this->photo = "";
    this->age = -1;
}

Dog::~Dog() {

}

void Dog::openPhoto() {
    std::string url = "firefox " + this->photo;
    system(url.c_str());
}

bool Dog::operator==( Dog other) {
	if (this->name == other.getName()) 
		if (this->breed == other.getBreed())
			if (this->age == other.getAge())
				return true;
	return false;
}
