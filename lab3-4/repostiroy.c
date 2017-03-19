//
// Created by denis on 09.03.2017.
//

#include <malloc.h>
#include <string.h>
#include "repostiroy.h"

/*
 * Will create a repository and will initialize the standard values.
 */
Repository* createRepository()
{
    Repository* repo;

    repo = (Repository*)malloc(sizeof(Repository*));

    repo->capacity = 8;
    repo->length = 0;
    repo->array = malloc(sizeof(Element *) * repo->capacity);

    return repo;
}

/*
 * Will destroy the repository and will free the memory.
 * Input:
 *      Repository* repo - the repository which we destroy and free.
 */
void deleteRepository(Repository *repo)
{
    free(repo->array);
    free(repo);
}

/*
 * Will save a custom Product in the repository as the last element in the list.
 * Input:
 *      Repository* repo - the repo for which we will save.
 *      Product* product - the product which we will save.
 */
int saveProductToRepository(Repository *repo, Product *product)
{
    if (repo->capacity <= repo->length) {
        repo->capacity *= 2;
        repo->array = realloc(repo->array, sizeof(Product *) * repo->capacity);
    }
    if (repo->array[repo->length++] = product)
        return 1;
    else
        return 0;
}

/*
 * Will delete a specific product from the repository using a position.
 * If the length is one quarter of the hole capacity or less, we will shrink the array
 * Input:
 *      Repository* repo - the repository used.
 *      int productPosition - the position on which we will delete it.
 * Output:
 *      -2 - if we can't delete, because the length is -2
 *      -1 - if the position is invalid (the position is out of the length
 *      1 - if the delete function was successfully
 */
int deleteProductFromRepository(Repository *repo, int productPosition)
{
     if (repo->length == 0)
        return -2;
     if (productPosition >= repo->length)
        // If we can't get that element we return -1
        return -1;

    for (int i = productPosition; i < repo->length; i++)
    {
        repo->array[i] = repo->array[i + 1];
    }
    repo->length--;
    if (repo->length < (repo->capacity / 4))
    {
        repo->capacity = repo->capacity / 2;
        repo->array = realloc(repo->array, sizeof(Element) * repo->capacity);
    }
    return 1;
}

void testRepo()
{
    Repository* repo = createRepository();

    assert(deleteProductFromRepository(repo, 0) == -2);

    assert(repo->capacity == 8);
    assert(repo->length == 0);


    Product* p = createProduct("1\0", "2\0", "3\0",10);
    saveProductToRepository(repo, p);

    assert(deleteProductFromRepository(repo, 2) == -1);

    assert(repo->array[0] == p);
    assert(repo->length == 1);
    assert(strcmp(repo->array[0]->name, p->name) == 0);
    assert(strcmp(repo->array[0]->supplier, p->supplier) == 0);
    assert(strcmp(repo->array[0]->expirationDate, p->expirationDate) == 0);

    for (int i = 0; i < 9; ++i) {
        saveProductToRepository(repo, p);
    }
    assert(repo->capacity == 16);
    assert(repo->length == 10);

    deleteProductFromRepository(repo, 1);
    assert(repo->length == 9);
    for (int j = 0; j < 8; ++j) {
        assert(deleteProductFromRepository(repo, 0) == 1);
    }
    assert(repo->capacity == 4);
    deleteRepository(repo);
}
