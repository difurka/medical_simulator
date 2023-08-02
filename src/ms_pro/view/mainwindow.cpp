#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitSettings_();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Create object of QPainter
    // Set Brush
//    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(col_back_, Qt::SolidPattern));

//    QRect rect(kXcenter, kYcenter, radius_*2, radius_*2);
    painter.drawEllipse(QPointF(kXcenter, kYcenter), radius_, radius_);
}

void MainWindow::InitSettings_()
{
    QString qss = QString("background-color: %1").arg(col_pixel_.name());
    ui->button_choose_colour_pixel->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(col_back_.name());
    ui->button_choose_colour_back->setStyleSheet(qss);

    ui->label_colour_background->setToolTip ("Colour of back");

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

QColor MainWindow::GetColor_(QColor current_color) {
  QColorDialog dialog(this);
  QColor result = current_color;
  dialog.setCurrentColor(current_color);
  if (dialog.exec() == QColorDialog::Accepted) {
    result = dialog.selectedColor();
  }
  return result;
}

void MainWindow::SetButtonColor_(QPushButton *button, QColor color) {
  button->setStyleSheet("background-color: "+color.name());
}

void MainWindow::on_button_choose_colour_back_clicked()
{
    QColor color = GetColor_(col_back_);
    SetButtonColor_(ui->button_choose_colour_back, color);
    col_back_ = color;
}


void MainWindow::on_button_choose_colour_pixel_clicked()
{
    QColor color = GetColor_(col_pixel_);
    SetButtonColor_(ui->button_choose_colour_pixel, color);
    col_pixel_ = color;
}

void MainWindow::on_slider_pixel_size_valueChanged(int value) {
//  controller_->RotationAroundAxis(s21::OX, value);
  ui->spin_pixel_size->setValue(value);
}


void MainWindow::on_spin_pixel_size_editingFinished() {
  ui->slider_pixel_size->setSliderPosition(ui->spin_pixel_size->value());
}


void MainWindow::on_draw_pixels_clicked()
{
    repaint();
}


void MainWindow::on_slider_circle_radius_valueChanged(int value)
{
    ui->spin_circule_radius->setValue(value);
    radius_ = value;
    repaint();
}


void MainWindow::on_spin_circule_radius_editingFinished()
{
    ui->slider_circle_radius->setSliderPosition(ui->spin_circule_radius->value());
    radius_ = ui->spin_circule_radius->value();
    repaint();
}

