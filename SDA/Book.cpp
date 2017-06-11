//
// Created by denis on 10/06/17.
//

#include "Book.h"

Book::Book(std::string name, std::string author, long long isbn) {
    this->name = name;
    this->author = author;
    this->isbn = isbn;
}

Book::Book() {
    this->name = "";
    this->author = "";
    this->isbn = -1;
}

Book::Book(int) {
    this->name = "Nothing";
    this->author = "Unknown";
    this->isbn = -1;
}
Book::~Book() {

}
