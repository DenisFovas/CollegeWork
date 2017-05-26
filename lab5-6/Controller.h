//
// Created by denis on 17.04.2017.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include "dog.h"
#include "Repository.h"

class Controller {
private:
    Repository <Dog> repo;
public:
    Controller();
    ~Controller();

    bool add(std::string, std::string, std::string, int, int);
    bool deleteDog(int);
    bool update(std::string, std::string, std::string, int, int);
    void init();

    Repository<Dog> &getRepository() { return this->repo; };
};


#endif //LAB5_6_CONTROLLER_H
