//
// Created by denis on 17.04.2017.
//

#ifndef LAB5_6_UIADMIN_H
#define LAB5_6_UIADMIN_H

#include "Controller.h"
#include "UserUi.h"

class UiAdmin {
private:
    UserUi &userUi;
    Controller &controller;

    std::string readString(std::string);
    int readInteger(std::string);
    void printMenu();
    void add();
    void update();
    void deleteDog();
    void getAll();
public:
    UiAdmin(UserUi&, Controller&);
    ~UiAdmin();
    Controller& getController() { return this->controller; };
    UserUi getUserUi() { return this->userUi; }
    void runUser();
    void run();
    void select();
};


#endif //LAB5_6_UIADMIN_H
