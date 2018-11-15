//
// Created by denis on 17.04.2017.
//

#include "Controller.h"

Controller::~Controller() {

}

/*
 * Add a entity dog to the controller.
 * Receives:
 *  name - string
 *  breed - string
 *  url - string
 *  age - int
 * Returns:
 *  true  - if we can add
 *  false - otherwise
 */
bool Controller::add(std::string name, std::string breed, std::string url, int age, int id_dog) {
    Dog a(breed, name, url, age, id_dog);
    for (int i = 0; i < this->repo.getSize(); ++i) {
        if (a == this->repo.getElement(i))
            return false;
        if (a.getID() == this->repo.getElement(i).getID())
            return false;
    }
    this->repo.add(a);
    return true;
}

/*
 * Delete a dog from the repository.
 * Receives:
 *  a - position of the dog
 * Returns:
 *  true - if the dog exists
 *  false - if the dog doesn't exists
 */
bool Controller::deleteDog(int a) {
    for (int i = 0; i <= this->repo.getSize(); i++)
        if (a == this->repo.getElement(i).getID()){
            this->repo.deleteElement(this->repo.getElement(i));
            return true;
        }
    return false;
}

Controller::Controller() {

}

/*
 * Update a dog from the repository, based on the position
 * Receives:
 *  name -string
 *  breed - string
 *  url - string
 *  age - int
 *  position - int
 *
 * Returns:
 *  true - if the dog exists on that position
 *  false - otherwise
 */
bool Controller::update(std::string name, std::string breed, std::string url, int age, int position) {
    for (int i = 0; i < this->repo.getSize(); ++i) {
        Dog dog(breed, name, url, age, position);
        if (position == this->repo.getElement(i).getID()) {
            this->repo.update(dog, i);
            return true;
        }
    }
    return false;
}

void Controller::init() {

    this->add("Max", "Pitbull", "google.com", 23, 1);
    this->add("Maxi", "Rottvailer", "google.com", 24, 2);
    this->add("Rex", "Rottvailer", "google.com", 25, 3);
    this->add("Bubu", "Daimanez", "google.com", 25, 4);
    this->add("Cutulache", "Chiuaua", "google.com", 26,5);
    this->add("Rex", "Chiuaua", "google.com", 27, 6);
    this->add("Rex", "Dalmanatian", "google.com", 28, 7);
    this->add("Narmod", "Caine luo", "google.com", 30, 9);
    this->add("Periculos", "Chiuaua", "google.com", 31, 8);
    this->add("Cutulache", "Dalmanatian", "google.com", 32, 10);
    this->add("Micutu", "Chiuaua", "google.com", 33, 11);

}
