//
// Created by denis on 09.03.2017.
//

#include <malloc.h>
#include <tkPort.h>
#include "controller.h"


Controller* createController(Repository* repo)
{
    Controller* controller = malloc(sizeof(Controller));

    controller->repository = repo;

    return controller;
}

int createProductFromUserInput(Controller* controller, char* name, char* supplier, char* expirationDate, int quantity)
{
    Product *p = createProduct(name, supplier, expirationDate, quantity);

    int state = validateProduct(controller->repository, *p);
    if (state == 1)
        return saveProductToRepository(controller->repository, p);
    if (state == -2)
    {
        for (int i = 0; i < controller->repository->length; ++i) {
            if (strcmp(controller->repository->array[i]->name, p->name) == 0) {
                controller->repository->array[i]->quantity += p->quantity;
                return 2;
            }
        }
    }
    return 0;
}

Product* getProductByPosition(Repository* repo, int position)
{
    if (position < repo->length)
        return repo->array[position];
    else
        return 0;
}

int validateProduct(Repository* repo, Product p)
{
    if (p.expirationDate[2] != '/' && p.expirationDate[5] != '/')
        return -1;
    if (strlen(p.expirationDate) != 10)
        return -1;
    for (int i = 0; i< repo->length; i++)
    {
        if (strcmp(repo->array[i]->name, p.name) == 0)
            return -2;
        for (int j = 0; j < strlen(repo->array[i]->expirationDate); ++j) {
            if (j == 2 || j == 5)
                j++;
            else if (!(p.expirationDate[j] >= '0' && p.expirationDate[j] <= '9'))
                return -1;
        }
    }
    return 1;
}

void deleteController(Controller* controller)
{
    deleteRepository(controller->repository);
    free(controller);
}

void testController()
{
    Repository* repo = createRepository();
    Controller* controller = createController(repo);

    assert(createProductFromUserInput(controller, "ana", "are mere", "10/10/2000", 100) == 1);
    assert(createProductFromUserInput(controller, "1", "2", "3", 10) == 0);
    assert(createProductFromUserInput(controller, "1", "2", "3", 10) == 0);
    assert(strcmp(controller->repository->array[0]->name, "ana\0") == 0);

    assert(getProductByPosition(controller->repository, 102) == 0);
    deleteController(controller);
}
