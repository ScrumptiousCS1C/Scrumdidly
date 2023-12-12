#ifndef SHAPEEDITOR_H
#define SHAPEEDITOR_H

#include <QDialog>
#include "renderscreen.h"

namespace Ui {
class ShapeEditor;
}

class ShapeEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ShapeEditor(QWidget *parent = nullptr, Shape<int>* shape = nullptr);
    void switchShapeTab();
    Shape<int>* getShapeData();
    void getPenBrush(QPen pen, QBrush brush);
    Qt::GlobalColor getQtColorEnum(const QColor& color);
    ~ShapeEditor();

private:
    Ui::ShapeEditor *ui;
};

#endif // SHAPEEDITOR_H
