#ifndef LINE_H
#define LINE_H

#include "Shape.h"
template<typename T>
class Line : public Shape<T> {
private:
    QLine line;  // Private variable specific to Line

public:
    //**********************************************************************
    // Constructors
    //______________________________________________________________________
    // Default constructor initializes a sample line
    // Another constructor allows creating a line with different dimensions
    //**********************************************************************
    Line(QPoint p1, QPoint p2)
        : Shape<T>(1, Shape<T>::ShapeType::line)
    {
        line.setP1(p1);
        line.setP2(p2);
    }

    Line() : Shape<T>(1, Shape<T>::ShapeType::line)
    {
        line = QLine(QPoint(20,90), QPoint(100, 20));
    }


    Line(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush)
        : Shape<T>(id, Shape<T>::ShapeType::line, pen, brush)
    {
        line.setP1(p1);
        line.setP2(p2);
    }


    // parser constructor
    Line(int i, typename Shape<T>::ShapeType shapeT, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(i, shapeT, dimensions, pen)
    {
        line = QLine(dimensions[0], dimensions[1]);
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the line using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override
    {

        if (externalPainter) {
            this->painter = externalPainter;
        }
        // Draws the line using the specified QPainter and dimensions
        this->painter->setPen(this->getPen());
        this->painter->setBrush(this->getBrush());
        this->painter->drawLine(line);
    }

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the line by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override
    {
        // Moves the line by the specified translationVector
        line.translate(translationVector.x(), translationVector.y());
    }
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

