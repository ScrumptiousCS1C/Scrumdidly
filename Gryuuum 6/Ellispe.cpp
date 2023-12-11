#include "Ellipse.h"


// Constructor
Ellipse::Ellipse() : Shape() {
    ellipseRect.adjust(600, 20, 200, 88);
}

Ellipse::Ellipse(QPoint p1, QPoint p2) : Shape(5, ShapeType::ellipse) {
    ellipseRect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
}

Ellipse::Ellipse(QPoint p1, QPoint p2, int id, QPen pen, QBrush brush)
    : Shape(id, ShapeType::ellipse, pen, brush)
{
    ellipseRect = QRect(p1, p2);
}

// Implement pure virtual function from base class
void Ellipse::draw(QPainter *externalPainter) {

    if (externalPainter) {
        painter = externalPainter;
    }
    painter->setPen(pen);
    painter->setBrush(brush);
    // Draw the ellipse using the QRect dimensions
    painter->drawEllipse(ellipseRect);
}

// Implement pure virtual function from base class
void Ellipse::move(const QPoint& translationVector) {
    ellipseRect.translate(translationVector.x(), translationVector.y());
}

// Example: Getter for the ellipse dimensions
QRect Ellipse::getEllipseRect() const {
    return ellipseRect;
}

// Example: Setter for the ellipse dimensions
void Ellipse::setEllipseRect(const QRect& newRect) {
    ellipseRect = newRect;
}

