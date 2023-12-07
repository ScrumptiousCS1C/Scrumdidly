#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"
#include <QPolygon>

class Polyline : public Shape {
private:
    // Private variable specific to Polyline
    QPolygon polyline;

public:
    //**********************************************************************
    // Constructors
    //______________________________________________________________________
    // Default constructor initializes a sample polyline
    // Other constructors allow creating polylines with different dimensions
    //**********************************************************************
    Polyline()
        : Shape() {
        // Add sample points to the polyline
        polyline << QPoint(100, 80)
                 << QPoint(150, 130)
                 << QPoint(200, 80);
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3;
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3, QPoint p4)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3 << p4;
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3 << p4 << p5;
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3 << p4 << p5 << p6;
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3 << p4 << p5 << p6 << p7;
    }

    Polyline(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7, QPoint p8)
        : Shape(2, ShapeType::polyline) {
        polyline << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polyline using the specified QPainter and dimensions
    //**********************************************************************
    void draw() override {
        painter->drawPolyline(polyline);
    }

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polyline by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override {
        polyline.translate(translationVector.x(), translationVector.y());
    }

    //**********************************************************************
    // getPolyline() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polyline
    //**********************************************************************
    QPolygon getPolyline() const {
        return polyline;
    }

    //**********************************************************************
    // setPolyline(const QPolygon& newPolyline)
    //______________________________________________________________________
    // Pre: Object exists, newPolyline is a valid QPolygon
    // Post: Sets the polyline to newPolyline
    //**********************************************************************
    void setPolyline(const QPolygon& newPolyline) {
        polyline = newPolyline;
    }
};

#endif // POLYLINE_H
