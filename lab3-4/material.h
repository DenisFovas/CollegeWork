//
// Created by denis on 09.03.2017.
//

#ifndef LAB3_4_MATERIAL_H
#define LAB3_4_MATERIAL_H

#include <assert.h>
typedef struct {
    char *name;
    char *supplier;
    char *expirationDate;
    int quantity;
} Product;
// Constructor
Product* createProduct(char* name, char* supplier, char* expirationDate, int quantity);
// Destructor
void deleteProduct(Product *p);
// Update
void updateProduct(Product *p, Product *new_P);
void testProduct();

#endif //LAB3_4_MATERIAL_H
