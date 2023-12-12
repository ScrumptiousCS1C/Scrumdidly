#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <Qt>
#include <QRect>
#include <string>
#include "vector.h"
#include <fstream>

template<typename T>
class Shape {
public:
    // Enumeration defining different shape types
    enum ShapeType {empty, line, polyline, polygon, rectangle, square, ellipse, circle, text};

    //**********************************************************************
    // Default Constructor
    //______________________________________________________________________
    // Pre: none
    // Post: Shape object is initialized in heap with default values
    //**********************************************************************
    Shape() : id{0}, shapeType{empty} {}

    //**********************************************************************
    // Overloaded Constructor
    //______________________________________________________________________
    // Pre: Object must exist
    // Post: Shape object is initialized with specified ID and type
    //**********************************************************************
    Shape(int i, ShapeType t): id{i}, shapeType{t}{}

    Shape(int i, ShapeType t, QPen nPen, QBrush nBrush) :
        id{i}, shapeType{t}, pen{nPen}
    {
        pen.setBrush(nBrush);
    }

    Shape(int i, scrumptious::Vector<T> shapeDim, QPen nPen) : id{i}, shapeDimensions{shapeDim}, pen{nPen} {}

    // parser constructor
    Shape(int i, ShapeType type, scrumptious::Vector<T> shapeDim, QPen nPen)
        : id{i}, shapeType{type}, shapeDimensions{shapeDim}, pen{nPen}{}

    // Destructor
    //**********************************************************************
    // Pre: Object must exist
    // Post: Shape object is deleted
    //**********************************************************************
    virtual ~Shape() {}

    //**********************************************************************
    // Getters
    //**********************************************************************

    //**********************************************************************
    // getShapeType()
    //______________________________________________________________________
    // Pre: Object must be initialized
    // Post: Returns the shape type of the object
    //**********************************************************************
    ShapeType getShapeType() const {return shapeType;}

    //**********************************************************************
    // getId()
    //______________________________________________________________________
    // Pre: Object must be initialized
    // Post: Returns the ID of the object
    //**********************************************************************
    int getId() const{return id;}

    //**********************************************************************
    // getPen()
    //______________________________________________________________________
    // Pre: Object must be initialized (painter != nullptr)
    // Post: Returns const reference to painter's QPen
    //**********************************************************************
    QPen getPen() const {return pen;}
    //**********************************************************************
    // getBrush()
    //______________________________________________________________________
    // Pre: Object must be initialized (painter != nullptr)
    // Post: Returns const reference to painter's QBrush
    //**********************************************************************
    QBrush getBrush() const {return pen.brush();}

    //**********************************************************************
    // getQPainter()
    //______________________________________________________________________
    // Pre: Object must exist
    // Post: Returns const reference to QPainter object
    //**********************************************************************
    QPainter &getQPainter() const {return *painter;}
    //**********************************************************************
    T getPoint(int n) const {return shapeDimensions[n];}
    // Setters
    //**********************************************************************
    void setDimension(const T n) {shapeDimensions.push_back(n);}

    //**********************************************************************
    // setId(const int i)
    //______________________________________________________________________
    // Pre: Object exists, int i is passed in
    // Post: Shape ID is set to i
    //**********************************************************************
    void setId(const int i) { id = i; }

    //**********************************************************************
    // setShapeType(const ShapeType s)
    //______________________________________________________________________
    // Pre: Object exists, ShapeType s is passed in
    // Post: Shape type is set to s
    //**********************************************************************
    void setShapeType(const ShapeType s) {shapeType = s;}

    //**********************************************************************
    // setPen(const QPen &pen)
    //______________________________________________________________________
    // Pre: Object exists, QPen pen is passed in
    // Post: Painter's pen is set to pen
    //**********************************************************************
    void setPen(const QPen &pen1) {pen = pen1;}

    //**********************************************************************
    // setPenColor(const QColor &color)
    //______________________________________________________________________
    // Pre: Object exists, QColor color is passed in
    // Post: Painter's pen color is set to color
    //**********************************************************************
    void setPenColor(const QColor &color) {pen.setColor(color);}
    //**********************************************************************
    // setStyle(const Qt::PenStyle style)
    //______________________________________________________________________
    // Pre: Object exists, Qt::PenStyle style is passed in
    // Post: Painter's pen style is set to style
    //**********************************************************************
    void setPenStyle(const Qt::PenStyle style) {pen.setStyle(style);}

    void setPenJoinStyle(const Qt::PenJoinStyle style) {pen.setJoinStyle(style);}

    void setPenWidth(const int width) {pen.setWidth(width);}

    //**********************************************************************
    // setBrush(const QBrush &brush)
    //______________________________________________________________________
    // Pre: Object exists, QBrush brush is passed in
    // Post: Painter's brush is set to brush
    //**********************************************************************
    void setBrush(const QBrush &newbrush) {pen.setBrush(newbrush);}

    //**********************************************************************
    // setBrushColor(const Qt::BrushStyle style)
    //______________________________________________________________________
    // Pre: Object exists, Qt::BrushStyle style is passed in
    // Post: Painter's brush color is set to style
    //**********************************************************************
    void setBrushColor(const Qt::GlobalColor style)
    {
        QBrush brush = pen.brush();
        brush.setColor(style);
        pen.setBrush(brush);
    }
    //**********************************************************************
    void setBrushStyle(const Qt::BrushStyle style)
    {
        QBrush brush = pen.brush();
        brush.setStyle(style);
        pen.setBrush(brush);
    }
    //**********************************************************************
    void setCapStyle(const Qt::PenCapStyle style) {pen.setCapStyle(style);}
    //**********************************************************************
    // Functionality
    //**********************************************************************

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Pure virtual function, draws for every subclass in shape hierarchy
    //**********************************************************************
    virtual void draw(QPainter *externalPainter) = 0;

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, QPoint translationVector is passed in
    // Post: Pure virtual function, moves shape to the desired location
    //**********************************************************************
    virtual void move(const QPoint& translationVector) = 0;
    //**********************************************************************
    // string getShapeTypeString() const
    //______________________________________________________________________
    //
    //
    //**********************************************************************
    QString getShapeTypeString() const
    {
        switch(shapeType)
        {
        case empty:
            return "empty";
        case line:
            return "Line";
        case polyline:
            return "Polyline";
        case polygon:
            return "Polygon";
        case rectangle:
            return "Rectangle";
        case square:
            return "Square";
        case ellipse:
            return "Ellipse";
        case circle:
            return "Circle";
        case text:
            return "Text";
        }
    }
private:
    // NOTE:
    // Is an individual data member needed for each instance of data received from the parser,
    // or by aggregating a QPainter object to our shape object, would we be allocating unnecessary memory
    // and creating a slower, less reliable program.
    //
    // If our program is reaching to multiple places to try to find the same data, this could lead to memory leaks,
    // program crashes, and other problems.
    //
    // -- Gryuuum
    //
    int id;                                         // Shape ID
    ShapeType shapeType;                            // Shape Type enum
    scrumptious::Vector<T> shapeDimensions;    // Vector of shape dimensions
    QPen pen;
protected:
    QPainter *painter;                        // Pointer to QPainter object
};

#endif // SHAPE_H


