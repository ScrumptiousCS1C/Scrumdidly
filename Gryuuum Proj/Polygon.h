#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <QPolygon>

class Polygon : public Shape {
private:
    // Private variable specific to Polygon
    QPolygon polygon;

public:
    //**********************************************************************
    // Constructors
    //______________________________________________________________________
    // Default constructor initializes a sample polygon
    // Other constructors allow creating polygons with different dimensions
    //**********************************************************************
    Polygon()
        : Shape() {
        // Add sample points to the polygon
        polygon << QPoint(300, 200)
                << QPoint(400, 150)
                << QPoint(500, 200)
                << QPoint(475, 300)
                << QPoint(375, 300);
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3;
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3, QPoint p4)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3 << p4;
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3 << p4 << p5;
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3 << p4 << p5 << p6;
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3 << p4 << p5 << p6 << p7;
    }

    Polygon(QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7, QPoint p8)
        : Shape(3, ShapeType::polygon) {
        polygon << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polygon using the specified QPainter and dimensions
    //**********************************************************************
    void draw() override {
        painter->drawPolygon(polygon);
    }

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polygon by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override {
        polygon.translate(translationVector.x(), translationVector.y());
    }

    //**********************************************************************
    // getPolygon() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polygon
    //**********************************************************************
    QPolygon getPolygon() const {
        return polygon;
    }

    //**********************************************************************
    // setPolygon(const QPolygon& newPolygon)
    //______________________________________________________________________
    // Pre: Object exists, newPolygon is a valid QPolygon
    // Post: Sets the polygon to newPolygon
    //**********************************************************************
    void setPolygon(const QPolygon& newPolygon) {
        polygon = newPolygon;
    }
};

#endif // POLYGON_H
