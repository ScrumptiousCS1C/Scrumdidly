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
    Polygon();
    // Constructor taking Vector<QPoint>
    Polygon(const scrumptious::Vector<QPoint>& pointsVector);

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polygon using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override;

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polygon by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override;

    //**********************************************************************
    // getPolygon() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polygon
    //**********************************************************************
    QPolygon getPolygon() const;

    //**********************************************************************
    // setPolygon(const QPolygon& newPolygon)
    //______________________________________________________________________
    // Pre: Object exists, newPolygon is a valid QPolygon
    // Post: Sets the polygon to newPolygon
    //**********************************************************************
    void setPolygon(const QPolygon& newPolygon);
};

#endif // POLYGON_H



