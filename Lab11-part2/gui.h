#ifndef GUI_H
#define GUI_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QList>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QWindow>
#include <QListWidget>
#include "Repository.h"
#include <QListWidgetItem>
#include "dog.h"

class GUI : public QMainWindow
{
    Q_OBJECT
private:
    Repository<Dog> dogArray;
    QListWidget *dogList;
    void populateList();
public:
    explicit GUI(int argc, char* argv[], Repository<Dog> array, QWidget *parent = 0);
    void run(int argc, char* argv[]);

signals:

public slots:
};

#endif // GUI_H
