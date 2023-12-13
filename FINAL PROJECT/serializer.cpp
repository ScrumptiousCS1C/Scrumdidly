#include <iostream>
#include <fstream>
#include <string>
#include <QMap>
#include <QString>
#include <limits>
#include <QDebug>
#include "serializer.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"
#include "vector.h"

// Functions to create shapes
void OutputLine(std::ofstream& outFile, const Shape<int>* shape);
void OutputPolyLine(std::ofstream& outFile, const Shape<int>* shape);
void OutputPolygon(std::ofstream& outFile, const Shape<int>* shape);
void OutputRectangle(std::ofstream& outFile, const Shape<int>* shape);
void OutputSquare(std::ofstream& outFile, const Shape<int>* shape);
void OutputEllipse(std::ofstream& outFile, const Shape<int>* shape);
void OutputCircle(std::ofstream& outFile, const Shape<int>* shape);
void OutputText(std::ofstream& outFile, const Shape<int>* shape);

// Pen, brush output functions
void OutputPen(std::ofstream& outFile, const Shape<int>* shape);
void OutputBrush(std::ofstream& outFile, const Shape<int>* shape);

// Convert pen, brush info to string functions

std::string penColor(const QPen pen);
std::string penStyle(const QPen pen);
std::string penCapStyle(const QPen pen);
std::string penJoinStyle(const QPen pen);
std::string brushColor(const QBrush brush);
std::string brushStyle(const QBrush brush);

// Functions to convert string to Qt object
Qt::GlobalColor   getColor(const std::string&);
Qt::PenStyle      getPenStyle(const std::string&);
Qt::PenCapStyle   getCapStyle(const std::string&);
Qt::PenJoinStyle  getPenJoinStyle(const std::string&);
Qt::BrushStyle    getBrushStyle(const std::string&);
Qt::AlignmentFlag getAlignment(const std::string&);
QFont::Style      getFontStyle(const std::string&);
QFont::Weight     getFontWeight(const std::string&);

// Parser

//! Serializer function
/*!
* Saves shapes to custom specified file path and file name
* Pre: File name passed, File path passed, Vector of shapes passed
* Post: Saves file with info of all shapes to specified file path with specified file name
*/
void serializer(std::string fileName, scrumptious::Vector<Shape<int>*> myShapes)
{
    //std::string pathName = "shapes2.txt";
    std::string pathName = fileName; ///< Create custom file name with custom file path
    std::ofstream outFile(pathName); ///< Create and open file

    Shape<int>* shape; ///< Shape base class pointer

    for (int i = 0; i < myShapes.sizeOf(); i++) ///< Traverse through each item in the vector
    {
        shape = myShapes[i]; ///< Assign shape to pointer
        switch (shape->getShapeType()) ///< Read in the shape type, switch statement to call specific
        {
        case Shape<int>::line:
            OutputLine(outFile, shape);
            break;
        case Shape<int>::polyline:
            OutputPolyLine(outFile, shape);
            break;
        case Shape<int>::polygon:
            OutputPolygon(outFile, shape);
            break;
        case Shape<int>::rectangle:
            OutputRectangle(outFile, shape);
            break;
        case Shape<int>::square:
            OutputSquare(outFile, shape);
            break;
        case Shape<int>::ellipse:
            OutputEllipse(outFile, shape);
            break;
        case Shape<int>::circle:
            OutputCircle(outFile,shape);
            break;
        case Shape<int>::text:
            OutputText(outFile, shape);
            break;
        case Shape<int>::empty:
        default:
            break;
        };
    }

    outFile.close(); //< Close file
    return;
}


//! Output line function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info written to file
*/
void OutputLine(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    outFile << "ShapeDimensions: "
            << shape->getPoint(0) << ", " << shape->getPoint(1) << ", "
            << shape->getPoint(2) << ", " << shape->getPoint(3) << "\n";
    OutputPen(outFile, shape);
    outFile << "\n";
    return;
}

//! Output polyline function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info written to file
*/
void OutputPolyLine(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    outFile << "ShapeDimensions: "
            << shape->getPoint(0) << ", " << shape->getPoint(1) << ", "
            << shape->getPoint(2) << ", " << shape->getPoint(3) << ", "
            << shape->getPoint(4) << ", " << shape->getPoint(5) << ", "
            << shape->getPoint(6) << ", " << shape->getPoint(7) << "\n";

    OutputPen(outFile, shape);
    outFile << "\n";
    return;
}

