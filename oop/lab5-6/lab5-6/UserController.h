//
// Created by denis on 21.04.2017.
//

#ifndef LAB5_6_USERCONTROLLER_H
#define LAB5_6_USERCONTROLLER_H


#include "DynamicArray.h"

class UserController {
private:
    DynamicVector <Dog> adoptionList;
    DynamicVector <Dog> mainRepository;
public:
    UserController();
    ~UserController();
};


#endif //LAB5_6_USERCONTROLLER_H
