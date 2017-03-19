//
// Created by denis on 09.03.2017.
//

#include "ui.h"
#include <stdio.h>
#include <tkPort.h>

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
    printf("0. Exit\n\n");
    printf("\n******************************************\n");


    printf("Nothing to see here\n");
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

    printf("Please insert the expiration date in the format dd/mm/yyyy: ");
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

int updateSpecificProduct(Ui* ui)
{
    int number;

    printf("Please insert the number of the product: ");
    scanf("%d", &number);
    ui->controller;
}

void run(Ui* ui)
{
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
               int result = updateSpecificProduct(ui);
               break;
           }
           case 0: {
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

