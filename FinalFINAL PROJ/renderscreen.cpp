#include "renderscreen.h"
#include "serializer.h"
#include "ui_renderscreen.h"
#include <QFileDialog>
#include "shapeeditor.h"
#include "aboutus.h"
#include "Line.h"
#include <QPen>
#include "parser.h"
#include <QMessageBox>

MainScreen::MainScreen(QWidget *parent, bool isAdmin) :
    QMainWindow(parent),
    ui(new Ui::RenderScreen)
{
    ui->setupUi(this);
    this->setAdmin(isAdmin);
    shapeList = LoadFile();
    uniqueId = shapeList.sizeOf() + 1;
    fillComboBox();
    connect(this->ui->shapeSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(checkSelection(int)));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(onSaveClicked(bool)));
    connect(this->ui->draw, SIGNAL(clicked(bool)), this, SLOT(onDrawClicked(bool)));
    connect(this->ui->newProject, SIGNAL(clicked(bool)), this, SLOT(onNewProjectClicked(bool)));
    connect(this->ui->help, SIGNAL(clicked(bool)), this, SLOT(onHelpClicked(bool)));
    connect(this->ui->sortbyAbutton, SIGNAL(clicked(bool)), this, SLOT(sortByArea(bool)));
    connect(this->ui->sortbyPbutton, SIGNAL(clicked(bool)), this, SLOT(sortByPerimeter(bool)));
    connect(this->ui->sortbyIDbutton, SIGNAL(clicked(bool)), this, SLOT(sortByID(bool)));
}

void MainScreen::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QRect rect = ui->canvas->geometry();
    painter.setViewport(rect);


    if(drawShapes)
    {
        for(int i = 0; i < shapeList.sizeOf(); i++)
        {
            shapeList[i]->draw(&painter);
        }
    }

    painter.end();
}

void MainScreen::setAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
}

MainScreen::~MainScreen()
{
    delete ui;
}

// onSaveClick()
//
void MainScreen::onSaveClicked(bool)
{
    if(isAdmin)
    {
        QString filename = QFileDialog::getSaveFileName(this, "Choose file name: ", "", "Text files (*.txt)");
        if(filename.isEmpty()||filename.isNull())
        {
            return;
        }
        serializer(filename.toStdString(), shapeList);
    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");

    }
}

// Fills the combo box with the NAMES of the shapes (may need to cast to Qstring but Qt sometimes does this implicitly)
void MainScreen::fillComboBox()
{
    reFillCombo = true;
    this->ui->shapeSelection->clear();
    this->ui->shapeSelection->addItem("N/A");
    this->ui->shapeSelection->addItem("New...");
    auto va1 = shapeList.begin();
    auto va2 = shapeList.end();
    for(auto it = shapeList.begin(); it != shapeList.end(); ++it)
    {
        this->ui->shapeSelection->addItem((*it)->getShapeTypeString());
    }
    reFillCombo = false;
}

// checks selection, calls function to create new shape if "New..."
void MainScreen::checkSelection(int shapeDropDownSel)
{
    if (isAdmin){
        if(reFillCombo || shapeDropDownSel == 0)
        {
            return;
        }

        std::cout << shapeDropDownSel << std::endl;

        Shape<int>* shape = nullptr;
        if (shapeDropDownSel != 1) // if new was not selected
        {
            shape = shapeList[shapeDropDownSel - 2];
        }
        ShapeEditor editor(this, shape);
        if(editor.exec() == 1){
            //std::cout<< "hello" << std::endl;
            // code to create/save and add shape to vector
            // Some kind of function to get the shape.
            Shape<int>* newShape = editor.getShapeData(); // Function that returns a shape pointer.
            if (newShape == nullptr)
            {
                //std::cout << "Where are we" << std::endl;
                return;
            }
            if (shapeDropDownSel == 1)
            {
                // Add the shape to the end of the vector.
                std::cout << "I think it's here" << std::endl;
                newShape->setId(uniqueId);
                shapeList.push_back(newShape);
                uniqueId++;
            }
            else
            {
                // We want to delete the data of the old shape immediately.
                std::cout << "Holy shit" << std::endl;
                delete shape;
                // Replace the value in the vector with the new shape.
                shapeList[shapeDropDownSel - 2] = newShape;
            }

            // Call something here to update the combobox and the UI and whatever else needs to be updated. You may just want to pass the shape vector around as a constant reference so it can be read but not modified.
        }
        else
        {
            if(editor.getDeleting())
            {
                auto trash = shapeList.begin()+shapeDropDownSel-2;
                delete *trash;
                shapeList.erase(trash);
            }
        }
        fillComboBox();
    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");
    }
}
void MainScreen::onHelpClicked(bool)
{
    aboutus *mainscreen1 = new aboutus();
    mainscreen1->show();
}

void MainScreen::onDrawClicked(bool)
{
    // draw EVERYTHING
    // call draw functions here
    // set painter obj
    drawShapes = true;
    repaint();
}

void MainScreen::onNewProjectClicked(bool)
{
    if(isAdmin)
    {
        drawShapes = false;
        repaint();
    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");

    }
}

void MainScreen::sortByPerimeter(bool)
{
    if(isAdmin)
    {
        for (int j = 0; j < shapeList.sizeOf() - 1; ++j) {
            int minIndex = j;
            for (int i = j + 1; i < shapeList.sizeOf(); ++i) {
                if (shapeList[minIndex]->perimeter() > shapeList[i]->perimeter()) {
                    minIndex = i;
                }
            }
            if (minIndex != j) {
                std::swap(shapeList[j], shapeList[minIndex]);
            }
        }

        for (int j = 0; j < shapeList.sizeOf() - 1; j++){
            std::cout << shapeList[j]->area() << ", ";
        }
        std::cout << "\n";

        fillComboBox();

    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");

    }
}

void MainScreen::sortByID(bool)
{
    if(isAdmin)
    {
        for (int j = 0; j < shapeList.sizeOf() - 1; ++j) {
            int minIndex = j;
            for (int i = j + 1; i < shapeList.sizeOf(); ++i) {
                if (shapeList[minIndex]->getId() > shapeList[i]->getId()) {
                    minIndex = i;
                }
            }
            if (minIndex != j) {
                std::swap(shapeList[j], shapeList[minIndex]);
            }
        }

        for (int j = 0; j < shapeList.sizeOf() - 1; j++){
            std::cout << shapeList[j]->getId() << ", ";
        }
        std::cout << "\n";
        fillComboBox();

    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");

    }
}

void MainScreen::sortByArea(bool)
{
    if(isAdmin)
    {
        for (int j = 0; j < shapeList.sizeOf() - 1; ++j) {
            int minIndex = j;
            for (int i = j + 1; i < shapeList.sizeOf(); ++i) {
                if (shapeList[minIndex]->area() > shapeList[i]->area()) {
                    minIndex = i;
                }
            }
            if (minIndex != j) {
                std::swap(shapeList[j], shapeList[minIndex]);
            }
        }
        for (int j = 0; j < shapeList.sizeOf() - 1; j++){
            std::cout << shapeList[j]->perimeter() << ", ";
        }
        std::cout << "\n";
        fillComboBox();
    }
    else
    {
        QMessageBox::information(this, "Login", "!! Must be Admin to use this feature!");

    }
}



void MainScreen::on_quit_clicked()
{
    MainScreen::close();
}

