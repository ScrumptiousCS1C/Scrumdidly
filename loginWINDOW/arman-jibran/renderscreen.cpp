#include "renderscreen.h"
#include "ui_renderscreen.h"
#include "aboutus.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderScreen)
{
    ui->setupUi(this);
    fillComboBox();
    connect(this->ui->shapeSelection, SIGNAL(currentTextChanged()), this, SLOT(checkSelection()));
}

MainScreen::~MainScreen()
{
    delete ui;
}

// Fills th4e combo box with the NAMES of the shapes (may need to cast to Qstring but Qt sometimes does this implicitly)
void MainScreen::fillComboBox(){

    this->ui->shapeSelection->clear();
    this->ui->shapeSelection->addItem("N/A");
    this->ui->shapeSelection->addItem("New...");


}

// checks selection, calls function to create new shape if "New..."
void MainScreen::checkSelection(QString shapeDropDownSel){
    if(shapeDropDownSel == "New..."){
        QDialog dialog(this);
        QComboBox *shapeComboBox = new QComboBox(&dialog);
        shapeComboBox->addItem("Blank");
        shapeComboBox->addItem("Line");
        shapeComboBox->addItem("Polyline");
        shapeComboBox->addItem("Rectangle");
        shapeComboBox->addItem("Ellipse");
        shapeComboBox->addItem("Text");

        QLabel *shapeParamsLabel = new QLabel(&dialog);
        connect(shapeComboBox, &QComboBox::currentTextChanged, this, [&shapeParamsLabel](const QString &shapeType){
            shapeParamsLabel->setText(shapeType);
            if(shapeType == "Blank"){

            }else if(shapeType == "Line"){

            }else if(shapeType == "Polyline"){

            }else if(shapeType == "Rectangle"){

            }else if(shapeType == "Text"){

            }
        });
//        if (dialog.exec() == QDialog::Accepted(){

//        }



    }
}

void MainScreen::on_pushButton_5_clicked()
{
    aboutus *mainscreen1 = new aboutus();
    mainscreen1->show();
}

