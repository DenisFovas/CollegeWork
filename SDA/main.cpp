#include "Tests.h"
#include "UI.h"


int main() {

    Tests test;
    test.testAll();
//
//    Book a("Jocul lui Gerald", "Stephen King", 9786065799301);
//    Book b("Jocul lui Gerald", "Stephen King", 9786065790301);
//
//    Set set;
//    set.addElement(a);

    UI ui;
    ui.init();
    ui.run();
    return 0;
}