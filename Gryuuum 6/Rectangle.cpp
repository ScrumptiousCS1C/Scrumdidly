#include "Rectangle.h"

Rectangle::Rectangle(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush)
    : Shape(id, ShapeType::rectangle, pen, brush)
{
    rect = QRect(p1, p2);
}

// Constructor
Rectangle::Rectangle(QPoint p1, QPoint p2)
    : Shape(4, ShapeType::rectangle) {
    rect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
}

// Overloaded Constructor with default values
Rectangle::Rectangle()
    : rect(QRect(30, 40, 50, 30)), Shape(4, ShapeType::rectangle) {}

// draw()
void Rectangle::draw (QPainter *externalPainter) {

    if (externalPainter) {
        painter = externalPainter;
    }
    // Draw the rectangle using the QRect dimensions
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(rect);
}

// move(const QPoint& translationVector)
void Rectangle::move(const QPoint& translationVector) {
    rect.translate(translationVector.x(), translationVector.y());
}

// Additional functions specific to Rectangle class, if needed

// getRectangle() const
QRect Rectangle::getRectangle() const {
    return rect;
}

// setRectangle(const QRect& newRect)
void Rectangle::setRectangle(const QRect& newRect) {
    rect = newRect;
}
