#ifndef TEXT_H
#define TEXT_H

#include "Shape.h" // Include the base class header

#include <QRect>
#include <QString>
#include <QColor>
#include <QFont>
#include <QPainter>

template <typename T>
class Text : public Shape<T> {
public:
    //**********************************************************************
    // Default Constructor
    //______________________________________________________________________
    // Pre: none
    // Post: Text object is initialized in heap with default values
    //**********************************************************************
    Text() : Shape<T>(6, Shape<T>::ShapeType::text) {}

    // Parser Constructor
    Text(QString txt, QFont fnt, Qt::AlignmentFlag flag, int i, typename Shape<T>::ShapeType type, scrumptious::Vector<T> dimensions)
        : Shape<T>(i, type, dimensions)
    {
        text = QString(txt);
        font = QFont(fnt);
        rect = QRect(dimensions[0], dimensions[1], dimensions[2], dimensions[3]);
        align = flag;
    }

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
    void draw (QPainter *externalPainter)  override{

        if (externalPainter) {
            this->painter = externalPainter;
        }

        this->painter->setPen(this->getPen());
        this->painter->setFont(font);

        // Draw the text
        this->painter->drawText(rect, align, text);
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


    void changeAlignment(Qt::AlignmentFlag newalign){
        align = newalign;
    }


    void setFont ( QFont newfont) {
        font = newfont;
    }

    QChar getTextIndex(int n) const{return text[n];}

    // textbox size..
    double area()
    {
        return rect.height()*rect.width();
    }

    double perimeter(){
        return 2*(rect.height() + rect.width());
    }


private:
    QRect rect;
    QFont font;
    QString text{"Class Project 2 - 2D Graphics Modeler"};
    Qt::AlignmentFlag align{Qt::AlignCenter};

};

#endif // TEXT_H
