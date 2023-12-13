#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <QPolygon>

template<typename T>
class Polygon : public Shape<T> {
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
    {
        // Add sample points to the polygon
        polygon << QPoint(300, 200)
                << QPoint(400, 150)
                << QPoint(500, 200)
                << QPoint(475, 300)
                << QPoint(375, 300);
    };
    // Constructor taking Vector<QPoint>
    Polygon(const scrumptious::Vector<QPoint>& pointsVector)
        : Shape<T>(3, Shape<T>::ShapeType::polygon)
    {
        for (int i = 0; i < pointsVector.sizeOf(); ++i) {
            polygon << pointsVector[i];
        }
    }


    Polygon(const QList<QPoint>& points, int id, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, Shape<T>::ShapeType::polygon, dimensions, pen)
    {
        polygon = QPolygon(points);
    }

    // parser constructor
    Polygon(int id, typename Shape<T>::ShapeType type, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, type, dimensions, pen)
    {   QList<QPoint> list = {
        QPoint(dimensions[0], dimensions[1]),
        QPoint(dimensions[2], dimensions[3]),
        QPoint(dimensions[4], dimensions[5]),
        QPoint(dimensions[6], dimensions[7])
        };

        polygon = QPolygon(list);
    }

    //**********************************************************************
    // draw()
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Draws the polygon using the specified QPainter and dimensions
    //**********************************************************************
    void draw(QPainter *externalPainter) override
    {

        if (externalPainter) {
            this->painter = externalPainter;
        }
        this->painter->setPen(this->getPen());
        this->painter->setBrush(this->getBrush());
        this->painter->drawPolygon(polygon);
    };

    //**********************************************************************
    // move(const QPoint& translationVector)
    //______________________________________________________________________
    // Pre: Object exists, translationVector is a valid QPoint
    // Post: Moves the polygon by the specified translationVector
    //**********************************************************************
    void move(const QPoint& translationVector) override
    {
        polygon.translate(translationVector.x(), translationVector.y());
    };

    //**********************************************************************
    // getPolygon() const
    //______________________________________________________________________
    // Pre: Object exists
    // Post: Returns the QPolygon representing the polygon
    //**********************************************************************
    QPolygon getPolygon() const
    {
        return polygon;
    };

    //**********************************************************************
    // setPolygon(const QPolygon& newPolygon)
    //______________________________________________________________________
    // Pre: Object exists, newPolygon is a valid QPolygon
    // Post: Sets the polygon to newPolygon
    //**********************************************************************
    void setPolygon(const QPolygon& newPolygon)
    {
        polygon = newPolygon;
    }

    double area()
    {
        return 1000;
        // since we can't get area or perimeter, we'll make these last in line
    }

    double perimeter()
    {
        return 1000;
        // since we can't get area or perimeter, we'll make these last in line
    }
};

#endif // POLYGON_H


