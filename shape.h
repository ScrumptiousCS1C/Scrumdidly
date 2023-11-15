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
#include "vector.h"
#include <string>
#include <fstream>

class Shape {
    //
    // global enum within scope of shape base class to define shape types recieved from parser
    // consider making first value "blank" to reflect 0 R value
    //
    // --Spencer Glenn (Gryuuum)
    enum ShapeType {empty, Line, polyline, polygon, rectangle, square, ellipse, circle};
    //

private:
    // NOTE:
    // Is an individual data member needed for each instance of data recieved from the parser,
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
    scrumptious::Vector<QPoint> shapeDimensions;    // pointer array to vector of Qpoints
    QPainter *painter;  // make unique pt                              // Pointer to Qpainter object

public:
    //**********************************************************************
    // Default Constructor
    //______________________________________________________________________
    // Pre: none
    // Post: Shape object is initialized in heap with default values
    //**********************************************************************
    Shape() : id{0}, shapeType{empty}, shapeDimensions{}, painter{new QPainter} {}
    //**********************************************************************
    //Shape() : id{}, shapeType{}, shapeDimenstion{}, painter{} {};
    //**********************************************************************
    // Destructor
    //**********************************************************************
    // Pre: Object must exist
    // Post: Shape object is deleted
    //**********************************************************************
    virtual ~Shape() {}
    //**********************************************************************
    // Getters
    //**********************************************************************
    // getShapeType()
    //______________________________________________________________________
    // Pre: Object must be initialized
    // Post: shapetype is returned
    //**********************************************************************
    ShapeType getShapeType() const {return shapeType;}
    //**********************************************************************
    // getId()
    //______________________________________________________________________
    // Pre: Object must be initialized
    // Post: shapetype is returned
    //**********************************************************************
    int getId() const{return id;}
    //**********************************************************************
    // getPen()
    //______________________________________________________________________
    // Pre: Object must be initialized (painter != nullptr)
    // Post: Returns const reference to painter's Qpen
    //**********************************************************************
    QPen getPen() const {return painter->pen();}
    //**********************************************************************
    // getBrush()
    //______________________________________________________________________
    // Pre: Object must be initialized (painter != nullptr)
    // Post: Returns const reference to painter's Qpen
    //**********************************************************************
    QBrush getBrush() const {return painter->brush();}
    //**********************************************************************
    // &getQPainter()
    //______________________________________________________________________
    // Pre: Object must exist
    // Post: Returns const reference to QPainter object
    //**********************************************************************
    QPainter &getQPainter() const {return *painter;}
    //**********************************************************************
    // Setters
    //**********************************************************************
    // setId(const int i)
    //______________________________________________________________________
    // Pre: Object exists int is passed in
    // Post: Shape iD = i
    //**********************************************************************
    void setId(const int i) { id = i; }
    //**********************************************************************
    // setShapeType(const ShapeType s)
    //______________________________________________________________________
    // Pre: Obejct exists ShapeType is passed in
    // Post: Shape shapeType = s
    //**********************************************************************
    void setShapeType(const ShapeType s) {shapeType = s;}
    //**********************************************************************
    // setPen(const QPen &pen)
    //______________________________________________________________________
    // Pre: Object exists Qpen passed in
    // Post: Painter's pen = pen
    //**********************************************************************
    void setPen(const QPen &pen) {painter->setPen(pen);}
    //**********************************************************************
    // setPenColor(const Qcolor &color)
    //______________________________________________________________________
    // Pre: Object exists Qcolor passed in
    // Post: Painter's pen color = pen
    //**********************************************************************
    void setPenColor(const QColor &color) {painter->setPen(color);}
    //**********************************************************************
    // setStyle(const Qt::Penstyle style)
    //______________________________________________________________________
    // Pre: Object exists Qt::Penstyle passed in
    // Post: Painter's penStyle = style
    //**********************************************************************
    void setStyle(const Qt::PenStyle style) {painter->setPen(style);}
    //**********************************************************************
    // setBrush(const QBrush &brush)
    //______________________________________________________________________
    // Pre: Object exists QBrush passed in
    // Post: Painter's brush = brush
    //**********************************************************************
    void setBrush(const QBrush &brush) {painter->setBrush(brush);}
    //**********************************************************************
    // setBrushColor(const Qt::BrushStyle style)
    //______________________________________________________________________
    // Pre: Object exists Qt::BrushStyle passed in
    // Post: Painters brush color = style
    //**********************************************************************
    void setBrushColor(const Qt::BrushStyle style) {painter->setBrush(style);}
    //**********************************************************************
    // Functionality
    //**********************************************************************
    // draw() = 0
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Pure virtual function, draws for every subclass in shape hierarchy
    //**********************************************************************
    virtual void draw() = 0;
    //**********************************************************************
    // move(scrumptious::Vector<QPoint> coordinates[]) = 0
    //______________________________________________________________________
    // Pre: Object exists, vector of Q points is passed int
    // Post: Pure virtual function, moves shape to desired location
    //**********************************************************************
    virtual void move(scrumptious::Vector<QPoint> coordinates[]) = 0;
    //**********************************************************************
    // getStartPoint()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns start point for shape render
    //**********************************************************************
    virtual QPoint getStartPoint() {return *shapeDimensions.begin();}
    //**********************************************************************
    // getEndPoint()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns end point for shape render
    //**********************************************************************
    virtual QPoint getEndPoint() {return *shapeDimensions.end();}
    //**********************************************************************
    // &getCords()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns vector of QPoints for shape
    //**********************************************************************
    virtual scrumptious::Vector<QPoint> &getCords() {return shapeDimensions;}
    //**********************************************************************
};
#endif // SHAPE_H
