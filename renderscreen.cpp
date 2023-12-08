#include "renderscreen.h"
#include "ui_renderscreen.h"
#include <QFileDialog>
#include "shapeeditor.h"
#include "aboutus.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderScreen)
{
    ui->setupUi(this);
    fillComboBox();
    connect(this->ui->shapeSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(checkSelection(int)));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(onSaveClick(bool)));
}

MainScreen::~MainScreen()
{
    delete ui;
}

// onSaveClick()
//
void MainScreen::onSaveClick(bool){
    QString filename = QFileDialog::getSaveFileName(this, "Choose file name: ", "", "Text files (*.txt)");
    if(filename.isEmpty()||filename.isNull()){
        return;
    }
    // code to save shape data goes here GRYUUUM
}

// Fills th4e combo box with the NAMES of the shapes (may need to cast to Qstring but Qt sometimes does this implicitly)
void MainScreen::fillComboBox(){

    this->ui->shapeSelection->clear();
    this->ui->shapeSelection->addItem("N/A");
    this->ui->shapeSelection->addItem("New...");


}

// checks selection, calls function to create new shape if "New..."
void MainScreen::checkSelection(int shapeDropDownSel){

    Shape* shape = nullptr;
    if (shapeDropDownSel != 0)
    {
        shape = shapeList[shapeDropDownSel - 1];
    }
    ShapeEditor editor(this, shape);
    if(editor.exec() == 1){
        // code to create/save and add shape to vector
        // Some kind of function to get the shape.
        Shape* newShape = editor.getShapeData(); // Function that returns a shape pointer.
        if (newShape == nullptr)
        {
            return;
        }
        if (shapeDropDownSel == 0)
        {
            // Add the shape to the end of the vector.
            shapeList.push_back(newShape);
        }
        else
        {
            // We want to delete the data of the old shape immediately.
            delete shape;
            // Replace the value in the vector with the new shape.
            shapeList[shapeDropDownSel - 1] = newShape;
        }

        // Call something here to update the combobox and the UI and whatever else needs to be updated. You may just want to pass the shape vector around as a constant reference so it can be read but not modified.
    }
}

void MainScreen::on_help_clicked()
{
    aboutus *mainscreen1 = new aboutus();
    mainscreen1->show();
}


