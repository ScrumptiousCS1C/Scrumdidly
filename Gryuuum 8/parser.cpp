#include <iostream>
#include <fstream>
#include <string>
#include <QMap>
#include <limits>
#include <QDebug>
#include "parser.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"

// Functions to create shapes
Shape<int>* ReadLine(std::ifstream&, int id);
Shape<int>* ReadPolyLine(std::ifstream&, int id);
Shape<int>* ReadPolygon(std::ifstream&, int id);
Shape<int>* ReadRectangle(std::ifstream&, int id);
Shape<int>* ReadSquare(std::ifstream&, int id);
Shape<int>* ReadEllipse(std::ifstream&, int id);
Shape<int>* ReadCircle(std::ifstream&, int id);
Shape<int>* ReadText(std::ifstream&, int id);

// Functions to convert string to Qt object
Qt::GlobalColor   getColor(const std::string&);
Qt::PenStyle      getPenStyle(const std::string&);
Qt::PenCapStyle   getCapStyle(const std::string&);
Qt::PenJoinStyle  getPenJoinStyle(const std::string&);
Qt::BrushStyle    getBrushStyle(const std::string&);
Qt::AlignmentFlag getAlignment(const std::string&);
QFont::Style       getFontStyle(const std::string&);
QFont::Weight     getFontWeight(const std::string&);

// Map that helps converts string to enum ShapeNames
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

// Parser
scrumptious::Vector<Shape<int>*> LoadFile()
{
    // Vector that will hold the shapes
    scrumptious::Vector<Shape<int>*> myShapes;

    // Open the txt file(make sure it is in build folder)
    std::ifstream inFile;
    inFile.open("/Users/spencerglenn/Documents/CS1C/2D Modeler vector_class/Scrumdidly/Scrumdidly/loginWINDOW/shapes.txt");

    // Error check
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

        // Get id from text filer
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> id;

        // Get shape type from text file
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
        inFile >> typeStr;

        // Convert shape type from string to enum ShapeNames
        type = INPUT_SHAPE_NAMES.key(typeStr);

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

// Function to create line shape
Shape<int>* ReadLine(std::ifstream& inFile, int id)
{
    // Declare variables
    int x1, x2, y1, y2, width;
    std::string color, style, cap, join;

    // Get dimensions
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> x2;
    inFile.get();
    inFile >> y2;

    // Get pen information
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    // Initialize qpoints for the line
    QPoint p1(x1, y1);
    QPoint p2(x2, y2);

    // Initialize the pen
    QPen pen(getColor(color));
    pen.setWidth(width);
    pen.setStyle(getPenStyle(style));
    pen.setCapStyle(getCapStyle(cap));
    pen.setJoinStyle(getPenJoinStyle(join));

    // Create the line and set the line's pen
    Line<int> *line = new Line<int>(p1, p2);
    line->setPen(pen);

    return line;
}

Shape<int>* ReadPolyLine(std::ifstream& inFile, int id)
{
    int width;
    std::string color, style, cap, join;
    scrumptious::Vector<QPoint> points;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');

    do {
        int x, y;
        inFile.get();
        inFile >> x;
        inFile.get();
        inFile >> y;
        points.push_back(QPoint(x, y));
    } while (inFile.peek() == ',');

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    QPen pen(getColor(color));
    pen.setWidth(width);
    pen.setStyle(getPenStyle(style));
    pen.setCapStyle(getCapStyle(cap));
    pen.setJoinStyle(getPenJoinStyle(join));

    Polyline<int> *polyline = new Polyline<int>(points);
    polyline->setPen(pen);
    polyline->setId(id);

    return polyline;
}

Shape<int>* ReadPolygon(std::ifstream& inFile, int id)
{
    int width;
    std::string color, style, cap, join, brushColor, brushStyle;
    scrumptious::Vector<QPoint> points;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');

    do {
        int x, y;
        inFile.get();
        inFile >> x;
        inFile.get();
        inFile >> y;
        points.push_back(QPoint(x, y));
    } while (inFile.peek() == ',');

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushStyle;


    QBrush brush(getColor(brushColor), getBrushStyle(brushStyle));
    QPen   pen(getColor(color));
    pen.setBrush(brush);
    pen.setWidth(width);
    pen.setStyle(getPenStyle(style));
    pen.setCapStyle(getCapStyle(cap));
    pen.setJoinStyle(getPenJoinStyle(join));

    Polygon<int> *polygon = new Polygon<int>(points);
    polygon->setPen(pen);
    polygon->setBrush(brush);
    polygon->setId(id);

    return polygon;
}

Shape<int>* ReadRectangle(std::ifstream& inFile, int id)
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
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushStyle;

    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+l),(y1+w)); // Point 2

    QBrush brush(getColor(color), getBrushStyle(brushStyle));
    QPen   pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    Rectangle<int>* rectangle = new Rectangle<int>(p1, p2);
    rectangle->setId(id); // Set ID
    rectangle->setBrush(brush);
    rectangle->setPen(pen);

    return rectangle;
}