//! Output polygon function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputPolygon(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    outFile << "ShapeDimensions: "
            << shape->getPoint(0) << ", " << shape->getPoint(1) << ", "
            << shape->getPoint(2) << ", " << shape->getPoint(3) << ", "
            << shape->getPoint(4) << ", " << shape->getPoint(5) << ", "
            << shape->getPoint(6) << ", " << shape->getPoint(7) << "\n";
    OutputPen(outFile, shape);
    OutputBrush(outFile, shape);
    outFile << "\n";
    return;
}

//! Output rectangle function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputRectangle(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    int x1 = shape->getPoint(0);
    int y1 = shape->getPoint(1);
    int l = (shape->getPoint(2)-x1);
    int w = (shape->getPoint(3)-y1);

    outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << l << ", " << w << "\n"; // Fix
    OutputPen(outFile, shape);
    OutputBrush(outFile, shape);
    outFile << "\n";
    return;
}

//! Output square function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputSquare(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    int x1 = shape->getPoint(0);
    int y1 = shape->getPoint(1);
    int l = (shape->getPoint(2)-x1);
    outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << l << "\n";
    OutputPen(outFile, shape);
    OutputBrush(outFile, shape);
    outFile << "\n";
    return;
}


//! Output ellipse function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputEllipse(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    int x1 = shape->getPoint(0);
    int y1 = shape->getPoint(1);
    int x2 = shape->getPoint(2);
    int y2 = shape->getPoint(3);
    int a = (x2 - x1) / 2;
    int b = (y2 - y1) / 2;

    outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << a << ", " << b << "\n";
    OutputPen(outFile, shape);
    OutputBrush(outFile, shape);
    outFile << "\n";
    return;
}

//! Output circle function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputCircle(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    int x1 = shape->getPoint(0);
    int y1 = shape->getPoint(1);
    int r = ((shape->getPoint(2)-x1)/2);

    outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << r << "\n";
    OutputPen(outFile, shape);
    OutputBrush(outFile, shape);
    outFile << "\n";
    return;
}

//! Output text function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputText(std::ofstream& outFile, const Shape<int>* shape)
{
    QString shapeName = shape->getShapeTypeString();
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << shapeName.toStdString() << "\n";
    int x1 = shape->getPoint(0);
    int y1 = shape->getPoint(1);
    int l = (shape->getPoint(2)-x1);
    int w = (shape->getPoint(3)-y1);

    outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << l << ", " << w << "\n";
    outFile << "TextString: " << "\n";
    outFile << "TextColor: " << "\n";
    outFile << "TextAlignment: " << "\n";
    outFile << "TextPointSize: " << "\n";
    outFile << "TextFontFamily: " << "\n";
    outFile << "TextFontStyle: " << "\n";
    outFile << "TextFontWeight: " << "\n";
    outFile << "\n";
    return;
}


//! Output pen functio
/*!
* Pre: Shape in vector
* Post: Pen color, width, style, cap style, join style written to file
*/
void OutputPen(std::ofstream& outFile, const Shape<int>* shape)
{
    QPen pen = shape->getPen(); //< Get pen from given shape
    outFile << "PenColor: " << penColor(pen) << "\n";
    outFile << "PenWidth: " << pen.width() << "\n";
    outFile << "PenStyle: " << penStyle(pen) << "\n";
    outFile << "PenCapStyle: " << penCapStyle(pen) << "\n";
    outFile << "PenJoinStyle: " << penJoinStyle(pen) << "\n";
    return;
}

//! Output brush function
/*!
* Pre: Shape in vector passed
* Post: Brush color, style written to file
*/
void OutputBrush(std::ofstream& outFile, const Shape<int>* shape)
{
    QBrush brush = shape->getBrush(); //< Get brush from given shape
    outFile << "BrushColor: " << brushColor(brush) << "\n";
    outFile << "BrushStyle: " << brushStyle(brush) << "\n";
    return;
}


