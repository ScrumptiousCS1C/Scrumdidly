#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"; // Include the base class header

#include <QRect>
#include <QString>
#include <QColor>
#include <QFont>
#include <QPainter>

class Text : public Shape {
public:
    //**********************************************************************
    // Default Constructor
    //______________________________________________________________________
    // Pre: none
    // Post: Text object is initialized in heap with default values
    //**********************************************************************
    Text() : Shape(6, ShapeType::text) {}

    //**********************************************************************
    // Destructor
    //______________________________________________________________________
    // Pre: Text object must exist
    // Post: Text object is deleted
    //**********************************************************************
    ~Text() override {}

    //**********************************************************************
    // setRect(const QRect& newRect)
    //______________________________________________________________________
    // Pre: Text object exists, newRect is passed in
    // Post: Sets the rectangle for the text to newRect
    //**********************************************************************
    void setRect(const QRect& newRect) {
        rect = newRect;
    }

    //**********************************************************************
    // draw() override
    //______________________________________________________________________
    // Pre: Text object exists
    // Post: Draws the text using QPainter based on the text properties
    //**********************************************************************
    void draw() override {

        painter->setPen(getPen());
        painter->setBrush(getBrush());

        // Set font properties
        QFont font(family, pointSize, style, weight);
        painter->setFont(font);

        // Draw the text
        painter->drawText(rect, align, text);
    }

    //**********************************************************************
    // move(const QPoint& translationVector) override
    //______________________________________________________________________
    // Pre: Text object exists, translationVector is passed in
    // Post: Moves the text by translating its position
    //**********************************************************************
    void move(const QPoint& translationVector) override {
        rect.translate(translationVector);
    }

    //**********************************************************************
    // overrideText(const QString& newText)
    //______________________________________________________________________
    // Pre: Text object exists, newText is passed in
    // Post: Overrides the current text with the new text
    //**********************************************************************
    void overrideText(const QString& newText) {
        text = newText;
    }

    //**********************************************************************
    // setFontSize(int newSize)
    //______________________________________________________________________
    // Pre: Text object exists, newSize is passed in
    // Post: Sets the font size for the text to newSize
    //**********************************************************************
    void setFontSize(int newSize) {
        pointSize = newSize;
    }

    //**********************************************************************
    // setFontStyle(QFont::Style newStyle)
    //______________________________________________________________________
    // Pre: Text object exists, newStyle is passed in
    // Post: Sets the font style for the text to newStyle
    //**********************************************************************
    void setFontStyle(QFont::Style newStyle) {
        style = newStyle;
    }

    //**********************************************************************
    // setFontWeight(QFont::Weight newWeight)
    //______________________________________________________________________
    // Pre: Text object exists, newWeight is passed in
    // Post: Sets the font weight for the text to newWeight
    //**********************************************************************
    void setFontWeight(QFont::Weight newWeight) {
        weight = newWeight;
    }

    //**********************************************************************
    // setFontFamily(const QString& newFamily)
    //______________________________________________________________________
    // Pre: Text object exists, newFamily is passed in
    // Post: Sets the font family for the text to newFamily
    //**********************************************************************
    void setFontFamily(const QString& newFamily) {
        family = newFamily;
    }

    //**********************************************************************
    // setTextColor(const QColor& newColor)
    //______________________________________________________________________

    // Pre: Text object exists, newColor is passed in
    // Post: Sets the text color for the text to newColor
    //**********************************************************************


    //**********************************************************************
    // setTextAlignment(Qt::AlignmentFlag newAlignment)
    //______________________________________________________________________
    // Pre: Text object exists, newAlignment is passed in
    // Post: Sets the text alignment for the text to newAlignment
    //**********************************************************************
    void setTextAlignment(Qt::AlignmentFlag newAlignment) {
        align = newAlignment;
    }

private:
    QRect rect;
    QString text{"Class Project 2 - 2D Graphics Modeler"};
    Qt::AlignmentFlag align{Qt::AlignCenter};
    int pointSize{10};
    QString family{"Comic Sans MS"};
    QFont::Style style{QFont::StyleNormal};
    QFont::Weight weight{QFont::Normal};
};

#endif // TEXT_H
