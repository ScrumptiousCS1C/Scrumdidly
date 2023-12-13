#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

template<typename T>
class Ellipse : public Shape<T> {
private:
    QRect ellipseRect;  // Private variable specific to Ellipse

public:
    // Constructor
    Ellipse() : Shape<T>() {
        ellipseRect.adjust(600, 20, 200, 88);
    }

    Ellipse(QPoint p1, QPoint p2)
        : Shape<T>(5, Shape<T>::ShapeType::ellipse) {
        ellipseRect.adjust(p1.x(), p1.y(), p2.x(), p2.y());
    }

    Ellipse(QPoint p1, QPoint p2, int id, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(id, Shape<T>::ShapeType::ellipse, dimensions, pen)
    {
        ellipseRect = QRect(p1, p2);
    }

    // Parser constructor
    Ellipse(int i, typename Shape<T>::ShapeType type, scrumptious::Vector<T> dimensions, QPen pen)
        : Shape<T>(i, type, dimensions, pen)
    {
        ellipseRect = QRect(dimensions[0], dimensions[1],
                            dimensions[0], dimensions[1]);
    }

    // Implement pure virtual function from base class
    void draw(QPainter *externalPainter) override
    {

        if (externalPainter) {
            this->painter = externalPainter;
        }
        this->painter->setPen(this->getPen());
        this->painter->setBrush(this->getBrush());
        // Draw the ellipse using the QRect dimensions
        this->painter->drawEllipse(ellipseRect);
    }

    // Implement pure virtual function from base class
    void move(const QPoint& translationVector) override
    {
        ellipseRect.translate(translationVector.x(), translationVector.y());
    }

    // Example: Getter for the ellipse dimensions
    QRect getEllipseRect() const
    {
        return ellipseRect;
    }

    // Example: Setter for the ellipse dimensions
    void setEllipseRect(const QRect& newRect)
    {
        ellipseRect = newRect;
    }
    double perimeter()
    {
        return 2 * M_PI * std::sqrt((ellipseRect.height() * ellipseRect.height() + ellipseRect.width() * ellipseRect.width()) / 8);
    }

    double area()
    {
        return M_PI * ellipseRect.width() * ellipseRect.height() / 4;
    }
};

#endif // ELLIPSE_H

