#include "vector.h"
#include "Shape.h"
#include "Line.h"
#include "parser.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QDebug>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    QMainWindow mainWindow;

    scrumptious::Vector<Shape*> myShapes = LoadFile();
    qInfo() << "Size of vector after parser: " << myShapes.sizeOf();
    qInfo() << "Looping through vector";
    for (int i = 0; i < myShapes.sizeOf(); ++i)
    {
        qInfo() << "Id       : " << myShapes[i]->getId();
        qInfo() << "ShapeType: " << myShapes[i]->getShapeType();
        qInfo() << "Pen      : " << myShapes[i]->getPen();
    }

    QLabel* label = new QLabel(&mainWindow);

    std::string str = "This is a window";
    label->setText(QString::fromStdString(str));

    // Set the label as the central widget of the main window
    mainWindow.setCentralWidget(label);

    mainWindow.show();
    return application.exec();
}
