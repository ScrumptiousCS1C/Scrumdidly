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
    Shape<int>* getShapeData() const;
    Qt::GlobalColor getQtColorEnum(const QColor& color);
    bool getDeleting() const;
    ~ShapeEditor();
private slots:
    void onDeleteClicked(bool);
    void handleTextSelection(int choice);

private:
    Ui::ShapeEditor *ui;
    bool deleting = false;
};

#endif // SHAPEEDITOR_H
