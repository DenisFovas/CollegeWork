//
// Created by denis on 21.04.2017.
//

#ifndef LAB5_6_USERCONTROLLER_H
#define LAB5_6_USERCONTROLLER_H


#include "DynamicArray.h"
#include "Repository.h"

class UserController {
private:
    Repository <Dog> adoptionList;
    Repository<Dog> &repository;
public:
    UserController(Repository<Dog>&);
    ~UserController();
    Repository<Dog> getAdoptionList();
    void setRepository(Repository<Dog> &r) { this->repository = r; }
    Repository<Dog> getRepository() { return this->repository; }
    Repository<Dog> &getByBreedAnAge(std::string, int);
    void addToAdoption(Dog);
};


#endif //LAB5_6_USERCONTROLLER_H
