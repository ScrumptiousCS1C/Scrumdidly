#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/logo.png");
    ui->label_pic->setPixmap(pix.scaled(281,221, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LOGINBUTTON_clicked()
{
    QString UserName = ui->userEDIT->text();
    QString Password = ui->passEDIT->text();

    if (UserName == "Scrumptious" && Password == "CS1C")
    {
        QMessageBox::information(this, "ScrumptiousCS1C", "Login Successful!");
        MainScreen *mainscreen = new MainScreen();
        mainscreen->show();
    }
    else
    {
        QMessageBox::warning(this, "ScrumptiousCS1C", "Enter username or password... / Incorrect entry");
    }
}


void MainWindow::on_CANCELBUTTON_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "ScrumptiousCS1C", "Are you sure you would like to close the application?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

