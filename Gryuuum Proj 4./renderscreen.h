#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include "vector.h"
#include "Shape.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Text.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QSpinBox>


namespace Ui {
class RenderScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    void fillComboBox();
    void paintEvent(QPaintEvent *);
    ~MainScreen();
public slots:
    void onSaveClicked(bool);
    void checkSelection(int shapeDropDownSel);
    void onHelpClicked(bool);
    void onDrawClicked(bool);
    void onNewProjectClicked(bool);

private:
    Ui::RenderScreen *ui;
    scrumptious::Vector<Shape*> shapeList;
    QPainter* painter;
    bool drawShapes;
    bool reFillCombo = false;
};

#endif // MAINSCREEN_H
