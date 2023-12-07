#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
private:
    QLineF line;  // Private variable specific to Line

public:
    //**********************************************************************
    // Constructors
    //______________________________________________________________________
    // Default constructor initializes a sample line
    // Another constructor allows creating a line with different dimensions
    //**********************************************************************
    Line(QPoint p1, QPoint p2)
        : Shape(1, ShapeType::Line) {
        line.setP1(p1);
        line.setP2(p2);
    }

    Line()
        : Shape() {
        line.setP1(QPoint(12, 90));
        line.setP2(QPoint(45, 67));
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the line using the specified QPainter and dimensions
    //**********************************************************************
    void draw() override {
        painter->drawLine(line);
    }

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the line by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override {
        line.translate(translationVector.x(), translationVector.y());
    }
};

#endif // LINE_H
