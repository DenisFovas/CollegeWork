//
// Created by denis on 09.03.2017.
//

#ifndef LAB3_4_UI_H
#define LAB3_4_UI_H

#include "controller.h"

typedef struct {
    Controller *controller;
    int isRunning;
} Ui;
Ui* createUi(Controller *controller);
void run(Ui* ui);

#endif //LAB3_4_UI_H
