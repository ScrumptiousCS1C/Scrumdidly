#include "shapeeditor.h"
#include "ui_shapeeditor.h"
#include "Line.h"
#include "Text.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Ellipse.h"

ShapeEditor::ShapeEditor(QWidget *parent, Shape<int>* shape) :
    QDialog(parent),
    ui(new Ui::ShapeEditor)
{
    ui->setupUi(this);

    connect(this->ui->shapeType, SIGNAL(currentIndexChanged(int)), this->ui->shapeDetails, SLOT(setCurrentIndex(int)));
    if(shape != nullptr)
    {
        // set current tab to correct shape
        // set combo box to correct tab
        // fill shape data
        ui->shapeType->setCurrentIndex(shape->getShapeType());
        ui->shapeDetails->setCurrentIndex(ui->shapeType->currentIndex());
        if(shape->getShapeType() == Shape<int>::ShapeType::text)
        {
            ui->penbrushdetails->setCurrentIndex(1);
        }
        // plug values into corresponding places
        switch(shape->getShapeType())
        {
        case 0:
            break;
        case Shape<int>::ShapeType::line:
        {

            //const QLine& line = ((Line<int>*)shape)->getLine();
            ui->line_id->setValue(shape->getId());
            ui->line_x1->setValue(shape->getPoint(0));
            ui->line_y1->setValue(shape->getPoint(1));
            ui->line_x2->setValue(shape->getPoint(2));
            ui->line_y2->setValue(shape->getPoint(3));
            break;
        }
        case Shape<int>::ShapeType::polyline:
        {
            //const QPolygon& polyLine = ((Polyline<int>*)shape)->getPolyline();
            ui->polyline_id->setValue(shape->getId());
            ui->polyline_x1->setValue(shape->getPoint(0));
            ui->polyline_y1->setValue(shape->getPoint(1));
            ui->polyline_x2->setValue(shape->getPoint(2));
            ui->polyline_y2->setValue(shape->getPoint(3));
            ui->polyline_x3->setValue(shape->getPoint(4));
            ui->polyline_y3->setValue(shape->getPoint(5));
            break;
        }
        case Shape<int>::ShapeType::polygon:
        {
            //const QPolygon& polygon = ((Polygon<int>*)shape)->getPolygon();
            ui->polygon_id->setValue(shape->getId());
            ui->polygon_x1->setValue(shape->getPoint(0));
            ui->polygon_y1->setValue(shape->getPoint(1));
            ui->polygon_x2->setValue(shape->getPoint(2));
            ui->polygon_y2->setValue(shape->getPoint(3));
            ui->polygon_x3->setValue(shape->getPoint(4));
            ui->polygon_y3->setValue(shape->getPoint(5));
            ui->polygon_x4->setValue(shape->getPoint(6));
            ui->polygon_y4->setValue(shape->getPoint(7));
            ui->polygon_x5->setValue(shape->getPoint(8));
            ui->polygon_y5->setValue(shape->getPoint(9));
            break;
        }
        case Shape<int>::ShapeType::rectangle:
        {
            // const QRect& rect = ((Rectangle<int>*)shape)->getRectangle();
            ui->rectangle_id->setValue(shape->getId());
            ui->rectangle_x1->setValue(shape->getPoint(0));
            ui->rectangle_y1->setValue(shape->getPoint(1));
            ui->rectangle_x2->setValue(shape->getPoint(2));
            ui->rectangle_y2->setValue(shape->getPoint(3));

            break;
        }
        case Shape<int>::ShapeType::square:
        {
            break;
        }
        case Shape<int>::ShapeType::ellipse:
        {
            // const QRect& ellipse = ((Ellipse<int>*)shape)->getEllipseRect();
            ui->Ellipse_id->setValue(shape->getId());
            ui->ellipse_x1->setValue(shape->getPoint(0));
            ui->ellipse_y1->setValue(shape->getPoint(1));
            ui->ellipse_x2->setValue(shape->getPoint(2));
            ui->ellipse_y2->setValue(shape->getPoint(3));
            break;
        }
        case Shape<int>::ShapeType::circle:
        {
            break;
        }
        }
        // set pen/brush data
        ui->penStyle->setCurrentIndex(shape->getPen().style());
        ui->penCap->setCurrentIndex(static_cast<int>(shape->getPen().capStyle()));
        ui->width->setValue(shape->getPen().width());
        ui->joinStyle->setCurrentIndex(shape->getPen().joinStyle());
        ui->color->setCurrentIndex(getQtColorEnum(shape->getPen().color()) - 2);
        ui->style->setCurrentIndex(shape->getBrush().style());

    }
}

