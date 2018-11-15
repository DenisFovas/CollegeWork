//
// Created by denis on 17.04.2017.
//

#include <iostream>
#include "UiAdmin.h"

/*
 * Read a string, based on a message
 */
std::string UiAdmin::readString(std::string object) {
    std::string input;
    std::cout << "Please input the " << object << ": ";
    std::cin >> input;
    return input;
}

/*
 * Reads an integer. Receives a string as a message to display
 */
int UiAdmin::readInteger(std::string object) {
    int input;
    std::cout << "Please insert a " << object << ": ";
    std::cin >> input;
    return input;
}

/*
 * Display the main menu
 */
void UiAdmin::printMenu() {
    std::cout << std::endl << std::endl;
    std::cout << "1. Add a dog" << std::endl;
    std::cout << "2. Update a dog" << std::endl;
    std::cout << "3. Delete a dog" << std::endl;
    std::cout << "4. Get all dogs" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

/*
 * The application loop
 */
void UiAdmin::run() {
    while(1) {
        printMenu();
        int number = this->readInteger("command");
        switch (number) {
            case 1: {
                this->add();
                break;
            }
            case 2: {
                this->update();
                break;
            }
            case 3: {
                this->deleteDog();
                break;
            }
            case 4: {
                this->getAll();
                break;
            }

            case 0: {
                return;
            }
            default: {
                std::cout << "Invalid input.";
                break;
            }
        }
    }
}

UiAdmin::UiAdmin(UserUi &userUi, Controller &controller) :
        userUi {userUi}, controller { controller } {
}

UiAdmin::~UiAdmin() {

}

void UiAdmin::add() {
    std::string name, breed, url;
    int age, id_dog;
    name = this->readString("name");
    breed = this->readString("breed");
    url = this->readString("url");
    age = this->readInteger("age");
    id_dog = this->readInteger("id");
    bool state = this->controller.add(name, breed, url, age, id_dog);
    if (state) {
        std::cout << "Success!";
    } else {
        std::cout << "Invalid data. The dog was already inserted.";
    }
}

void UiAdmin::update() {
    std::string name, breed, url;
    int age, position;
    name = this->readString("name");
    breed = this->readString("breed");
    url = this->readString("url");
    age = this->readInteger("age");

    position = this->readInteger("id of a dog");
    bool state = this->controller.update(name, breed, url, age, position);
    if (state)
        std::cout << "Succes!";
    else std::cout << "Invalid data.";
}

void UiAdmin::deleteDog() {
    int number;
    number = this->readInteger("id of a dog");
    bool state = this->controller.deleteDog(number);
    if (state)
        std::cout << "Success!";
    else std::cout << "Invalid id";
}

void UiAdmin::getAll() {
    for (int i = 0; i < this->controller.getRepository().getSize(); ++i) {
        Dog dog = this->controller.getRepository().getElement(i);
        std::cout << std::endl << "####################################" << std::endl;
        std::cout << dog.toString() << std::endl;
    }
}

void UiAdmin::runUser() {
    this->userUi.run();
}

void UiAdmin::select() {
    std::cout << "Insert 1 for administrator mode." << std::endl;
    std::cout << "Insert 2 for user mode." << std::endl;
    std::cout << "Select an option: ";
    char option;
    std::cin >> option;
    if (option == '1')
        this->run();
    else if (option == '2') {
        this->userUi.getController().setRepository(this->controller.getRepository());
        this->runUser();
    }
    else {
        std::cout << "Invalid input. Please try again." << std::endl;
        this->select();
    }
}
