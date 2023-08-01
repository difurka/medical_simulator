#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString qss = QString("background-color: %1").arg(col_pixel_.name());
    ui->button_choose_colour_pixel->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(col_back_.name());
    ui->button_choose_colour_back->setStyleSheet(qss);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->label->text() == "ON") {
        ui->label->setText("OFF");
    } else {
        ui->label->setText("ON");
    }
}


void MainWindow::on_button_choose_colour_back_clicked()
{
    QColor col = QColorDialog::getColor(Qt::white, this);
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        ui->button_choose_colour_back->setStyleSheet(qss);
        col_back_ = col;
    }
}


void MainWindow::on_button_choose_colour_pixel_clicked()
{
    QColor col = QColorDialog::getColor(Qt::white, this);
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        ui->button_choose_colour_pixel->setStyleSheet(qss);
        col_pixel_ = col;
    }
}

