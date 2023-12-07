#include "shapeeditor.h"
#include "ui_shapeeditor.h"

ShapeEditor::ShapeEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeEditor)
{
    ui->setupUi(this);
    fillShapeTypes();
}

ShapeEditor::~ShapeEditor()
{
    delete ui;
}

void ShapeEditor::fillShapeTypes(){
    this->ui->shapeType->addItem("Blank");
    this->ui->shapeType->addItem("Line");
    this->ui->shapeType->addItem("PolyLine");
    this->ui->shapeType->addItem("Rectangle");
    this->ui->shapeType->addItem("Ellipse");
    this->ui->shapeType->addItem("Text");

}

void ShapeEditor::switchShapeTab(){

}
