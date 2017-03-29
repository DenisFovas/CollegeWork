//
// Created by denis on 09.03.2017.
//

#include "material.h"
#include <string.h>
#include <stdlib.h>

/*
 * Will create the product
 * Input:
 *      char* name - the name of the product
 *      char* supplier - the name of the supplier
 *      char* expirationDate - the date on which the product will expire
 * Output:
 *      Product* p - the product that was created. It will be a pointer in HEAP for
 *                   the product.
 */
Product* createProduct(char *name, char* supplier, char* expirationDate, int quantity)
{
    Product *p;

    p = malloc(sizeof(Product));

    p->name = malloc(sizeof(char *) * (strlen(name) + 1));
    strcpy(p->name, name);

    p->supplier = (char*)malloc(sizeof(char *) * (strlen(supplier) + 1));
    strcpy(p->supplier, supplier);

    p->expirationDate = (char *)malloc(sizeof(char *) * (strlen(expirationDate) + 1));
    strcpy(p->expirationDate, expirationDate);

    p->quantity = quantity;
    return p;
}

/*
 * Will delete the pointer and will deallocate the memory.
 * Input:
 *      Product* p - the product on which we will freethe memory and will delete it.
 */
void deleteProduct(Product *p)
{
    free(p->name);
    free(p->supplier);
    free(p->expirationDate);

    free(p);
}

/*
 * Will update the old product with a new product with new settings.
 * Input:
 *      Product* p - the old product, the product on which we will need to
 *                   update the data
 *      Product* new_P - the new data for the product stored as a product
 */
void updateProduct(Product *p, Product *new_P) {
    // will resize the proprieties to can get the new values
    strcpy(p->name, "");
    free(p->name);
    p->name = malloc(sizeof(char) * strlen(new_P->name));
    strcpy(p->supplier, "");
    free(p->supplier);
    p->supplier = malloc(sizeof(char) * strlen(new_P->supplier));
    strcpy(p->expirationDate, "");
    free(p->expirationDate);
    p->expirationDate = malloc(sizeof(char) * strlen(new_P->expirationDate));
    // Will copy the specifications of the new product to the Product p
    strcpy(p->name, new_P->name);
    strcpy(p->supplier, new_P->supplier);
    strcpy(p->expirationDate, new_P->expirationDate);
    p->quantity = new_P->quantity;
    deleteProduct(new_P);
}

void testProduct()
{
    Product *p = createProduct("Nume1", "supp", "22", 10);

    assert(strcmp(p->name, "Nume1") == 0);
    assert(strcmp(p->supplier, "supp") == 0);
    assert(strcmp(p->expirationDate, "22") == 0);
    assert(p->quantity == 10);

    Product *new_p = createProduct("a", "sup", "12", 100);

    updateProduct(p, new_p);

    assert(strcmp(p->name, "a") == 0);
    assert(strcmp(p->supplier, "sup") == 0);
    assert(strcmp(p->expirationDate, "12") == 0);
    assert(p->quantity == 100);

    deleteProduct(p);
}
