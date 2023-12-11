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
        if(shape->getShapeType() == Shape::ShapeType::text)
        {
            ui->penbrushdetails->setCurrentIndex(1);
        }
        // plug values into corresponding places
        switch(shape->getShapeType())
        {
        case 0:
            break;
        case Shape::ShapeType::line:
        {
            const QLine& line = ((Line*)shape)->getLine();
            ui->line_x1->setValue(line.x1());
            ui->line_y1->setValue(line.y1());
            ui->line_x2->setValue(line.x2());
            ui->line_y2->setValue(line.y2());
        }
        }
    }
    else
    {
        Shape* newLine = new Line();
        ui->shapeType->setCurrentIndex(newLine->getShapeType());
        ui->shapeDetails->setCurrentIndex(newLine->getShapeType());

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
    {
        QPoint p1(ui->line_x1->value(), ui->line_y1->value());
        QPoint p2(ui->line_x2->value(), ui->line_y2->value());

        Line* line = new Line(p1, p2);

        shape = line;
        break;
    }
    case Shape::ShapeType::polyline:
    {
        Polyline* polyline = new Polyline();

        shape = polyline;
        break;
    }
    case Shape::ShapeType::polygon:
    {
        Polygon* polygon = new Polygon();

        shape = polygon;
        break;
    }
    case Shape::ShapeType::rectangle:
    {
        Rectangle* rectangle = new Rectangle();

        shape = rectangle;
        break;
    }
    case Shape::ShapeType::ellipse:
    {
        Ellipse* ellipse = new Ellipse();

        shape = ellipse;
        break;
    }
    case Shape::ShapeType::text:
    {
        Text* text = new Text();

        shape = text;
        break;
    }
    }


    return shape;
}

//void ShapeEditor::switchShapeTab(){
//    this->ui->
//}
