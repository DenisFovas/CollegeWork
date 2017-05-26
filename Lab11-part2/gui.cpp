#include "gui.h"
#include <string>
#include <sstream>
#include <QListWidget>
#include <QString>

GUI::GUI(int argc, char* argv[], Repository<Dog> array, QWidget *parent) : QMainWindow(parent), dogArray {array}
{

    this->run(argc, argv);
    this->populateList();
}

//int GUI::run(int argc, char *argv[]) {
//        //    QApplication a(argc, argv);
//        //    return a.exec();
//    return 1;
//}

void GUI::run(int argc, char* argv[]) {
        // The widget which we will display
        // The main layout of the window
        QHBoxLayout *horizontalLayout  = new QHBoxLayout{};

        // +++++++++++++++++++++++
        // The left layout of the window - for the adding
        QVBoxLayout *verticalLayoutLeft  = new QVBoxLayout{};
        // The right layout of the window - for the adding
        QVBoxLayout *verticalLayoutRight =  new QVBoxLayout{};

        // Create the form for the left side
        QFormLayout *formularAdd = new QFormLayout {};
        // Create the labels and the text boxes, then add them to the form
        QLabel *nameLabel = new QLabel { "&Name: " };
        QLabel *breedLabel = new QLabel { "&Breed: " };
        QLabel *urlLabel = new QLabel { "&Link: " };
        QLabel *ageLabel = new QLabel { "&Age: " };

        // Create the line edits, so that they can be set togheter
        // with the labels
        QLineEdit *nameLine = new QLineEdit {};
        QLineEdit *breedLine = new QLineEdit {};
        QLineEdit *urlLine = new QLineEdit {};
        QLineEdit *ageLine = new QLineEdit {};

        nameLabel->setBuddy(nameLine);
        breedLabel->setBuddy(breedLine);
        urlLabel->setBuddy(urlLine);
        ageLabel->setBuddy(ageLine);

        formularAdd->addRow(nameLabel, nameLine);
        formularAdd->addRow(breedLabel, breedLine);
        formularAdd->addRow(urlLabel, urlLine);
        formularAdd->addRow(ageLabel, ageLine);
        // Create the buttons
        QPushButton *addButton = new QPushButton {"Add" };
        QPushButton *deleteButton = new QPushButton {"Delete"};
        // Create the layout so that we can put the buttons down, and form up
        QVBoxLayout *leftFormAndButtons = new QVBoxLayout {};
        QHBoxLayout *buttonsLayout = new QHBoxLayout {};
        // Add the buttons to the layout
        buttonsLayout->addWidget(addButton);
        buttonsLayout->addWidget(deleteButton);
        // Add the formular and the layout of the buttons
        leftFormAndButtons->addLayout(formularAdd);
        leftFormAndButtons->addLayout(buttonsLayout);
        verticalLayoutLeft->addLayout(leftFormAndButtons);

        // +++++++++++++++
        // Gata partea stanga. Timpul de lista
        // TODO: Finnish the list
        // +++++++++++++++
        this->dogList = new QListWidget {};
        this->dogList->setSelectionMode(QAbstractItemView::SingleSelection);
        this->populateList();
        verticalLayoutRight->addWidget(this->dogList);
        // ++++++++++++++++++++++++
        // Add the formular to the layout
        verticalLayoutLeft->addLayout(formularAdd);
        // Set the layouts for the 2 parts of the window
        horizontalLayout->addLayout(verticalLayoutLeft);
        horizontalLayout->addLayout(verticalLayoutRight);
        QWidget *mainWidget = new QWidget {};
        mainWidget->setLayout(horizontalLayout);
        // Display the layout
        mainWidget->show();
}

/*
 * Generate the list to be displayed
 */
void GUI::populateList() {
    // If the list is empty, then we will clear the screen
    if (this->dogArray.getSize() < 0)
        this->dogList->clear();
    // For every dog in the repository, add it to the QList
    for (int i = 0; i < this->dogArray.getSize(); i++) {
        Dog a;
        a = this->dogArray.getElement(i);
        // Convert age (int) into a string
        std::stringstream ss;
        ss << a.getAge();
        //++++++++++++++++
        // you can use http://doc.qt.io/qt-4.8/qdesktopservices.html#openUrl to can
        // open the picture
        //++++++++++++++++
        QString item = QString::fromStdString(a.getName() + " - " + a.getBreed() + ", " + ss.str());
        QListWidgetItem *itemToAdd = new QListWidgetItem{item};
        this->dogList->addItem(itemToAdd);
    }
    if (this->dogArray.getSize() > 0)
        this->dogList->setCurrentRow(0);
}
