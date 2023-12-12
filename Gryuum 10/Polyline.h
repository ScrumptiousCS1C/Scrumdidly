#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"
#include <QPolygon>
#include <QList>

template<typename T>
class Polyline : public Shape<T> {
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
    Polyline(): Shape<T>()
    {
        polyline << QPoint(100, 80) << QPoint(150, 130) << QPoint(200, 80);
    }

    // Constructor taking Vector<QPoint>
    Polyline(const scrumptious::Vector<QPoint>& pointsVector)
        : Shape<T>(3, Shape<T>::ShapeType::polyline)
    {
        for (int i = 0; i < pointsVector.sizeOf(); ++i)
        {
            polyline << pointsVector[i];
        }
    }
    //overloaded constructor taking QList of QPoints
    Polyline(const QList<QPoint>& points, int id, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, Shape<T>::ShapeType::polyline, dimensions, pen)
    {
        polyline = QPolygon(points);
    };

    // parser constructor
    Polyline(int id, typename Shape<T>::ShapeType type,
             const scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, type, dimensions, pen)
    {
        QList<QPoint> points =
        {
            QPoint(dimensions[0], dimensions[1]),
            QPoint(dimensions[2], dimensions[3]),
            QPoint(dimensions[4], dimensions[5]),
            QPoint(dimensions[6], dimensions[7])
        };
        polyline = QPolygon(points);
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polyline using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override
    {

        if (externalPainter) {
            this->painter = externalPainter;
        }
        this->painter->setPen(this->getPen());
        this->painter->setBrush(this->getBrush());
        this->painter->drawPolyline(polyline);
    };

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polyline by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override
    {
        polyline.translate(translationVector.x(), translationVector.y());
    };

    //**********************************************************************
    // getPolyline() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polyline
    //**********************************************************************
    QPolygon getPolyline() const
    {
        return polyline;
    };

    //**********************************************************************
    // setPolyline(const QPolygon& newPolyline)
    //______________________________________________________________________
    // Pre: Object exists, newPolyline is a valid QPolygon
    // Post: Sets the polyline to newPolyline
    //**********************************************************************
    void setPolyline(const QPolygon& newPolyline)
    {
        polyline = newPolyline;
    };
};

#endif // POLYLINE_H

