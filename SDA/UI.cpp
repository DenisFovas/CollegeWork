//
// Created by denis on 11/06/17.
//

#include "UI.h"

void UI::printMenu() {
    std::cout << "1. Add a book" << std::endl;
    std::cout << "2. Delete a book" << std::endl;
    std::cout << "3. Get all books" << std::endl;
    std::cout << "4. Check if a book exists" << std::endl;
    std::cout << "5. Get the number of books" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void UI::run() {
    while (1) {
        int input;
        this->printMenu();
        std::cout << "Please insert a number: ";
        std::cin >> input;
        switch (input) {
            case 1: {
                std::string name, author;
                long long isbn;
                std::cout << "Please insert the book name: ";
                std::cin >> name;
                std::cout << "Please insert the book author: ";
                std::cin >> author;
                std::cout << "Please insert the book ISBN: ";
                std::cin >> isbn;
                Book a(name, author, isbn);
                this->set.addElement(a);
                break;
            }
            case 3: {
                std::string name, author;
                std::cout << "Here are the books:" << std::endl;
                for (int i = 0; i < this->set.getSize(); ++i) {
                    Book none;
                    if (this->set.getElement(i) != none)
                        std::cout << "\t" << i << ". " << this->set.getElement(i).toString() << std::endl;
                }
                break;
            }
            case 2: {
                std::string name, author;
                long long isbn;
                std::cout << "Please insert the book name: ";
                std::cin >> name;
                std::cout << "Please insert the book author: ";
                std::cin >> author;
                std::cout << "Please insert the book ISBN: ";
                std::cin >> isbn;
                Book a(name, author, isbn);
                this->set.addElement(a);

                break;
            }
            case 4: {
                std::string name, author;
                long long isbn;
                std::cout << "Please insert the book name: ";
                std::cin >> name;
                std::cout << "Please insert the book author: ";
                std::cin >> author;
                std::cout << "Please insert the book ISBN: ";
                std::cin >> isbn;
                Book a(name, author, isbn);
                bool state = this->set.find(a);
                if (state)
                    std::cout << "The book " <<  a.toString() << " exists!";
                else
                    std::cout << "The book " <<  a.toString() << " is not inserted!";
                std::cout << std::endl;
                break;
            }
            case 5: {
                std::cout << "The number of books inserted is: " << this->set.getNumberOfElements() << std::endl;
                break;
            }
            case 0:
                return;
            default: {
                std::cout << "Invalid position. ";
                break;
            }
        }
    }
}
