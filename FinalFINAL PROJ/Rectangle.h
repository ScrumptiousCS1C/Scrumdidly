#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

template<typename T>
class Rectangle : public Shape<T> {
private:
    QRect rect;  // Private variable specific to Rectangle

public:
    // Constructor
    Rectangle(QPoint p1, QPoint p2)
        : Shape<T>(4, Shape<T>::ShapeType::rectangle)
    {
        rect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
    }

    Rectangle(QPoint p1, QPoint p2, int id, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, Shape<T>::ShapeType::rectangle, dimensions, pen)
    {
        rect = QRect(p1, p2);
    }

    // Parser Constructor
    Rectangle(int id, typename Shape<T>::ShapeType type, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, type, dimensions, pen)
    {
        rect = QRect(dimensions[0], dimensions[1],
                     dimensions[2], dimensions[3]);
    }


    // Overloaded Constructor with default values
    Rectangle():
        rect(QRect(30, 40, 50, 30)),
        Shape<T>(4, Shape<T>::ShapeType::rectangle) {}

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: The Object's painter should be set first
    //
    // Post: Draws the rectangle using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override
    {

        if (externalPainter) {
            this->painter = externalPainter;
        }
        // Draw the rectangle using the QRect dimensions
        this->painter->setPen(this->getPen());
        this->painter->setBrush(this->getBrush());
        this->painter->drawRect(rect);
    }
    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the rectangle by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override
    {
        rect.translate(translationVector.x(), translationVector.y());
    }

    // Additional functions specific to Rectangle class, if needed

    //**********************************************************************
    // getRectangle() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the rectangle dimensions
    //**********************************************************************
    QRect getRectangle() const
    {
        return rect;
    }

    //**********************************************************************
    // setRectangle(const QRect& newRect)
    //______________________________________________________________________
    // Pre: Object exists, newRect is a valid QRect
    // Post: Sets the rectangle dimensions to newRect
    //**********************************************************************
    void setRectangle(const QRect& newRect)
    {
        rect = newRect;
    }

    double area(){
        return rect.height()*rect.width();
    }

    double perimeter(){
        return 2*(rect.height() + rect.width());
    }
};

#endif // RECTANGLE_H
