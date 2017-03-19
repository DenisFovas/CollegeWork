//
// Created by denis on 09.03.2017.
//

#ifndef LAB3_4_REPOSTIROY_H
#define LAB3_4_REPOSTIROY_H

#include "material.h"

typedef Product* Element;

typedef struct {
    Element *array;
    int length;
    int capacity;
} Repository;

// Constructor
Repository* createRepository();

// Destructor
void deleteRepository(Repository *repo);

// Function to can add a special element to the repository
int saveProductToRepository(Repository *repo, Product *product);

// Function to can delete a product from the repository
int deleteProductFromRepository(Repository *repo, int productPosition);

void testRepo();

#endif //LAB3_4_REPOSTIROY_H
