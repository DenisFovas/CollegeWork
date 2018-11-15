#include "widget.h"
#include <QApplication>
#include "gui.h"
#include "Controller.h"
#include "Repository.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a {argc, argv};
    Controller controller;
    controller.init();
    GUI gui{argc, argv, controller.getRepository()};
//    gui.show();
    return a.exec();
}

