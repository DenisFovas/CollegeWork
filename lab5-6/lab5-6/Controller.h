//
// Created by denis on 17.04.2017.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include "DynamicArray.h"
#include "dog.h"

class Controller {
private:
    DynamicVector <Dog> repo;
public:
    Controller();
    ~Controller();

    bool add(std::string, std::string, std::string, int);
    bool deleteDog(int);
    bool update(std::string, std::string, std::string, int, int);
    void init();

    DynamicVector<Dog> getRepository() { return this->repo; };
};


#endif //LAB5_6_CONTROLLER_H
