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
    explicit ShapeEditor(QWidget *parent = nullptr, Shape* shape = nullptr);
    void switchShapeTab();
    Shape* getShapeData() const;
    ~ShapeEditor();

private:
    Ui::ShapeEditor *ui;
};

#endif // SHAPEEDITOR_H
