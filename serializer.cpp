#include <iostream>
#include <fstream>
#include <string>
#include <QMap>
#include <QPen>
#include <QBrush>
#include <limits>
#include <QDebug>
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"
#include "Serializer.h"
#include "vector.h"

// Shape output functions
void OutputLine(Shape* shape);
void OutputPolyLine(Shape* shape);
void OutputPolygon(Shape* shape);
void OutputRectangle(Shape* shape); // Rectangle and Square
void OutputEllipse(Shape* shape); // Ellipse and Circle
void OutputText(Shape* shape);

// Pen, brush output functions
void OutputPen(Shape* shape);
void OutputBrush(Shape* shape);

// Convert shape name to string function
std::string ShapeName(Shape* shape);

// Convert pen, brush info to string functions

std::string penColor(QPen pen);
std::string penStyle(QPen pen);
std::string penCapStyle(QPen pen);
std::string penJoinStyle(QPen pen);
std::string brushColor(QBrush brush);
std::string brushStyle(QBrush brush);

//! Serializer function
/*!
* Saves shapes to custom specified file path and file name
* Pre: File name passed, File path passed, Vector of shapes passed
* Post: Saves file with info of all shapes to specified file path with specified file name
*/
void serializer(std::string fileName, std::string filePath, scrumptious::vector<Shape*>* myShapes) const
{
    std::string pathName = filePath + fileName + ".txt"; ///< Create custom file name with custom file path
    std::ofstream outfile(pathName); ///< Create and open file

    Shape* shape; ///< Shape base class pointer

    for (scrumptious::vector<Shape*>::iterator it = myShapes.begin(); it != myShapes.end(); it++) ///< Traverse through each item in the vector
    {
        shape = &myShapes[i]; ///< Assign shape to pointer
        switch (shape->getShapeType()) ///< Read in the shape type, switch statement to call specific
        {
        case Line:
            OutputLine(shape);
            break;
        case polyline:
            OutputPolyline(shape);
            break;
        case polygon:
            OutputPolygon(shape);
            break;
        case rectangle:
            OutputRectangle(shape);
            break;
        case ellipse:
            OutputEllipse(shape);
            break;
        case text:
            OutputText(shape);
            break;
        case empty:
        default:
            break;
        };
        return;
    }
    outfile.close(); //< Close file
    // Exit file
    return;
}

//! Output line function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info written to file
*/
void OutputLine(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    OutputPen(Shape* shape);
    outfile << "\n";
    return;
}

//! Output polyline function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info written to file
*/
void OutputPolyLine(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    OutputPen(shape);
    outfile << "\n";
    return;
}

//! Output polygon function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputPolygon(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    OutputPen(shape);
    OutputBrush(shape);
    outfile << "\n";
    return;
}

//! Output rectangle function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputRectangle(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    OutputPen(shape);
    OutputBrush(shape);
    outfile << "\n";
    return;
}

//! Output ellipse function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputEllipse(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    OutputPen(shape);
    OutputBrush(shape);
    outfile << "\n";
    return;
}

//! Output text function
/*!
* Pre: Shape in vector passed
* Post: ID, Type, Dimensions, Pen info, Brush info written to file
*/
void OutputText(Shape* shape) const
{
    outFile << "ShapeID: " << shape->getId() << "\n";
    outFile << "ShapeType: " << ShapeName(shape) << "\n";
    outFile << "ShapeDimensions: " << << "\n"; // Fix
    // Text info here
    outfile << "\n";
    return;
}



//! Output pen function
/*!
* Pre: Shape in vector
* Post: Pen color, width, style, cap style, join style written to file
*/
void OutputPen(Shape* shape) const
{
    QPen pen = shape->getPen(); //< Get pen from given shape


    outFile << "PenColor: " << penColor(pen) << "\n"; // Convert to string later
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
void OutputBrush(Shape* shape) const
{
    QBrush brush = shape->getBrush(); //< Get brush from given shape


    outFile << "BrushColor: " << brushColor(brush) << "\n"; // Convert to string later
    outFile << "BrushStyle: " << brushStyle(brush) << "\n";
    return;
}

//! Shape name function
/*!
* Pre: Shape in vector passed
* Post: Shape type of shape passed as a string
*/
std::string ShapeName(Shape* shape) const
{
    switch (shape->getShapeType())
    {
    case Line:
        return "Line";
    case polyline:
        return "Polyline";
    case polygon:
        return "Polygon";
    case rectangle:
        return "Rectangle";
    case ellipse:
        return "Ellipse";
    case text:
        return "Text";
    case empty:
    default:
        return "Empty";
    }
}


std::string penColor(QPen pen) const
{

}

std::string penStyle(QPen pen) const
{

}

std::string penCapStyle(QPen pen) const
{

}

std::string penJoinStyle(QPen pen) const
{

}

std::string brushColor(QBrush brush) const
{

}

std::string brushStyle(QBrush brush)
{

}
