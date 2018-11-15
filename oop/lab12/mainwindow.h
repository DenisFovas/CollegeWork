#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "dog.h"
#include "Controller.h"
#include "Repository.h"
#include "UserController.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
  Controller controller;
  UserController userController {controller.getRepository()};
  Ui::MainWindow *ui;
  void populateRepositoryList();
  void populateAdoptionList();
  void populateFilterList(int);
public slots:
    void addFunction();
    void adoptFunction();
    void removeFunction();
    void filterFunction();
};

#endif // MAINWINDOW_H
