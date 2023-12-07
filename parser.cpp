#include <iostream>
#include <fstream>
#include <string>
#include <QMap>
#include <limits>
#include <QDebug>
#include "parser.h"
#include "Line.h"
#include "Rectangle.h"

Shape* ReadLine(std::ifstream&, int id);
Shape* ReadPolyLine(std::ifstream&, int id);
Shape* ReadPolygon(std::ifstream&, int id);
Shape* ReadRectangle(std::ifstream&, int id);
Shape* ReadSquare(std::ifstream&, int id);
Shape* ReadEllipse(std::ifstream&, int id);
Shape* ReadCircle(std::ifstream&, int id);
Shape* ReadText(std::ifstream&, int id);

Qt::GlobalColor  getColor(const std::string&);
Qt::PenStyle     getPenStyle(const std::string&);
Qt::PenCapStyle  getCapStyle(const std::string&);
Qt::PenJoinStyle getPenJoinStyle(const std::string&);
Qt::BrushStyle   getBrushStyle(const std::string&);
QFont::Weight    getFontWeight(const std::string&);

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

scrumptious::Vector<Shape*> LoadFile() // Open the file
{
    scrumptious::Vector<Shape*> myShapes;

    std::ifstream inFile;
    inFile.open("shapes.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        std::perror("Reason");
    }

    // Loop to go through each shape in text
    while(inFile)
    {
        // Declaring shape id and shape type variables
        int id;
        std::string typeStr;
        ShapeNames type;

        // Get id from text file
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> id;

        qInfo() << "This is the id: " << id;

        // Get shape type from text file
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> typeStr;

        qInfo() << "This is the type string: " << typeStr;

        // Convert shape type from string to enum ShapeNames
        type = INPUT_SHAPE_NAMES.key(typeStr);

        qInfo() << "This is the type enum: " << type;

        if(inFile.eof()) {
            break;
        }

        // Go to correct shape type based on type found and call read functions to create a
        // shape class of that type. i.e. ReadLine produces a line class
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

    inFile.close();

    return myShapes;
}

Shape* ReadLine(std::ifstream& inFile, int id)
{
    int x1, x2, y1, y2, width;
    std::string color, style, cap, join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> x2;
    inFile.get();
    inFile >> y2;

    qInfo() << x1 << " " << y1 << " " << x2 << " " << y2;
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    qInfo() << color << getColor(color);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;
    qInfo() << width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;
    qInfo() << style << getPenStyle(style);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    qInfo() << cap << getCapStyle(cap);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;
    qInfo() << join << getPenJoinStyle(join);

    QPoint p1(x1, y1);
    QPoint p2(x2, y2);

    qInfo() << p1 << p2;

    QPen pen(getColor(color));
    pen.setWidth(width);
    pen.setStyle(getPenStyle(style));
    pen.setCapStyle(getCapStyle(cap));
    pen.setJoinStyle(getPenJoinStyle(join));

    Line *line = new Line(p1, p2);

    qInfo() << "Before";

    // line->setPen(pen);

    qInfo() << "After";

    return line;
}

Shape* ReadPolyLine(std::ifstream& inFile, int id)
{

}

Shape* ReadPolygon(std::ifstream& inFile, int id)
{

}

Shape* ReadRectangle(std::ifstream& inFile, int id)
{
    int x1, y1, l, w, width; // Shape Dimensions variables
    std::string color, style, cap, join, brushColor, brushStyle; // Pen stuff

    // Getting the shape dimensions
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> l;
    inFile.get();
    inFile >> w;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, color);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, style);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, cap);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, join);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, brushColor);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(inFile, brushStyle);

    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+l),(y1+w)); // Point 2

    QBrush brush(getColor(color), getBrushStyle(brushStyle));
    QPen   pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    Rectangle* rectangle = new Rectangle(p1, p2);
    rectangle->setId(id); // Set ID
    rectangle->setBrush(brush);
    rectangle->setPen(pen);

    return rectangle;
}

Shape* ReadSquare(std::ifstream& inFile, int id)
{

}

Shape* ReadEllipse(std::ifstream& inFile, int id)
{

}

Shape* ReadCircle(std::ifstream& inFile, int id)
{

}

Shape* ReadText(std::ifstream& inFile, int id)
{

}

// Functions to convert string into Qt class using QMap
Qt::GlobalColor  getColor(const std::string& colorStr)
{
    const QMap<std::string, Qt::GlobalColor> colorMap {
        {"white", Qt::white},
        {"black", Qt::black},
        {"red", Qt::red},
        {"green", Qt::green},
        {"blue", Qt::blue},
        {"cyan", Qt::cyan},
        {"magenta", Qt::magenta},
        {"yellow", Qt::yellow},
        {"gray", Qt::gray},
    };

    return colorMap.value(colorStr);
}

Qt::PenStyle     getPenStyle(const std::string& styleStr)
{
    const QMap<std::string, Qt::PenStyle> styleMap {
        {"NoPen", Qt::NoPen},
        {"SolidLine", Qt::SolidLine},
        {"DashLine", Qt::DashLine},
        {"DotLine", Qt::DotLine},
        {"DashDotLine", Qt::DashDotLine},
        {"DashDotDotLine", Qt::DashDotDotLine},
    };

    return styleMap.value(styleStr);
}

Qt::PenCapStyle  getCapStyle(const std::string& capStr)
{
    const QMap<std::string, Qt::PenCapStyle> capMap {
        {"SquareCap", Qt::SquareCap},
        {"FlatCap", Qt::FlatCap},
        {"RoundCap", Qt::RoundCap},
    };

    return capMap.value(capStr);
}

Qt::PenJoinStyle getPenJoinStyle(const std::string& joinStr)
{
    const QMap<std::string, Qt::PenJoinStyle> joinMap {
        {"BevelJoin", Qt::BevelJoin},
        {"MiterJoin", Qt::MiterJoin},
        {"RoundJoin", Qt::RoundJoin},
    };

    return joinMap.value(joinStr);
}

Qt::BrushStyle   getBrushStyle(const std::string& brushStlyle)
{
    const QMap<std::string, Qt::BrushStyle> brushStyleMap {
        {"NoBrush", Qt::NoBrush},
        {"SolidPattern", Qt::SolidPattern},
        {"Dense1Pattern", Qt::Dense1Pattern},
        {"Dense2Pattern", Qt::Dense2Pattern},
        {"Dense3Pattern", Qt::Dense3Pattern},
        {"Dense4Pattern", Qt::Dense4Pattern},
        {"Dense5Pattern", Qt::Dense5Pattern},
        {"Dense6Pattern", Qt::Dense6Pattern},
        {"Dense7Pattern", Qt::Dense7Pattern},
        {"HorPattern", Qt::HorPattern},
        {"VerPattern", Qt::VerPattern},
        {"CrossPattern", Qt::CrossPattern},
        {"BDiagPattern", Qt::BDiagPattern},
        {"FDiagPattern", Qt::FDiagPattern},
        {"DiagCrossPattern", Qt::DiagCrossPattern},
        {"LinearGradientPattern", Qt::LinearGradientPattern},
        {"ConicalGradientPattern", Qt::ConicalGradientPattern},
        {"RadialGradientPattern", Qt::RadialGradientPattern},
        {"TexturePattern", Qt::TexturePattern},
    };

    return brushStyleMap.value(brushStlyle);
}

QFont::Weight    getFontWeight(const std::string&);
