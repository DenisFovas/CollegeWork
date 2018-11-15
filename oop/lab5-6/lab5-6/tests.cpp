//
// Created by denis on 17.04.2017.
//

#include "tests.h"
#include "Controller.h"
#include <assert.h>
#include <iostream>

void testController() {
    Controller controller;
    Dog dog1("a", "23", "google.com", 23);

    controller.add( "23", "a", "google.com", 23);
    for (int i = 0; i < 10; i++) {
        assert(!controller.add( "23", "a", "google.com", 23));
    }
    assert(controller.getRepository().getSize() == 1);
    assert(controller.getRepository()[0] == dog1);

    for (int j = 0; j < controller.getRepository().getSize(); ++j) {
        assert(controller.getRepository()[j] == dog1);
    }
    assert(controller.deleteDog(0));
    assert(controller.getRepository().getSize() == 0);
    controller.getRepository().add(dog1);

    Dog dog2("b", "23", "youtube.com", 23);
    controller.add( "23", "b", "youtube.com", 23);
    //Delete
    assert(controller.deleteDog(1));
    assert(controller.getRepository().getSize() == 1);

    controller.update("23", "b", "youtube.com", 23, 0);
    assert(controller.getRepository()[0] == dog2);

    controller.add("Ghita", "Patrocle", "youtube.com", 23);
    controller.update("Ghita2.0", "Patrocle2.0","Youtube.com", 23, 1);
    assert(controller.getRepository()[1].getBreed() == "Patrocle2.0");
}

void testDog() {
    Dog a("a", "a", "youtube.com", 1);
    assert(a.getName() == "a");
    assert(a.getBreed() == "a");
    assert(a.getPhoto() == "youtube.com");
    assert(a.getAge() == 1);
}

void testRepo() {
    DynamicVector <int> repo;
    for (int i = 0; i < 10; ++i) {
        repo.add(i);
        assert(repo[i] == i);
    }
    repo.deleteElement(1);
    for (int j = 0; j < repo.getSize(); ++j) {
        assert(repo[j] != 1);
    }
    int x = 2;
    DynamicVector <int> newRepo = repo  - x;
    for (int k = 0; k < repo.getSize(); ++k) {
        assert(repo[k] != 2);
    }
}

void tests::runTests() {
    testController();
    testDog();
    testRepo();
}
