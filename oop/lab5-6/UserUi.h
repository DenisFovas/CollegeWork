//
// Created by denis on 20.04.2017.
//

#ifndef LAB5_6_USERUI_H
#define LAB5_6_USERUI_H


#include "Repository.h"
#include "UserController.h"

class UserUi {
private:
    UserController controller;
    void printMenu();
    void displayDogs();
    void displayByBreedAndAge();

public:
    UserUi(UserController &);
    ~UserUi();
    void run();
    UserController& getController() {return this->controller;}
    /* void setController(UserController controller)  { this->controller = controller;} */
    void getAll();
};


#endif //LAB5_6_USERUI_H
