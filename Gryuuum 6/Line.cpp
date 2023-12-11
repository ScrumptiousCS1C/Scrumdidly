#include "Line.h"

// Constructors
Line::Line(QPoint p1, QPoint p2)
    : Shape(1, ShapeType::line) {
    line.setP1(p1);
    line.setP2(p2);
}

Line::Line()
    : Shape(1, ShapeType::line) {
    line.setP1(QPoint(12, 90));
    line.setP2(QPoint(45, 67));
}

Line::Line(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush)
    : Shape(id, ShapeType::line, pen, brush)
{
    line.setP1(p1);
    line.setP2(p2);
}

// draw()
void Line::draw(QPainter *externalPainter) {

    if (externalPainter) {
        painter = externalPainter;
    }
    // Draws the line using the specified QPainter and dimensions
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawLine(line);
}

// move(const QPoint& translationVector)
void Line::move(const QPoint& translationVector) {
    // Moves the line by the specified translationVector
    line.translate(translationVector.x(), translationVector.y());
}

