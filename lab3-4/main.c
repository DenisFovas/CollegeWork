// Exercise 2 - lab 3-4
#include "material.h"
#include "repostiroy.h"
#include "ui.h"

void testAll()
{
    testRepo();
    testProduct();
    testController();
}
int main() {
    // Running the tests.
    testAll();
    Repository *repo = createRepository();
    Controller *controller =createController(repo);
    Ui* ui = createUi(controller);
    run(ui);
    return 0;
}