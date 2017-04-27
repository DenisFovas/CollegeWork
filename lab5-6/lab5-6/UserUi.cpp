//
// Created by denis on 20.04.2017.
//

#include <iostream>
#include "UserUi.h"

UserUi::UserUi() {

}

UserUi::~UserUi() {

}

void UserUi::run() {
    while (1) {
        this->printMenu();
        int option;
        std::cout << "Please insert an option: ";
        std::cin >> option;
        switch (option) {
            case 1: {
                break;
            }
            case 0: {
                return;
            }
            default: {
                std::cout << "Invalid command. Please try again." << std::endl;
            }
        }
    }
}

void UserUi::printMenu() {
    std::cout << "1. See dogs" << std::endl;
    std::cout << "0. Exit" << std::endl;
}
