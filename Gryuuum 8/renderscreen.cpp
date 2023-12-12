#include "renderscreen.h"
#include "ui_renderscreen.h"
#include <QFileDialog>
#include "shapeeditor.h"
#include "aboutus.h"
#include "Line.h"
#include <QPen>
#include "parser.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderScreen)
{
    ui->setupUi(this);
    shapeList = LoadFile();
    fillComboBox();
    connect(this->ui->shapeSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(checkSelection(int)));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(onSaveClicked(bool)));
    connect(this->ui->draw, SIGNAL(clicked(bool)), this, SLOT(onDrawClicked(bool)));
    connect(this->ui->newProject, SIGNAL(clicked(bool)), this, SLOT(onNewProjectClicked(bool)));
    connect(this->ui->help, SIGNAL(clicked(bool)), this, SLOT(onHelpClicked(bool)));
}

void MainScreen::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QRect rect = ui->canvas->geometry();
    painter.setViewport(rect);

    if(drawShapes)
    {
        for(int i = 0; i < shapeList.sizeOf(); i++)
        {
            shapeList[i]->draw(&painter);
        }
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

    Shape<int>* shape = nullptr;
    if (shapeDropDownSel != 1) // if new was not selected
    {
        shape = shapeList[shapeDropDownSel - 2];
    }
    ShapeEditor editor(this, shape);
    if(editor.exec() == 1){
        std::cout<< "hello" << std::endl;
        // code to create/save and add shape to vector
        // Some kind of function to get the shape.
        Shape<int>* newShape = editor.getShapeData(); // Function that returns a shape pointer.
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


void MainScreen::on_quit_clicked()
{
    MainScreen::close();
}

