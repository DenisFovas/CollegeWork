//
// Created by denis on 10/06/17.
//

#include "Tests.h"
#include "Set.h"

void Tests::testAll() {
    this->testBook();
    this->testSet();
}

void Tests::testBook() {
    Book a ("Carrie", "Stephen King", 9780671039721);
    assert(a.getISBN() == 9780671039721);
    assert(a.getCode() == 9780671039721);
    assert(a.getName() == "Carrie");
    assert(a.getAuthor() == "Stephen King");
    Book none(-1);
    assert(none.toString() == "Nothing,Unknown,-1");
    Book empty;
    assert(empty.getCode() == -1);
    assert(empty.getAuthor() == "");
    assert(empty.getName() == "");
    assert(empty.getISBN() == -1);
}

void Tests::testSet() {
    Set set;
    Book none(-1);
    Book a ("Carrie", "Stephen King", 1);
    set.addElement(a);
    assert(set.find(a));

//    assert(set.getElement(3) == a);
//    assert(set.getSize() == 43);
    assert(set.getNumberOfElements() == 1);
    set.remove(a);
    assert(!set.find(a));

    set.addElement(a);

    set.remove(a);
    Book b ("Carrie", " King", 9780671039722);
    Book c ("Carrie", "Stephen King", 9780671039724);
    set.addElement(a);
    set.addElement(b);
    assert(set.getNumberOfElements() == 2);
    assert(set.find(a));
    assert(!set.find(c));
    set.remove(b);
    assert(set.getNumberOfElements() == 1);
    assert(!set.find(b));
    assert(set.find(none));
}

