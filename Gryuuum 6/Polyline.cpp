#include "Polyline.h"

// Constructors
Polyline::Polyline()
    : Shape() {
    polyline << QPoint(100, 80) << QPoint(150, 130) << QPoint(200, 80);
}

Polyline::Polyline(const scrumptious::Vector<QPoint>& pointsVector)
    : Shape(3, ShapeType::polyline)
{
    for (int i = 0; i < pointsVector.sizeOf(); ++i)
    {
        polyline << pointsVector[i];
    }
}

Polyline::Polyline(const QList<QPoint>& points, int id, QPen pen, QBrush brush) :
    Shape(id, ShapeType::polyline, pen, brush)
{
    polyline = QPolygon(points);
}

// draw() - Draws the polyline using the specified QPainter and dimensions
void Polyline::draw(QPainter *externalPainter) {

    if (externalPainter) {
        painter = externalPainter;
    }
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPolyline(polyline);
}

// move(const QPoint& translationVector) - Moves the polyline by the specified translationVector
void Polyline::move(const QPoint& translationVector) {
    polyline.translate(translationVector.x(), translationVector.y());
}

// getPolyline() const - Returns the QPolygon representing the polyline
QPolygon Polyline::getPolyline() const {
    return polyline;
}

// setPolyline(const QPolygon& newPolyline) - Sets the polyline to newPolyline
void Polyline::setPolyline(const QPolygon& newPolyline) {
    polyline = newPolyline;
}



