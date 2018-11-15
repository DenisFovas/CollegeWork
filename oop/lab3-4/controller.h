//
// Created by denis on 09.03.2017.
//

#ifndef LAB3_4_CONTROLLER_H
#define LAB3_4_CONTROLLER_H

#include "repostiroy.h"

typedef struct {
    Repository* repository;
    char today[11];
} Controller;

Controller* createController(Repository* repo);
int createProductFromUserInput(Controller* controller, char* name, char* supplier, char* expirationDate, int quantity);
Product* getProductByPosition(Repository* repo, int position);
int validateProduct(Repository *repository, Product p);
int updateSpecificProduct(Controller* controller, int position, char* name, char* supp, char* date, int quantity);
int deleteSpecificProductController(Controller* controller, int position);
Product listProductsBasedOnexpirationDate(Controller* controller, char* date, int* positionToStart);
void deleteController(Controller* controller);
void testController();

#endif //LAB3_4_CONTROLLER_H