Qt::GlobalColor ShapeEditor::getQtColorEnum(const QColor& color)
{
    std::map<QRgb, Qt::GlobalColor> colorMap = {
        { qRgb(255, 255, 255), Qt::white },
        { qRgb(0, 0, 0), Qt::black },
        { qRgb(128, 128, 128), Qt::gray },
        { qRgb(160, 160, 165), Qt::lightGray },
        { qRgb(192, 192, 192), Qt::darkGray },
        { qRgb(255, 0, 0), Qt::red },
        { qRgb(0, 255, 0), Qt::green },
        { qRgb(0, 0, 255), Qt::blue },
        { qRgb(0, 255, 255), Qt::cyan },
        { qRgb(255, 0, 255), Qt::magenta },
        { qRgb(255, 255, 0), Qt::yellow },
        { qRgb(128, 0, 0), Qt::darkRed },
        { qRgb(0, 128, 0), Qt::darkGreen },
        { qRgb(0, 0, 128), Qt::darkBlue },
        { qRgb(0, 128, 128), Qt::darkCyan },
        { qRgb(128, 0, 128), Qt::darkMagenta },
        { qRgb(128, 128, 0), Qt::darkYellow }
    };
    auto it = colorMap.find(color.rgb());
    if (it != colorMap.end()) {
        return it->second;
    }
    else {
        return Qt::color0; // Invalid color
    }
}

ShapeEditor::~ShapeEditor()
{
    delete ui;
}

void ShapeEditor::getPenBrush(QPen pen, QBrush brush)
{

}