Shape<int>* ReadSquare(std::ifstream& inFile, int id)
{
    int x1, y1, l, width; // Shape Dimensions variables
    std::string color, style, cap, join, brushColor, brushStyle; // Pen stuff

    // Getting the shape dimensions
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> l;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushStyle;

    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+l),(y1+l)); // Point 2

    QBrush brush(getColor(color), getBrushStyle(brushStyle));
    QPen   pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    Rectangle<int>* square = new Rectangle<int>(p1, p2);
    square->setId(id); // Set ID
    square->setBrush(brush);
    square->setPen(pen);

    return square;
}

Shape<int>* ReadEllipse(std::ifstream& inFile, int id)
{
    int x1, y1, a, b, width; // Shape Dimensions variables
    std::string color, style, cap, join, brushColor, brushStyle; // Pen stuff

    // Getting the shape dimensions
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> a;
    inFile.get();
    inFile >> b;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushStyle;

    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+2*a),(y1+2*b)); // Point 2

    QBrush brush(getColor(color), getBrushStyle(brushStyle));
    QPen   pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    Ellipse<int>* ellipse = new Ellipse<int>(p1, p2);
    ellipse->setId(id); // Set ID
    ellipse->setBrush(brush);
    ellipse->setPen(pen);

    return ellipse;
}

Shape<int>* ReadCircle(std::ifstream& inFile, int id)
{
    int x1, y1, r, width; // Shape Dimensions variables
    std::string color, style, cap, join, brushColor, brushStyle; // Pen stuff

    // Getting the shape dimensions
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> x1;
    inFile.get();
    inFile >> y1;
    inFile.get();
    inFile >> r;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> color;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> style;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> cap;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> join;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> brushStyle;

    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+2*r),(y1+2*r)); // Point 2

    QBrush brush(getColor(color), getBrushStyle(brushStyle));
    QPen   pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    Ellipse<int>* circle = new Ellipse<int>(p1, p2);
    circle->setId(id); // Set ID
    circle->setBrush(brush);
    circle->setPen(pen);

    return circle;
}

Shape<int>* ReadText(std::ifstream& inFile, int id)
{
    int x1, y1, l, w, textSize; // Shape Dimensions variables
    std::string textStr, textColor, textAlignment, textFamily,
        textStyle, textWeight;

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
    inFile.get();
    getline(inFile, textStr);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> textColor;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> textAlignment;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> textSize;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile.get();
    getline(inFile, textFamily);

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> textStyle;

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> textWeight;

    // Creating QFont
    QFont font;
    font.setFamily(QString::fromStdString(textFamily));
    font.setPointSize(textSize);
    font.setStyle(getFontStyle(textStyle));

    // Creating rectangle
    QPoint p1(x1, y1); // Point 1
    QPoint p2((x1+l),(y1+w)); // Point 2
    QRect rectangle(p1, p2);

    // Creating text class
    Text<int>* text = new Text<int>();
    text->setId(id);
    text->setRect(rectangle);
    text->setFont(font);
    text->overrideText(QString::fromStdString(textStr));
    text->changeAlignment(getAlignment(textAlignment));

    return text;
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

Qt::AlignmentFlag getAlignment(const std::string& alignment)
{
    const QMap<std::string, Qt::AlignmentFlag> alignmentMap {
                                                            {"AlignLeft", Qt::AlignLeft},
                                                            {"AlignRight", Qt::AlignRight},
                                                            {"AlignTop", Qt::AlignTop},
                                                            {"AlignBottom", Qt::AlignBottom},
                                                            {"AlignCenter", Qt::AlignCenter},
                                                            };

    return alignmentMap.value(alignment);
}

QFont::Style      getFontStyle(const std::string& fontStyle)
{
    const QMap<std::string, QFont::Style> fontStyleMap {
                                                       {"StyleNormal", QFont::StyleNormal},
                                                       {"StyleItalic", QFont::StyleItalic},
                                                       {"StyleOblique", QFont::StyleOblique},
                                                       };

    return fontStyleMap.value(fontStyle);
}
QFont::Weight     getFontWeight(const std::string& fontWeight)
{
    const QMap<std::string, QFont::Weight> fontWeightMap {
                                                         {"Thin", QFont::Thin},
                                                         {"Light", QFont::Light},
                                                         {"Normal", QFont::Normal},
                                                         {"Bold", QFont::Bold},
                                                         };

    return fontWeightMap.value(fontWeight);
}
