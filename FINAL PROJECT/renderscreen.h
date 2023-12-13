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
    explicit MainScreen(QWidget *parent = nullptr, bool isAdmin = false);
    void fillComboBox();
    void paintEvent(QPaintEvent *);
    void setAdmin(bool isAdmin);
    ~MainScreen();
public slots:
    void onSaveClicked(bool);
    void checkSelection(int shapeDropDownSel);
    void onHelpClicked(bool);
    void onDrawClicked(bool);
    void onNewProjectClicked(bool);
    void sortByPerimeter(bool);
    void sortByArea(bool);
    void sortByID(bool);

private slots:
    void on_quit_clicked();

private:
    Ui::RenderScreen *ui;
    QPainter* painter;
    bool reFillCombo = false;
    bool drawShapes = false;
    bool isAdmin = false;
    scrumptious::Vector<Shape<int>*> shapeList;
    int uniqueId;
protected:

};

#endif // MAINSCREEN_H
