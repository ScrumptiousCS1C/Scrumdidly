#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
private:
    QLine line;  // Private variable specific to Line

public:
    //**********************************************************************
    // Constructors
    //______________________________________________________________________
    // Default constructor initializes a sample line
    // Another constructor allows creating a line with different dimensions
    //**********************************************************************
    Line(QPoint p1, QPoint p2);
    Line();
    Line(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush);

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the line using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override;

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the line by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override;
    //**********************************************************************
    // getLine() const
    //______________________________________________________________________
    // Pre: Obj exists
    // Post: Returns const ref to internal QLine obj
    //**********************************************************************
    const QLine& getLine() const
    {
        return line;
    }
    //**********************************************************************
};

#endif // LINE_H

