#include "tests.h"
#include "MainUi.h"

int main() {
    tests test;
    test.runTests();
    UiAdmin ui;
    ui.run();
    return 0;
}
