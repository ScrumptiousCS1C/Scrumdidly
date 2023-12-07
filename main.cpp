#include "vector.h"
#include "Shape.h"
#include "Line.h"
#include "parser.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    QMainWindow mainWindow;

    scrumptious::Vector<Shape*> myShapes = LoadFile();

    QPoint p1(1, 11);
    QPoint p2(11, 1);
    Line *some = new Line(p1, p2);
    some->setId(5);
    myShapes.push_back(some);

    QLabel* label = new QLabel(&mainWindow);

    std::string str = std::to_string(myShapes[0]->getId()) + "\n" + "I hate Qt";
    label->setText(QString::fromStdString(str));

    // Set the label as the central widget of the main window
    mainWindow.setCentralWidget(label);

    mainWindow.show();
    return application.exec();
}
