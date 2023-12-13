#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include "vector.h"
#include "Shape.h"
#include "Polygon.h"
#include "Polyline.h"
//#include "Text.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QMessageBox>
#include "globals.h"


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

private slots:
    void on_quit_clicked();

private:
    Ui::RenderScreen *ui;

    QPainter* painter;
    bool drawShapes = false;
    bool reFillCombo = false;
    scrumptious::Vector<Shape<int>*> shapeList;
};

#endif // MAINSCREEN_H
