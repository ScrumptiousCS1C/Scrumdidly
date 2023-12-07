#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
private:
    QRect ellipseRect;  // Private variable specific to Ellipse

public:
    // Constructor
    Ellipse() : Shape() {
        ellipseRect.adjust(600,20,200,88);
    }

    Ellipse(QPoint p1, QPoint p2) : Shape(5, ShapeType::ellipse) {
        ellipseRect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
    }

    // Implement pure virtual function from base class
    void draw() override {
        // Draw the ellipse using the QRect dimensions
        painter->drawEllipse(ellipseRect);
    }

    // Implement pure virtual function from base class
    void move(const QPoint& translationVector) override {
        ellipseRect.translate(translationVector.x(), translationVector.y());
    }

    // Example: Getter for the ellipse dimensions
    QRect getEllipseRect() const {
        return ellipseRect;
    }

    // Example: Setter for the ellipse dimensions
    void setEllipseRect(const QRect& newRect) {
        ellipseRect = newRect;
    }
};

#endif // ELLIPSE_H
