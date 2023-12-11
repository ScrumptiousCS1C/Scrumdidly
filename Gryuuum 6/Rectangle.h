#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    QRect rect;  // Private variable specific to Rectangle

public:
    // Constructor
    Rectangle(QPoint p1, QPoint p2);

    Rectangle(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush);

    // Overloaded Constructor with default values
    Rectangle();

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: The Object's painter should be set first
    //
    // Post: Draws the rectangle using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override;

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the rectangle by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override;

    // Additional functions specific to Rectangle class, if needed

    //**********************************************************************
    // getRectangle() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the rectangle dimensions
    //**********************************************************************
    QRect getRectangle() const;

    //**********************************************************************
    // setRectangle(const QRect& newRect)
    //______________________________________________________________________
    // Pre: Object exists, newRect is a valid QRect
    // Post: Sets the rectangle dimensions to newRect
    //**********************************************************************
    void setRectangle(const QRect& newRect);
};

#endif // RECTANGLE_H
