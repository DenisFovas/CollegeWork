#include "mainwindow.h"
#include <QString>
#include <iostream>
#include <string>
#include "ui_mainwindow.h"
#include <QDebug>
#include <QListWidget>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(ui->adoptButton, &QPushButton::clicked, this, &MainWindow::adoptFunction);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::removeFunction);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::filterFunction);
    this->controller.init();
    this->populateRepositoryList();
    this->populateAdoptionList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFunction()
{
    QString nameQString = ui->nameInput->text();
    QString breedQString = ui->breedInput->text();
    QString urlQString = ui->urlInput->text();
    QString ageQString = ui->ageInput->text();
    QString idQString = ui->idInput->text();
    std::string nameString = nameQString.toStdString();
    std::string breedString = breedQString.toStdString();
    std::string urlString = urlQString.toStdString();
    int ageInteger = ageQString.toInt();
    int idInteger = idQString.toInt();

    this->controller.add(nameString, breedString, urlString, ageInteger, idInteger);
    this->populateRepositoryList();
}

void MainWindow::adoptFunction()
{
    int idOfDog = ui->adoptionIdInput->text().toInt();
    for (int i = 0; i < this->controller.getRepository().getSize(); i++) {
        Dog a;
        a = this->controller.getRepository().getElement(i);
        if (a.getID() == idOfDog)
            this->userController.addToAdoption(a);
    }
    this->populateAdoptionList();
    this->populateRepositoryList();
}

void MainWindow::removeFunction()
{
    int idOfDog = ui->removeIdInput->text().toInt();
    this->controller.deleteDog(idOfDog);
    this->populateRepositoryList();
    this->populateAdoptionList();
}

void MainWindow::populateAdoptionList() {
    ui->adoptionListWidget->clear();
    for (int i = 0; i < this->userController.getAdoptionList().getSize(); i++) {
        Dog a;
        a = this->userController.getAdoptionList().getElement(i);
        QString string = QString::fromStdString(a.toString());
        QListWidgetItem *item = new QListWidgetItem {string};
        ui->adoptionListWidget->addItem(item);
    }
    ui->adoptionListWidget->setCurrentRow(0);
}

void MainWindow::populateRepositoryList() {
    ui->repositoryListWidget->clear();
    for	(int i = 0; i < this->controller.getRepository().getSize(); i++) {
        Dog a;
        a = this->controller.getRepository().getElement(i);
        QString dogInfo = QString::fromStdString(a.toString());
        QListWidgetItem* item = new QListWidgetItem{dogInfo};
        ui->repositoryListWidget->addItem(item);
    }
    ui->repositoryListWidget->setCurrentRow(0);
}

void MainWindow::filterFunction() {
    ui->filterListWidget->clear();
    int size = 0;
    std::string breedFilter = ui->breedFilterInput->text().toStdString();
    int ageFilter = ui->ageFilterInput->text().toInt();
    for	(int i = 0; i < this->controller.getRepository().getSize(); i++) {
        Dog a;
        a = this->controller.getRepository().getElement(i);
        if (breedFilter == "-" || a.getBreed() == breedFilter) {
            if (a.getAge() <= ageFilter) {
                QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(a.toString()));
                ui->filterListWidget->addItem(item);
                size++;
            }
        }
    }
    if (size > 0)
        ui->filterListWidget->setCurrentRow(0);
}

