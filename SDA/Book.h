//
// Created by denis on 10/06/17.
//

#ifndef PROJECTIMPLEMENTATION_BOOK_H
#define PROJECTIMPLEMENTATION_BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string name;
    long long isbn;
    std::string author;
public:
    Book(std::string, std::string, long long);
//    Book(int);
    Book();
    Book (int nr);
    ~Book();
    bool operator==(Book other) {
        bool state = true;
        if (this->isbn != other.getISBN())
            state = false;
        return state;
    }
    Book& operator=(Book other) {
        this->author = other.getAuthor();
        this->isbn = other.getISBN();
        this->name = other.getName();
        return *this;
    }
    bool operator!=(Book other) {
        return !(this->operator==(other));
    }
    std::string toString() {
        return this->name + "," + this->author + "," + std::to_string(this->isbn);
    }
    std::string getName() {return this->name;}
    long long getISBN() {return this->isbn;}
    long long getCode() {return this->isbn;}
    std::string getAuthor() {return this->author;}
};


#endif //PROJECTIMPLEMENTATION_BOOK_H