Shape<int>* ShapeEditor::getShapeData()
{
    Shape<int>* shape = nullptr;
    QPen pen;
    QBrush brush;

    // if the current selected shape isn't text or empty
    if(ui->shapeType->currentIndex() != Shape<int>::ShapeType::text
        || ui->shapeType->currentIndex() != Shape<int>::ShapeType::empty)
    {
        // set pen style
        pen.setStyle((Qt::PenStyle)ui->penStyle->currentIndex());

        // set pencap style
        pen.setCapStyle((Qt::PenCapStyle)ui->penCap->currentIndex());

        // Set pen width
        pen.setWidth(ui->width->value());

        // set pen join style
        pen.setJoinStyle((Qt::PenJoinStyle)ui->joinStyle->currentIndex());

        // set pen color
        brush.setColor((Qt::GlobalColor)(ui->color->currentIndex() + 2));

        // set fill style
        brush.setStyle((Qt::BrushStyle)ui->style->currentIndex());

        pen.setBrush(brush);
    }

    switch(ui->shapeType->currentIndex())
    {
    case 0:
        break;
    case Shape<int>::ShapeType::line:
    {
        QPoint p1(ui->line_x1->value(), ui->line_y1->value());
        QPoint p2(ui->line_x2->value(), ui->line_y2->value());
        int id = ui->line_id->value();
        scrumptious::Vector<int> dimensions;
        dimensions.push_back(p1.x());
        dimensions.push_back(p1.y());
        dimensions.push_back(p2.x());
        dimensions.push_back(p2.y());

        Line<int>* line = new Line<int>(p1, p2, id, dimensions, pen);

        shape = line;
        break;
    }
    case Shape<int>::ShapeType::polyline:
    {
        QPoint p1(ui->polyline_x1->value(), ui->polyline_y1->value());
        QPoint p2(ui->polyline_x2->value(), ui->polyline_y2->value());
        QPoint p3(ui->polyline_x3->value(), ui->polyline_y3->value());
        QList points{p1, p2, p3};
        int id = ui->polyline_id->value();
        scrumptious::Vector<int> dimensions;
        dimensions.push_back(p1.x());
        dimensions.push_back(p1.y());
        dimensions.push_back(p2.x());
        dimensions.push_back(p2.y());
        dimensions.push_back(p3.x());
        dimensions.push_back(p3.y());

        Polyline<int>* polyline = new Polyline<int>(points, id, dimensions, pen);

        shape = polyline;
        break;
    }
    case Shape<int>::ShapeType::polygon:
    {
        QPoint p1(ui->polygon_x1->value(), ui->polygon_y1->value());
        QPoint p2(ui->polygon_x2->value(), ui->polygon_y2->value());
        QPoint p3(ui->polygon_x3->value(), ui->polygon_y3->value());
        QPoint p4(ui->polygon_x4->value(), ui->polygon_y4->value());
        QPoint p5(ui->polygon_x5->value(), ui->polygon_y5->value());
        QList points{p1, p2, p3, p4, p5};

        int id = ui->polygon_id->value();

        scrumptious::Vector<int> dimensions;
        dimensions.push_back(p1.x());
        dimensions.push_back(p1.y());
        dimensions.push_back(p2.x());
        dimensions.push_back(p2.y());
        dimensions.push_back(p3.x());
        dimensions.push_back(p3.y());
        dimensions.push_back(p4.x());
        dimensions.push_back(p4.y());
        dimensions.push_back(p5.x());
        dimensions.push_back(p5.y());

        Polygon<int>* polygon = new Polygon<int>(points, id, dimensions, pen);

        shape = polygon;
        break;
    }
    case Shape<int>::ShapeType::rectangle:
    {
        QPoint p1(ui->rectangle_x1->value(), ui->rectangle_y1->value());
        QPoint p2(ui->rectangle_x2->value(), ui->rectangle_y2->value());
        int id = ui->rectangle_id->value();

        scrumptious::Vector<int> dimensions;
        dimensions.push_back(p1.x());
        dimensions.push_back(p1.y());
        dimensions.push_back(p2.x());
        dimensions.push_back(p2.y());

        Rectangle<int>* rectangle = new Rectangle<int>(p1, p2, id, dimensions, pen);

        shape = rectangle;
        break;
    }
    case Shape<int>::ShapeType::square:
    {
        // missing square
        break;
    }
    case Shape<int>::ShapeType::ellipse:
    {
        QPoint p1(ui->ellipse_x1->value(), ui->ellipse_y1->value());
        QPoint p2(ui->ellipse_x2->value(), ui->ellipse_y2->value());
        int id = ui->Ellipse_id->value();
        scrumptious::Vector<int> dimensions;
        dimensions.push_back(p1.x());
        dimensions.push_back(p1.y());
        dimensions.push_back(p2.x());
        dimensions.push_back(p2.y());



        Ellipse<int>* ellipse = new Ellipse<int>(p1, p2, id, dimensions, pen);

        shape = ellipse;
        break;
    }
    case Shape<int>::ShapeType::circle:
    {
        // missing circle
        break;
    }
    case Shape<int>::ShapeType::text:
    {
        Text<int>* text = new Text<int>();

        shape = text;
        break;
    }
    }
    if(shape != nullptr)
    {
        std::cout << "cap style enum" << shape->getPen().capStyle() << std::endl;
    }

    return shape;
}

//void ShapeEditor::switchShapeTab(){
//    this->ui->
//}
