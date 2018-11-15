//
// Created by denis on 17.04.2017.
//

#ifndef LAB5_6_MAINUI_H
#define LAB5_6_MAINUI_H


#include "UiAdmin.h"
#include "UserUi.h"

class MainUi {
private:
    UiAdmin uiAdmin;
    UserUi uiUser;
public:
    MainUi();
    ~MainUi();
    void run();
    UiAdmin getUiAdmin() {return this->uiAdmin;}
    UserUi getUiUser() {return this->uiUser;}
};


#endif //LAB5_6_MAINUI_H
