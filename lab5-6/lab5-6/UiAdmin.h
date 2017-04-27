//
// Created by denis on 17.04.2017.
//

#ifndef LAB5_6_UIADMIN_H
#define LAB5_6_UIADMIN_H

#include "Controller.h"

class UiAdmin {
private:
    Controller controller;
    std::string readString(std::string);
    int readInteger(std::string);
    void printMenu();
    void add();
    void update();
    void deleteDog();
    void getAll();
public:
    void run();
    UiAdmin();
    ~UiAdmin();
    Controller getController() { return this->controller; };
};


#endif //LAB5_6_UIADMIN_H
