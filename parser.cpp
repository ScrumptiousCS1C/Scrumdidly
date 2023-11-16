#include <iostream>
#include <fstream>
#include <string>
#include <QMap>
#include "parser.h"

Shape* ReadLine(std::ifstream&, int id);
Shape* ReadPolyLine(std::ifstream&, int id);
Shape* ReadPolygon(std::ifstream&, int id);
Shape* ReadRectangle(std::ifstream&, int id);
Shape* ReadSquare(std::ifstream&, int id);
Shape* ReadEllipse(std::ifstream&, int id);
Shape* ReadCircle(std::ifstream&, int id);
Shape* ReadText(std::ifstream&, int id);

Qt::GlobalColor     getColor(const std::string&);
Qt::PenStyle     getPenStyle(const std::string&);
Qt::PenCapStyle     getCapStyle(const std::string&);
Qt::PenJoinStyle     getPenJoinStyle(const std::string&);
Qt::BrushStyle     getBrushStyle(const std::string&);
QFont::Weight     getFontWeight(const std::string&);

const QMap<ShapeNames, std::string> INPUT_SHAPE_NAMES {
    {LINE, "Line"},
    {POLYLINE, "Polyline"},
    {POLYGON, "Polygon"},
    {RECTANGLE, "Rectangle"},
    {SQUARE, "Square"},
    {ELLIPSE, "Ellipse"},
    {CIRCLE, "Circle"},
    {TEXT, "Text"},
};

scrumptious::Vector<Shape*> LoadFile()
{
    std::ifstream inFile;
    inFile.open("shapes.txt");

    scrumptious::Vector<Shape*> myShapes;
    int id;

    while(inFile)
    {
        std::string typeStr;
        ShapeNames type;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> id;

        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> typeStr;
        type = INPUT_SHAPE_NAMES.key(typeStr);

        if(inFile.eof()) {
            break;
        }

        switch(type)
        {
        case LINE:
            myShapes.push_back(ReadLine(inFile, id));
            break;
        case POLYLINE:
            myShapes.push_back(ReadPolyLine(inFile, id));
            break;
        case POLYGON:
            myShapes.push_back(ReadPolygon(inFile, id));
            break;
        case RECTANGLE:
            myShapes.push_back(ReadRectangle(inFile, id));
            break;
        case SQUARE:
            myShapes.push_back(ReadSquare(inFile, id));
            break;
        case ELLIPSE:
            myShapes.push_back(ReadEllipse(inFile, id));
            break;
        case CIRCLE:
            myShapes.push_back(ReadCircle(inFile, id));
            break;
        case TEXT:
            myShapes.push_back(ReadText(inFile, id));
            break;
        }
    }
}

Shape* ReadLine(std::ifstream&, int id)
{

}

Shape* ReadPolyLine(std::ifstream&, int id)
{

}

Shape* ReadPolygon(std::ifstream&, int id)
{

}

Shape* ReadRectangle(std::ifstream&, int id)
{

}

Shape* ReadSquare(std::ifstream&, int id)
{

}

Shape* ReadEllipse(std::ifstream&, int id)
{

}

Shape* ReadCircle(std::ifstream&, int id)
{

}

Shape* ReadText(std::ifstream&, int id)
{

}

