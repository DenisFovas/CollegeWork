//
// Created by denis on 11/06/17.
//

#ifndef PROJECTIMPLEMENTATION_UI_H
#define PROJECTIMPLEMENTATION_UI_H


#include "Set.h"

class UI {
private:
    Set set;
    void printMenu();
public:
    void run();
    void init() {
        Book a{"The Wisperer in Darkness", "H. P. Lovecraft", 9781840226089};
        Book b ("Sam Savage", "The scream of the lazy one", 9789734619665);
        Book c("Jocul lui Gerald", "Stephen King", 9786065799301);
        Book d("Jocul lui Gerald", "Stephen King", 9786065790301);
        this->set.addElement(a);
        this->set.addElement(b);
        this->set.addElement(c);
        this->set.addElement(d);
    }
};


#endif //PROJECTIMPLEMENTATION_UI_H
