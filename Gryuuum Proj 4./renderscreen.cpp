#include "renderscreen.h"
#include "ui_renderscreen.h"
#include <QFileDialog>
#include "shapeeditor.h"
#include "aboutus.h"
#include "Line.h"
#include <QPen>

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderScreen)
{
    ui->setupUi(this);
    fillComboBox();
    connect(this->ui->shapeSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(checkSelection(int)));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(onSaveClicked(bool)));
    connect(this->ui->draw, SIGNAL(clicked(bool)), this, SLOT(onDrawClicked(bool)));
    connect(this->ui->newProject, SIGNAL(clicked(bool)), this, SLOT(onNewProjectClicked(bool)));
    connect(this->ui->help, SIGNAL(clicked(bool)), this, SLOT(onHelpClicked(bool)));
}

void MainScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  // Use the painter provided by the paint event

    QPen pen(Qt::blue);
    QBrush brush(Qt::red);
    QPen pen1(Qt::green);
    QBrush brush2(Qt::green);

    scrumptious::Vector<Shape*> shapeVector;

    // Create an instance of Rectangle on the heap
    Rectangle *rect2 = new Rectangle(QPoint(23, 23), QPoint(53, 522));
    rect2->setPen(pen1);
    rect2->setBrush(brush2);

    // Add the rectangle to the vector
    shapeVector.push_back(rect2);



    // Create an instance of Ellipse on the heap
    Ellipse *elipse1 = new Ellipse(QPoint(600, 20), QPoint(200, 88));
    elipse1->setPen(pen1);
    elipse1->setBrush(brush2);

    // Add the ellipse to the vector
    shapeVector.push_back(elipse1);




    // Create an instance of Line on the heap
    Line *line1 = new Line(QPoint(700, 500), QPoint(200, 500));
    line1->setPen(pen1);

    // Add the line to the vector
    shapeVector.push_back(line1);




    scrumptious::Vector<QPoint> pointsVector1;
    pointsVector1.push_back(QPoint(70, 0));
    pointsVector1.push_back(QPoint(90, 100));
    pointsVector1.push_back(QPoint(200, 200));
    pointsVector1.push_back(QPoint(150, 50));



    // Create an instance of Polygon
    Polygon *polygone1 = new Polygon(pointsVector1);

    // Configure pen and brush for the first draw
    polygone1->setPen(pen);
    polygone1->setBrush(brush);

    shapeVector.push_back(polygone1);


    scrumptious::Vector<QPoint> pointsVector;
    pointsVector.push_back(QPoint(370, 120));
    pointsVector.push_back(QPoint(203, 130));
    pointsVector.push_back(QPoint(210, 400));
    pointsVector.push_back(QPoint(510, 100));

    // Create an instance of Polyline
    Polyline *polyline1 = new Polyline(pointsVector);



    // Configure pen and brush for the first draw
    polyline1->setPen(pen);
    polyline1->setBrush(brush);


    shapeVector.push_back(polyline1);


    if (drawShapes) {

        for (int i = 0; i < shapeVector.sizeOf(); ++i) {
            shapeVector[i]->draw(&painter);
        }
    }


    // Don't forget to delete the objects when done
    for (int i = 0; i < shapeVector.sizeOf(); ++i) {
        delete shapeVector[i];
    }

}

MainScreen::~MainScreen()
{
    delete ui;
}

// onSaveClick()
//
void MainScreen::onSaveClicked(bool)
{
    QString filename = QFileDialog::getSaveFileName(this, "Choose file name: ", "", "Text files (*.txt)");
    if(filename.isEmpty()||filename.isNull())
    {
        return;
    }
    // code to save shape data goes here GRYUUUM
}

// Fills the combo box with the NAMES of the shapes (may need to cast to Qstring but Qt sometimes does this implicitly)
void MainScreen::fillComboBox()
{
    reFillCombo = true;
    this->ui->shapeSelection->clear();
    this->ui->shapeSelection->addItem("N/A");
    this->ui->shapeSelection->addItem("New...");
    auto va1 = shapeList.begin();
    auto va2 = shapeList.end();
    for(auto it = shapeList.begin(); it != shapeList.end(); ++it)
    {
        this->ui->shapeSelection->addItem((*it)->getShapeTypeString());
    }
    reFillCombo = false;
}

// checks selection, calls function to create new shape if "New..."
void MainScreen::checkSelection(int shapeDropDownSel)
{
    if(reFillCombo || shapeDropDownSel == 0)
    {
        return;
    }

    std::cout << shapeDropDownSel << std::endl;

    Shape* shape = nullptr;
    if (shapeDropDownSel != 1)
    {
        shape = shapeList[shapeDropDownSel - 2];
    }
    ShapeEditor editor(this, shape);
    if(editor.exec() == 1){
        std::cout<< "hello" << std::endl;
        // code to create/save and add shape to vector
        // Some kind of function to get the shape.
        Shape* newShape = editor.getShapeData(); // Function that returns a shape pointer.
        if (newShape == nullptr)
        {
            std::cout << "Where are we" << std::endl;
            return;
        }
        if (shapeDropDownSel == 1)
        {
            // Add the shape to the end of the vector.
            std::cout << "I think it's here" << std::endl;
            shapeList.push_back(newShape);
        }
        else
        {
            // We want to delete the data of the old shape immediately.
            std::cout << "Holy shit" << std::endl;
            delete shape;
            // Replace the value in the vector with the new shape.
            shapeList[shapeDropDownSel - 2] = newShape;
        }

        // Call something here to update the combobox and the UI and whatever else needs to be updated. You may just want to pass the shape vector around as a constant reference so it can be read but not modified.
    }
    fillComboBox();
}

void MainScreen::onHelpClicked(bool)
{
    aboutus *mainscreen1 = new aboutus();
    mainscreen1->show();
}

void MainScreen::onDrawClicked(bool)
{
    // draw EVERYTHING
    // call draw functions here
    // set painter obj
    drawShapes = true;
    repaint();
}

void MainScreen::onNewProjectClicked(bool)
{
    drawShapes = false;
    repaint();
}


