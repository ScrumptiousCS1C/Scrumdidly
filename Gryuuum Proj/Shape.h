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
#include "Vector.h"
#include <fstream>

class Shape {
public:
    // Enumeration defining different shape types
    enum ShapeType {empty, Line, polyline, polygon, rectangle, ellipse, text};

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
    QBrush getBrush() const {return brush;}




    //**********************************************************************
    // getQPainter()
    //______________________________________________________________________
    // Pre: Object must exist
    // Post: Returns const reference to QPainter object
    //**********************************************************************
    QPainter &getQPainter() const {return *painter;}

    //**********************************************************************
    // Setters
    //**********************************************************************

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
    void setPenColor(const QColor &color) {painter->setPen(color);}
    //**********************************************************************
    // setStyle(const Qt::PenStyle style)
    //______________________________________________________________________
    // Pre: Object exists, Qt::PenStyle style is passed in
    // Post: Painter's pen style is set to style
    //**********************************************************************
    void setStyle(const Qt::PenStyle style) {painter->setPen(style);}

    //**********************************************************************
    // setBrush(const QBrush &brush)
    //______________________________________________________________________
    // Pre: Object exists, QBrush brush is passed in
    // Post: Painter's brush is set to brush
    //**********************************************************************
    void setBrush(const QBrush &newbrush) {brush = newbrush;}

    //**********************************************************************
    // setBrushColor(const Qt::BrushStyle style)
    //______________________________________________________________________
    // Pre: Object exists, Qt::BrushStyle style is passed in
    // Post: Painter's brush color is set to style
    //**********************************************************************
    void setBrushColor(const Qt::BrushStyle style) {painter->setBrush(style);}






    ;

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
protected:
    QPainter *painter; //  unique pt                              // Pointer to QPainter object
    QBrush brush;
    QPen pen;
};

#endif // SHAPE_H


