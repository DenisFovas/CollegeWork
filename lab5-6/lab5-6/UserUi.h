//
// Created by denis on 20.04.2017.
//

#ifndef LAB5_6_USERUI_H
#define LAB5_6_USERUI_H


#include "Controller.h"

class UserUi {
private:
    Controller controller;
    void printMenu();

public:
    UserUi();
    ~UserUi();
    void run();
};


#endif //LAB5_6_USERUI_H
