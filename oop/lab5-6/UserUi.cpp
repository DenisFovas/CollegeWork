//
// Created by denis on 20.04.2017.
//

#include "UserUi.h"

UserUi::UserUi(UserController &controller) : controller { controller } {

}

UserUi::~UserUi() {

}

void UserUi::displayDogs() {
    int input, size = this->getController().getRepository().getSize();
    Dog a;

    for (int i = 0; i < size; i++) {
        a = this->getController().getRepository().getElement(i);

        // TODO: Don't forget to uncomment this line
		/* a.openPhoto(); */
        std::cout << a.toString();
        std::cout << "1. Next" << std::endl;
        std::cout << "2. Add to adoption list" << std::endl;
        std::cout << "0. Exit" << std::endl << "\tPlease insert an option: ";
        std::cin >> input;
        std::cout << std::endl;
        if (input == 2) {
            this->controller.addToAdoption(a);
        } else if (input == 1) {
            if (i == size)
                i = 0;
        } else if (input == 0){
            return;
        }
    }
}

void UserUi::run() {
    while (1) {
        this->printMenu();
        int option;
        std::cout << "Please insert an option: ";
        std::cin >> option;
        switch (option) {
            case 1: {
                this->displayDogs();
                break;
            }
            case 2: {
                this->getAll();
                break;
            }
            case 3: {
                this->displayByBreedAndAge();
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
    std::cout << std::endl;
    std::cout << "1. See dogs" << std::endl;
    std::cout << "2. See all the dogs from adoption list." << std::endl;
    std::cout << "3. Display dogs based on a breed and smaller than an age." << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void UserUi::getAll() {
    int size = this->controller.getAdoptionList().getSize();
    for (int i = 0; i < size; i++) {
        std::cout << "#######################################" << std::endl;
        std::cout << this->controller.getAdoptionList().getElement(i).toString();
        std::cout << "#######################################" << std::endl;
    }
}

void UserUi::displayByBreedAndAge() {
    std::string breed;
    int age;
    std::cout << "Please insert the breed: (if you insert '-' then we will "
            "consider an empty entry)";
    std:: cin >> breed;
    std::cout << "Please insert the age: ";
    std::cin >> age;

    Repository<Dog> tmp;

    for (int j = 0; j < this->getController().getRepository().getSize(); ++j) {
        if (this->getController().getRepository().getElement(j).getBreed() == breed or
                breed == "-")
            if (this->getController().getRepository().getElement(j).getAge() <= age)
                tmp.add(this->getController().getRepository().getElement(j));
    }
    std::cout << "We have " << tmp.getSize() << " dogs: " << std::endl;
	std::cout << "We will display now the dogs:" << std::endl << std::endl;
    Dog a;

	int size = tmp.getSize();
	int input;
    for (int i = 0; i < size; i++) {
        a = tmp.getElement(i);

        // TODO: Don't forget to uncomment this line
		/* a.openPhoto(); */
        std::cout << a.toString();
        std::cout << "1. Next" << std::endl;
        std::cout << "2. Add to adoption list" << std::endl;
        std::cout << "0. Exit" << std::endl << "\tPlease insert an option: ";
        std::cin >> input;
        std::cout << std::endl;
        if (input == 2) {
            this->controller.addToAdoption(a);
        } else if (input == 1) {
            if (i == size)
                i = 0;
        } else if (input == 0){
            return;
        }
    }

}
