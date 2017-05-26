#include "tests.h"
#include "UiAdmin.h"

int main() {
    // Tests
    tests test;
    test.runTests();

	// Admin Controller
    Controller controllerAdmin;
    // User ui
    /* Repository <Dog> repo; */
    UserController controller{ controllerAdmin.getRepository() };
    UserUi userUi {controller};

    // Admin ui
    UiAdmin ui{userUi, controllerAdmin};

    // Initialize with test values.
    ui.getController().init();

    // Run
    ui.select();
    return 0;
}
