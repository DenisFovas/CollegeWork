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

    createProductFromUserInput(controller, "Paine", "Brutarie 1", "10/10/1000", 20);
    createProductFromUserInput(controller, "Faine", "Brutarie 2", "10/10/1000", 20);
    createProductFromUserInput(controller, "oua", "Brutarie 3", "10/10/1000", 20);
    createProductFromUserInput(controller, "iaurt", "Brutarie 4", "10/10/1000", 20);
    createProductFromUserInput(controller, "Paine", "Brutarie 1", "10/10/1000", 20);
    createProductFromUserInput(controller, "floare", "Brutarie 2", "10/10/1000", 20);
    createProductFromUserInput(controller, "Ulei", "Brutarie 1", "10/10/1000", 20);
    createProductFromUserInput(controller, "Zahar", "Brutarie 4", "10/10/1000", 20);
    createProductFromUserInput(controller, "Drojdie", "Brutarie 1", "10/10/1000", 20);
    createProductFromUserInput(controller, "Butter", "Brutarie 34", "10/10/1000", 20);
    createProductFromUserInput(controller, "Paine", "Brutarie 10", "10/10/1000", 20);
    createProductFromUserInput(controller, "nu stiu ce altceva", "Brutarie 341", "10/10/1000", 20);


    Ui* ui = createUi(controller);
    run(ui);
    return 0;
}