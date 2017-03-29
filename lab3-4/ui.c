//
// Created by denis on 09.03.2017.
//

#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Ui* createUi(Controller* controller)
{
   Ui *ui;
   ui = malloc(sizeof(Ui*));
   ui->controller = controller;
   ui->isRunning = 1;

   return ui;
}

int validInput(char *c)
{
    int state = -1;
    int var;

    if (sscanf(c, "%d", &var) != 1)
        state = -1;
    if (var != atoi(c))
        state = -1;
    for (int i = 0; i < strlen(c); ++i) {
        if (c[i] >= '0' && c[i] <= '9')
            state = 1;
    }

    return state;
}

int readCommand()
{
   char c[10];
   int number = -1;

   printf("Please insert the command: ");
   scanf("%s", c);

   if (validInput(c) == 1)
   {
      sscanf(c, "%d", &number);
   }

   return number;
}

void printMenu()
{
    printf("\n******************************************\n");
    printf("1. Add a product\n");
    printf("2. List all products\n");
    printf("3. Update a product\n");
    printf("4. Delete a product\n");
    printf("5. See materials based on the expiration date\n");
    printf("0. Exit\n\n");
    printf("\n******************************************\n");
}

int getDataForProduct(Ui* ui)
{
    char name[100];
    char supp[100];
    char date[11];
    int quantity;

    printf("\n");
    printf("Please insert the product name: ");
    scanf("%s", name);
    printf("Please insert the supplier: ");
    scanf("%s", supp);
    printf("Please insert the expiration date in the format yyyy/mm/dd: ");
    scanf("%s", date);
    printf("Please inert the quantity: ");
    scanf("%d", &quantity);

    return createProductFromUserInput(ui->controller, name, supp, date, quantity);
}

void listItems(Ui* ui)
{
    for (int i = 0; i < ui->controller->repository->length; ++i) {
        printf("The product number %d has the following proprieties: \n", i);
        printf("\tName: %s\n", ui->controller->repository->array[i]->name);
        printf("\tSupplier: %s\n", ui->controller->repository->array[i]->supplier);
        printf("\tQuantity: %d\n", ui->controller->repository->array[i]->quantity);
        printf("\t\tExpiration date: %s\n\n", ui->controller->repository->array[i]->expirationDate);
    }
}

int updateSpecificProductUi(Ui* ui)
{
    char name[100];
    char supp[100];
    char date[11];
    int quantity;
    int number;

    printf("Please insert the number of the product: ");
    scanf("%d", &number);
    printf("\tPlease insert the new specifications of the product: ");
    printf("\n");
    printf("\tPlease insert the product name: ");
    scanf("%s", name);
    printf("\tPlease insert the supplier: ");
    scanf("%s", supp);
    printf("\tPlease insert the expiration date in the format yyyy/mm/dd ");
    scanf("%s", date);
    printf("\tPlease inert the quantity: ");
    scanf("%d", &quantity);
    return updateSpecificProduct(ui->controller, number, name, supp, date, quantity);
}

int deleteSpecificProductUi(Ui* ui)
{
    int position;
    printf("Please insert the position of the product you wish to delete: ");
    scanf("%d", &position);
    int status = deleteSpecificProductController(ui->controller, position);
    return status;
}
void deleteUi(Ui* ui)
{
    deleteController(ui->controller);
    free(ui);
}

int listMaterialsBasedOnExpirationDateUi(Ui* ui)
{
    char date[11];
    int position = 0;
    int state = 0;
    Product *p = createProduct("", "", "0000/00/00", 0);
	printf("Please insert the expiration date below. If you insert space, we will consider the today date.\n\t");
    printf("Please insert the expiration date: ");
	/* fgets(date, sizeof(date), stdin); */
	date = gets_s(date, 11);

    while (position < (ui->controller->repository->length - 1) && (strcmp(p->name, "null") != 0 &&
            strcmp(p->supplier, "null") != 0)) {
        *p = listProductsBasedOnexpirationDate(ui->controller, date, &position);
        if (strcmp(p->name, "null") == 0 && strcmp(p->supplier, "null") == 0 &&
                strcmp(p->expirationDate, ui->controller->today) == 0 && p->quantity == -1) {
            position = ui->controller->repository->length;
            return (state == 0);
        }
        state++;
        printf("The product %s, from %s expired on: %s. You had %d pieces.\n",
               p->name, p->supplier, p->expirationDate, p->quantity);
    }
    if (state == 0)
        return 0;
    return 1;
}

void run(Ui* ui)
{
    printf("Please insert the current date in the format yyyy/mm/dd: ");
    scanf("%s", ui->controller->today);
    createProductFromUserInput(ui->controller, "Paine", "Brutarie 1", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Faina", "Brutarie 2", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "oua", "Brutarie 3", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "iaurt", "Brutarie 4", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Paine", "Brutarie 1", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "floare", "Brutarie 2", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Ulei", "Brutarie 1", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Zahar", "Brutarie 4", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Drojdie", "Brutarie 1", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Butter", "Brutarie 34", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "Paine", "Brutarie 10", "2014/19/20", 20);
    createProductFromUserInput(ui->controller, "nu stiu ce altceva", "Brutarie 341", "2014/19/20", 20);
   while (ui->isRunning)
   {
       printMenu();
       int userInput = readCommand();
       switch (userInput)
       {
           case 1: {
               int result = getDataForProduct(ui);
               if (result == 1 || result == 2)
                   printf("Operation successful\n");
               else
                   printf("Invalid data. Please try again.\n");
               break;
           }
           case 2: {
               listItems(ui);
               break;
           }
           case 3: {
               int result = updateSpecificProductUi(ui);
               if (result == 1)
                   printf("The input was valid and the update of the product was done.\n");
               else
                   printf("The input was invalid. Please try again!\n");
               break;
           }
           case 4: {
               int result = deleteSpecificProductUi(ui);
               if (result == -2)
                   printf("We don't have enough elements to can delete elements. Try to add some elements.\n");
               else if (result == -1)
                   printf("The position you inserted was invalid. Please try again.\n");
               else
                   printf("The element was deleted with success!\n");
               break;
           }
           case 5: {
               int result = listMaterialsBasedOnExpirationDateUi(ui);
               if (result == 0)
                   printf("We don't have products which expire on that day.\n");
               break;
           }
           case 0: {
               deleteUi(ui);
               return;
           }
           default:
           {
               printf("Invalid command. Please try again.\n");
               break;
           }

       }
   }
}

