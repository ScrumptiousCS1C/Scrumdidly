#include"Polygon.h"

Polygon::Polygon(const QList<QPoint>& points, int id, QPen pen, QBrush brush)
    : Shape(id, ShapeType::polygon, pen, brush)
{
    polygon = QPolygon(points);
}
// Constructors
Polygon::Polygon() : Shape() {
    // Add sample points to the polygon
    polygon << QPoint(300, 200)
            << QPoint(400, 150)
            << QPoint(500, 200)
            << QPoint(475, 300)
            << QPoint(375, 300);
}

Polygon:: Polygon(const scrumptious::Vector<QPoint>& pointsVector)
    : Shape(3, ShapeType::polygon) {
        for (int i = 0; i < pointsVector.sizeOf(); ++i) {
            polygon << pointsVector[i];
        }
    }

// Draw method
void Polygon::draw(QPainter *externalPainter) {

    if (externalPainter) {
        painter = externalPainter;
    }
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

// Move method
void Polygon::move(const QPoint& translationVector) {
    polygon.translate(translationVector.x(), translationVector.y());
}

// Getter for the polygon
QPolygon Polygon::getPolygon() const {
    return polygon;
}

// Setter for the polygon
void Polygon::setPolygon(const QPolygon& newPolygon) {
    polygon = newPolygon;
}
