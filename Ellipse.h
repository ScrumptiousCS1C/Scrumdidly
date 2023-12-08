#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
private:
    QRect ellipseRect;  // Private variable specific to Ellipse

public:
    // Constructor
    Ellipse();

    Ellipse(QPoint p1, QPoint p2);

    // Implement pure virtual function from base class
    void draw(QPainter *externalPainter) override;

    // Implement pure virtual function from base class
    void move(const QPoint& translationVector) override;

    // Example: Getter for the ellipse dimensions
    QRect getEllipseRect() const;

    // Example: Setter for the ellipse dimensions
    void setEllipseRect(const QRect& newRect);
};

#endif // ELLIPSE_H

