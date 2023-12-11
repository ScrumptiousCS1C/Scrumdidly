#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"
#include <QPolygon>
#include <QList>

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
    Polyline();
    // Constructor taking Vector<QPoint>
    Polyline(const scrumptious::Vector<QPoint>& pointsVector);
    //overloaded constructor taking QList of QPoints
    Polyline(const QList<QPoint>& points, int id, QPen pen, QBrush brush);

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polyline using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override;

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polyline by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override;

    //**********************************************************************
    // getPolyline() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polyline
    //**********************************************************************
    QPolygon getPolyline() const;

    //**********************************************************************
    // setPolyline(const QPolygon& newPolyline)
    //______________________________________________________________________
    // Pre: Object exists, newPolyline is a valid QPolygon
    // Post: Sets the polyline to newPolyline
    //**********************************************************************
    void setPolyline(const QPolygon& newPolyline);
};

#endif // POLYLINE_H

