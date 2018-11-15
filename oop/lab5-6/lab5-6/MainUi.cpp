//
// Created by denis on 17.04.2017.
//

#include <iostream>
#include "MainUi.h"

MainUi::MainUi() {
    this->uiAdmin.getController().add("Da", "poate", "google.com", 23);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 24);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 25);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 25);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 26);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 27);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 28);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 30);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 31);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 32);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 33);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 34);
    this->uiAdmin.getController().add("Da", "poate", "google.com", 36);
}

MainUi::~MainUi() {

}

void MainUi::run() {
    int number;
    std::cout << "1. Administrator" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Please insert the mode that you will use: ";
    std::cin >> number;
    if (number == 1)
        this->uiAdmin.run();
    else if (number == 2)
        this->uiUser.run();
    else if (number == 0)
        return;
    else this->run();
}