//! Pen color function
/*!
 * Pre: Pen passed
 * Post: String of pen color returned
 */
std::string penColor(const QPen pen)
{
    QColor color = pen.color();
    const QMap<QString, std::string> colorMap {
        {"#ffffff", "white"},
        {"#000000", "black"},
        {"#ff0000", "red"},
        {"#00ff00", "green"},
        {"#0000ff", "blue"},
        {"#00ffff", "cyan"},
        {"#ff00ff", "magenta"},
        {"#ffff00", "yellow"},
        {"#a0a0a4", "gray",}
    };
    return colorMap.value(color.name());
}

//! Pen style function
/*!
 * Pre: Pen passed
 * Post: String of pen style returned
 */
std::string penStyle(const QPen pen)
{
    const QMap<Qt::PenStyle, std::string> styleMap
        {
         {Qt::NoPen, "NoPen"},
         {Qt::SolidLine, "SolidLine"},
         {Qt::DashLine, "DashLine"},
         {Qt::DotLine, "DotLine"},
         {Qt::DashDotLine, "DashDotLine"},
         {Qt::DashDotDotLine, "DashDotDotLine"},
         };
    return styleMap.value(pen.style());
}

//! Pen cap style function
/*!
 * Pre: Pen passed
 * Post: String of pen cap style returned
 */
std::string penCapStyle(const QPen pen)
{
    const QMap<Qt::PenCapStyle, std::string> capMap
        {
         {Qt::SquareCap, "SquareCap"},
         {Qt::FlatCap, "FlatCap"},
         {Qt::RoundCap, "RoundCap"},
         };
    return capMap.value(pen.capStyle());
}

//! Pen join style function
/*!
 * Pre: Pen passed
 * Post: String of pen join style returned
 */
std::string penJoinStyle(const QPen pen)
{
    const QMap<Qt::PenJoinStyle, std::string> joinMap
        {
         {Qt::BevelJoin, "BevelJoin"},
         {Qt::MiterJoin, "MiterJoin"},
         {Qt::RoundJoin, "RoundJoin"},
         };
    return joinMap.value(pen.joinStyle());
}

//! Brush color function
/*!
 * Pre: Brush passed
 * Post: String of brush color returned
 */
std::string brushColor(const QBrush brush)
{
    QColor color = brush.color();
    const QMap<QString, std::string> colorMap {
        {"#ffffff", "white"},
        {"#000000", "black"},
        {"#ff0000", "red"},
        {"#00ff00", "green"},
        {"#0000ff", "blue"},
        {"#00ffff", "cyan"},
        {"#ff00ff", "magenta"},
        {"#ffff00", "yellow"},
        {"#a0a0a4", "gray",}
    };
    return colorMap.value(color.name());
}

//! Brush style function
/*!
 * Pre: Brush passed
 * Post: String of brush style returned
 */
std::string brushStyle(const QBrush brush)
{
    const QMap<Qt::BrushStyle, std::string> brushStyleMap
        {
         {Qt::NoBrush, "NoBrush"},
         {Qt::SolidPattern, "SolidPattern"},
         {Qt::Dense1Pattern, "Dense1Pattern"},
         {Qt::Dense2Pattern, "Dense2Pattern"},
         {Qt::Dense3Pattern, "Dense3Pattern"},
         {Qt::Dense4Pattern, "Dense4Pattern"},
         {Qt::Dense5Pattern, "Dense5Pattern"},
         {Qt::Dense6Pattern, "Dense6Pattern"},
         {Qt::Dense7Pattern, "Dense7Pattern"},
         {Qt::HorPattern, "HorPattern"},
         {Qt::VerPattern, "VerPattern"},
         {Qt::CrossPattern, "CrossPattern"},
         {Qt::BDiagPattern, "BDiagPattern"},
         {Qt::FDiagPattern, "FDiagPattern"},
         {Qt::DiagCrossPattern, "DiagCrossPattern"},
         {Qt::LinearGradientPattern, "LinearGradientPattern"},
         {Qt::ConicalGradientPattern, "ConicalGradientPattern"},
         {Qt::RadialGradientPattern, "RadialGradientPattern"},
         {Qt::TexturePattern, "TexturePattern"},
         };

    return brushStyleMap.value(brush.style());
}

