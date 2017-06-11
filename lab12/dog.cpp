//
// Created by denis on 03.04.2017.
//

#include "dog.h"
#include <string>
#include <iostream>


/*
 * Initialize based on custom data
 */
Dog::Dog(std::string breed, std::string name, std::string photo, int age, int id_caine) {
    this->breed = breed;
    this->name = name;
    this->photo = photo;
    this->age = age;
    this->id = id_caine;
}

/*
 * Default constructor
 */
Dog::Dog() {
    this->breed = "Invalid breed";
    this->name = "Invalid name";
    this->photo = "Invalid Photo link";
    this->age = -1;
}

Dog::~Dog() {

}

/*
 * Opens the photo
 */
void Dog::openPhoto() {
    std::string url = "firefox --new-tab " + this->photo;
    system(url.c_str());
}

/*
 * Operator overloading to can check the existence of 2 dogs
 */
bool Dog::operator==( Dog other) {
    if (this->name == other.getName())
        if (this->breed == other.getBreed())
            if (this->age == other.getAge())
                if (this->id == other.getID())
                    return true;
    return false;
}

Dog &Dog::operator=(Dog other) {
    this->name = other.getName();
//    this->name = std::string::assign(other.getName());
    this->breed = other.getBreed();
//    this->breed = std::string::assign(other.getBreed());
    this->age = other.getAge();
    this->photo = other.getPhoto();
    this->id = other.getID();
    return *this;
}

std::string Dog::toString() {
    return "" + this->name + "," +
            this->breed + "," + this->photo
           + "," + std::to_string(this->age)
            + "," + std::to_string(this->id);
}

bool Dog::operator <(Dog other) {
    if (this->id < other.getID())
        return true;
    return false;
}
