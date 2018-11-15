//
// Created by denis on 17.04.2017.
//

#include "Controller.h"

Controller::~Controller() {

}

bool Controller::add(std::string name, std::string breed, std::string url, int age) {
    Dog a(breed, name, url, age);
    for (int i = 0; i < this->repo.getSize(); ++i) {
        if (a == this->repo[i])
            return false;
    }
    this->repo.add(a);
    return true;
}

bool Controller::deleteDog(int a) {
    if (this->repo.getSize() >= a) {
        this->repo.deleteElement(this->repo[a]);
        return true;
    }
    return false;
}

Controller::Controller() {

}

bool Controller::update(std::string name, std::string breed, std::string url, int age, int position) {
    Dog a(breed, name, url, age);
    if (position < this->getRepository().getSize()) {
        this->repo.update(a, position);
        return true;
    }
    return false;
}

void Controller::init() {

    this->add("Da", "poate", "google.com", 23);
    this->add("Da", "poate", "google.com", 24);
    this->add("Da", "poate", "google.com", 25);
    this->add("Da", "poate", "google.com", 25);
    this->add("Da", "poate", "google.com", 26);
    this->add("Da", "poate", "google.com", 27);
    this->add("Da", "poate", "google.com", 28);
    this->add("Da", "poate", "google.com", 30);
    this->add("Da", "poate", "google.com", 31);
    this->add("Da", "poate", "google.com", 32);
    this->add("Da", "poate", "google.com", 33);

}
