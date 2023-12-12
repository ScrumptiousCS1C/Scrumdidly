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

            const QLine& line = ((Line<int>*)shape)->getLine();
            ui->line_id->setValue(shape->getId());
            ui->line_x1->setValue(line.x1());
            ui->line_y1->setValue(line.y1());
            ui->line_x2->setValue(line.x2());
            ui->line_y2->setValue(line.y2());
            break;
        }
        case Shape<int>::ShapeType::polyline:
        {
            const QPolygon& polyLine = ((Polyline<int>*)shape)->getPolyline();
            ui->polyline_id->setValue(shape->getId());
            ui->polyline_x1->setValue(polyLine.point(0).x());
            ui->polyline_y1->setValue(polyLine.point(0).y());
            ui->polyline_x2->setValue(polyLine.point(1).x());
            ui->polyline_y2->setValue(polyLine.point(1).y());
            ui->polyline_x3->setValue(polyLine.point(2).x());
            ui->polyline_y3->setValue(polyLine.point(2).y());
            break;
        }
        case Shape<int>::ShapeType::polygon:
        {
            const QPolygon& polygon = ((Polygon<int>*)shape)->getPolygon();
            ui->polygon_id->setValue(shape->getId());
            ui->polygon_x1->setValue(polygon.point(0).x());
            ui->polygon_y1->setValue(polygon.point(0).y());
            ui->polygon_x2->setValue(polygon.point(1).x());
            ui->polygon_y2->setValue(polygon.point(1).y());
            ui->polygon_x3->setValue(polygon.point(2).x());
            ui->polygon_y3->setValue(polygon.point(2).y());
            ui->polygon_x4->setValue(polygon.point(3).x());
            ui->polygon_y4->setValue(polygon.point(3).y());
            ui->polygon_x5->setValue(polygon.point(4).x());
            ui->polygon_y5->setValue(polygon.point(4).y());
            break;
        }
        case Shape<int>::ShapeType::rectangle:
        {
            const QRect& rect = ((Rectangle<int>*)shape)->getRectangle();
            ui->rectangle_id->setValue(shape->getId());
            ui->rectangle_x1->setValue(rect.topLeft().x());
            ui->rectangle_y1->setValue(rect.topLeft().y());
            ui->rectangle_x2->setValue(rect.bottomRight().x());
            ui->rectangle_y2->setValue(rect.bottomRight().y());

            break;
        }
        case Shape<int>::ShapeType::square:
        {
            break;
        }
        case Shape<int>::ShapeType::ellipse:
        {
            const QRect& ellipse = ((Ellipse<int>*)shape)->getEllipseRect();
            ui->Ellipse_id->setValue(shape->getId());
            ui->ellipse_x1->setValue(ellipse.topLeft().x());
            ui->ellipse_y1->setValue(ellipse.topLeft().y());
            ui->ellipse_x2->setValue(ellipse.bottomRight().x());
            ui->ellipse_y2->setValue(ellipse.bottomRight().y());
            break;
        }
        case Shape<int>::ShapeType::circle:
        {
            break;
        }
        }
        // set pen/brush data
        ui->penStyle->setCurrentIndex(shape->getPen().style());
        ui->penCap->setCurrentIndex(shape->getPen().capStyle());
        ui->width->setValue(shape->getPen().width());
        ui->joinStyle->setCurrentIndex(shape->getPen().joinStyle());
        ui->color->setCurrentIndex(getQtColorEnum(shape->getPen().color()));
        ui->style->setCurrentIndex(shape->getBrush().style() - 2);

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
        { qRgb(128, 128, 0), Qt::darkYellow },
        { qRgb(0, 0, 0), Qt::transparent }
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
    switch(ui->penStyle->currentIndex())
    {
    case Qt::NoPen:
        pen.setStyle(Qt::NoPen);
        break;
    case Qt::SolidLine:
        pen.setStyle(Qt::SolidLine);
        break;
    case Qt::DashLine:
        pen.setStyle(Qt::DashLine);
        break;
    case Qt::DotLine:
        pen.setStyle(Qt::DotLine);
        break;
    case Qt::DashDotLine:
        pen.setStyle(Qt::DashDotLine);
        break;
    case Qt::DashDotDotLine:
        pen.setStyle(Qt::DashDotDotLine);
        break;
    }
    // set pencap style
    switch(ui->penCap->currentIndex())
    {
    case  Qt::FlatCap:
        pen.setCapStyle(Qt::FlatCap);
        break;
    case Qt::SquareCap:
        pen.setCapStyle(Qt::SquareCap);
        break;
    case Qt::RoundCap:
        pen.setCapStyle(Qt::RoundCap);
        break;
    }
    // Set pen width
    pen.setWidth(ui->width->value());

    // set pen join style
    switch(ui->joinStyle->currentIndex())
    {
    case Qt::MiterJoin:
        pen.setJoinStyle(Qt::MiterJoin);
        break;
    case Qt::BevelJoin:
        pen.setJoinStyle(Qt::BevelJoin);
        break;
    case Qt::RoundJoin:
        pen.setJoinStyle(Qt::RoundJoin);
        break;
    }
    // set pen color
    switch(ui->color->currentIndex())
    {
    case 0:
        brush.setColor(Qt::black);
        break;
    case 1:
        brush.setColor(Qt::white);
        break;
    case 2:
        brush.setColor(Qt::darkGray);
        break;
    case 3:
        brush.setColor(Qt::gray);
        break;
    case 4:
        brush.setColor(Qt::lightGray);
        break;
    case 5:
        brush.setColor(Qt::red);
        break;
    case 6:
        brush.setColor(Qt::green);
        break;
    case 7:
        brush.setColor(Qt::blue);
        break;
    case 8:
        brush.setColor(Qt::cyan);
        break;
    case 9:
        brush.setColor(Qt::magenta);
        break;
    case 10:
        brush.setColor(Qt::yellow);
        break;
    case 11:
        brush.setColor(Qt::darkRed);
        break;
    case 12:
        brush.setColor(Qt::darkGreen);
        break;
    case 13:
        brush.setColor(Qt::darkBlue);
        break;
    case 14:
        brush.setColor(Qt::darkCyan);
        break;
    case 15:
        brush.setColor(Qt::darkMagenta);
        break;
    case 16:
        brush.setColor(Qt::darkYellow);
        break;
    }

    // set fill style
    switch(ui->style->currentIndex())
    {
    case Qt::NoBrush:
        brush.setStyle(Qt::NoBrush);
        break;
    case Qt::SolidPattern:
        brush.setStyle(Qt::SolidPattern);
        break;
    case Qt::Dense1Pattern:
        brush.setStyle(Qt::Dense1Pattern);
        break;
    case Qt::Dense2Pattern:
        brush.setStyle(Qt::Dense2Pattern);
        break;
    case Qt::Dense3Pattern:
        brush.setStyle(Qt::Dense3Pattern);
        break;
    case Qt::Dense4Pattern:
        brush.setStyle(Qt::Dense4Pattern);
        break;
    case Qt::Dense5Pattern:
        brush.setStyle(Qt::Dense5Pattern);
        break;
    case Qt::Dense6Pattern:
        brush.setStyle(Qt::Dense6Pattern);
        break;
    case Qt::Dense7Pattern:
        brush.setStyle(Qt::Dense7Pattern);
        break;
    case Qt::HorPattern:
        brush.setStyle(Qt::HorPattern);
        break;
    case Qt::VerPattern:
        brush.setStyle(Qt::VerPattern);
        break;
    case Qt::CrossPattern:
        brush.setStyle(Qt::CrossPattern);
        break;
    case Qt::BDiagPattern:
        brush.setStyle(Qt::BDiagPattern);
        break;
    case Qt::FDiagPattern:
        brush.setStyle(Qt::FDiagPattern);
        break;
    case Qt::DiagCrossPattern:
        brush.setStyle(Qt::DiagCrossPattern);
        break;
    }
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

        // set pen/brush
        getPenBrush(pen, brush);
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

        Line<int>* line = new Line<int>(p1, p2, id, pen, brush);

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


        Polyline<int>* polyline = new Polyline<int>(points, id, pen, brush);

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



        Polygon<int>* polygon = new Polygon<int>(points, id, pen, brush);

        shape = polygon;
        break;
    }
    case Shape<int>::ShapeType::rectangle:
    {
        QPoint p1(ui->rectangle_x1->value(), ui->rectangle_y1->value());
        QPoint p2(ui->rectangle_x2->value(), ui->rectangle_y2->value());
        int id = ui->rectangle_id->value();

        Rectangle<int>* rectangle = new Rectangle<int>(p1, p2, id, pen, brush);

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

        Ellipse<int>* ellipse = new Ellipse<int>(p1, p2, id, pen, brush);

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


    return shape;
}

//void ShapeEditor::switchShapeTab(){
//    this->ui->
//}