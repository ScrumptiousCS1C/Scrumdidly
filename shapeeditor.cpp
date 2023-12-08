#include "shapeeditor.h"
#include "ui_shapeeditor.h"
#include "Line.h"
#include "Text.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Ellipse.h"

ShapeEditor::ShapeEditor(QWidget *parent, Shape* shape) :
    QDialog(parent),
    ui(new Ui::ShapeEditor)
{
    ui->setupUi(this);
    if(shape != nullptr)
    {
        // set current tab to correct shape
        // set combo box to correct tab
        // fill shape data
        ui->shapeType->setCurrentIndex(shape->getShapeType());
        ui->shapeDetails->setCurrentIndex(shape->getShapeType());
        if(shape->getShapeType() == Shape::ShapeType::text){

        }
    }
}

ShapeEditor::~ShapeEditor()
{
    delete ui;
}

Shape* ShapeEditor::getShapeData() const
{
    Shape* shape = nullptr;
    switch(ui->shapeType->currentIndex())
    {
    case 0:
        break;
    case Shape::ShapeType::line:
        Line* line = new Line();

        shape = line;
        break;
    }

    return shape;
}

//void ShapeEditor::switchShapeTab(){
//    this->ui->
//}
