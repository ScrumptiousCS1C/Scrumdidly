#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    QRect rect;  // Private variable specific to Rectangle

public:
    // Constructor
    Rectangle(QPoint p1, QPoint p2)
        : Shape(4, ShapeType::rectangle) {
        rect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
    }

    // Overloaded Constructor with default values
    Rectangle()
        : rect(QRect(30, 40, 50, 30)), Shape(4, ShapeType::rectangle) {}

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: The Object's painter should be set first
    //
    // Post: Draws the rectangle using the specified QPainter and dimensions
    //**********************************************************************
    void draw() override {
        // Draw the rectangle using the QRect dimensions
        painter->drawRect(rect);
    }

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the rectangle by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override {
        rect.translate(translationVector.x(), translationVector.y());
    }

    // Additional functions specific to Rectangle class, if needed

    //**********************************************************************
    // getRectangle() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the rectangle dimensions
    //**********************************************************************
    QRect getRectangle() const {
        return rect;
    }

    //**********************************************************************
    // setRectangle(const QRect& newRect)
    //______________________________________________________________________
    // Pre: Object exists, newRect is a valid QRect
    // Post: Sets the rectangle dimensions to newRect
    //**********************************************************************
    void setRectangle(const QRect& newRect) {
        rect = newRect;
    }
};

#endif // RECTANGLE_H
