//
// Created by denis on 09.03.2017.
//

#ifndef LAB3_4_CONTROLLER_H
#define LAB3_4_CONTROLLER_H

#include "repostiroy.h"

typedef struct {
    Repository* repository;
} Controller;

Controller* createController(Repository* repo);

int createProductFromUserInput(Controller* controller, char* name, char* supplier, char* expirationDate, int quantity);

Product* getProductByPosition(Repository* repo, int position);

int validateProduct(Repository *repository, Product p);

void deleteController(Controller* controller);

void testController();

#endif //LAB3_4_CONTROLLER_H
