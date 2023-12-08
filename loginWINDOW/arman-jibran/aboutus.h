#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QWidget>

namespace Ui {
class aboutus;
}

class aboutus : public QWidget
{
    Q_OBJECT

public:
    explicit aboutus(QWidget *parent = nullptr);
    ~aboutus();

private slots:
    void on_label_3_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::aboutus *ui;
};

#endif // ABOUTUS_H
