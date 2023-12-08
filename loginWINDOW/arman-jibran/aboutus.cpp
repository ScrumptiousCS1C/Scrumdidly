#include "aboutus.h"
#include "ui_aboutus.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>


aboutus::aboutus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutus)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    QPixmap logoABOUTUS(":/images/logo.png");
    ui->label_3->setPixmap(logoABOUTUS.scaled(281,221, Qt::KeepAspectRatio));

}

aboutus::~aboutus()
{
    delete ui;
}

void aboutus::on_pushButton_clicked()
{
    QString link = "https://forms.gle/vsKnN6DGaYzk6x868";
    QDesktopServices::openUrl(QUrl(link));
}


void aboutus::on_pushButton_2_clicked()
{
    QString link2 = "https://forms.gle/uvaVCaFYiVJoRX2Z9";
    QDesktopServices::openUrl(QUrl(link2));
}

