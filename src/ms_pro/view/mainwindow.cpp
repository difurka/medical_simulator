#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>
#include <QImage>
#include "utils/utils.h"

#include<QDebug>


MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller_(controller)
{
    ui->setupUi(this);

    ui->area->SetController(controller);
    InitSettings_();
    controller_->GeneratePix(radius_);
    UpdatePixels(radius_pixel_);

}


void MainWindow::InitSettings_()
{
    figure_t kFirstFigure = figure_t::CIRCLE;
    QColor kColBack = "#F1CFED";
    QColor kColPixel = Qt::blue;
    QColor col_main_window_ = "#F0FFF0";


    col_back_ = kColBack;
    col_pixel_ = kColPixel;
    QString qss = QString("background-color: %1").arg(col_pixel_.name());
    ui->button_choose_colour_pixel->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(col_back_.name());
    ui->button_choose_colour_back->setStyleSheet(qss);

    qss = QString("background-color: %1").arg(col_main_window_.name());
    setStyleSheet(qss);

    ui->label_colour_background->setToolTip ("Colour of back");
    figure_ = kFirstFigure;
    ui->tab_choose->setCurrentIndex(static_cast<int>(kFirstFigure));

    // set init sliders

    ui->slider_circle_radius->setMinimum(kMinSize/2);
    ui->slider_circle_radius->setMaximum(kMaxSize/2);
    ui->slider_circle_radius->setValue((kMaxSize/2 -kMinSize/2)/2);
    ui->slider_circle_radius->setSliderPosition((kMaxSize/2 -kMinSize/2)/2);

    ui->spin_circle_radius->setMinimum(kMinSize/2);
    ui->spin_circle_radius->setMaximum(kMaxSize/2);
    ui->spin_circle_radius->setValue((kMaxSize/2 -kMinSize/2)/2);

    ui->slider_rect_height->setMinimum(kMinSize);
    ui->slider_rect_height->setMaximum(kMaxSize);
    ui->slider_rect_height->setValue((kMaxSize -kMinSize)/2);
    ui->slider_rect_height->setSliderPosition((kMaxSize -kMinSize)/2);

    ui->spin_rect_height->setMinimum(kMinSize);
    ui->spin_rect_height->setMaximum(kMaxSize);
    ui->spin_rect_height->setValue((kMaxSize -kMinSize)/2);

    ui->slider_rect_width->setMinimum(kMinSize);
    ui->slider_rect_width->setMaximum(kMaxSize);
    ui->slider_rect_width->setValue((kMaxSize -kMinSize)/2);
    ui->slider_rect_width->setSliderPosition((kMaxSize -kMinSize)/2);

    ui->spin_rect_width->setMinimum(kMinSize);
    ui->spin_rect_width->setMaximum(kMaxSize);
    ui->spin_rect_width->setValue((kMaxSize -kMinSize)/2);

    // set area
    ui->area->resize(kMaxSize, kMaxSize);
    ui->area->SetBackArea(col_back_);
    ui->area->SetPixelArea(col_pixel_);
    ui->area->SetWindowArea(col_main_window_);

    // model
    controller_->SetPixelRad(radius_pixel_);
    controller_->SetCircleRad(radius_);
    controller_->SetRectSize(width_, height_);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Update() {
    if (figure_ == figure_t::CIRCLE) {
        controller_->GenerateCirc(radius_);
    } else {
        controller_->GenerateRect(width_, height_);
    }
    controller_->GeneratePix(radius_pixel_);
    Draw();
}

void MainWindow::UpdatePixels(int radius) {
    if (figure_ == figure_t::CIRCLE) {
        controller_->GenerateCirc(radius_);
    } else {
        controller_->GenerateRect(width_, height_);
    }
    controller_->ChangePixSize(radius_pixel_);
    Draw();
}

void MainWindow::Draw()
{
  ui->area->DrawFigure(figure_);
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
    ui->area->SetBackArea(col_back_);
    Draw();
}


void MainWindow::on_button_choose_colour_pixel_clicked()
{
    QColor color = GetColor_(col_pixel_);
    SetButtonColor_(ui->button_choose_colour_pixel, color);
    col_pixel_ = color;
    ui->area->SetPixelArea(col_pixel_);
    Draw();
}

void MainWindow::on_slider_pixel_size_valueChanged(int value) {
  ui->spin_pixel_size->setValue(value);
  radius_pixel_ = value;
  UpdatePixels(radius_pixel_);
}


void MainWindow::on_spin_pixel_size_editingFinished() {
  ui->slider_pixel_size->setSliderPosition(ui->spin_pixel_size->value());
  radius_pixel_ = ui->spin_pixel_size->value();
  UpdatePixels(radius_pixel_);
}


void MainWindow::on_draw_pixels_clicked()
{
    Update();
}


void MainWindow::on_slider_circle_radius_valueChanged(int value)
{
    ui->spin_circle_radius->setValue(value);
    radius_ = value;
    Update();
}


void MainWindow::on_spin_circle_radius_editingFinished()
{
    ui->slider_circle_radius->setSliderPosition(ui->spin_circle_radius->value());
    radius_ = ui->spin_circle_radius->value();
    Update();
}

void MainWindow::on_slider_rect_width_valueChanged(int value)
{
    ui->spin_rect_width->setValue(value);
    width_ = value;
    Update();
}


void MainWindow::on_spin_rect_width_editingFinished()
{
    ui->slider_rect_width->setSliderPosition(ui->spin_rect_width->value());
    width_ = ui->spin_rect_width->value();
    Update();
}

void MainWindow::on_slider_rect_height_valueChanged(int value)
{
    ui->spin_rect_height->setValue(value);
    height_ = value;
    Update();
}


void MainWindow::on_spin_rect_height_editingFinished()
{
    ui->slider_rect_height->setSliderPosition(ui->spin_rect_height->value());
    height_ = ui->spin_rect_height->value();
    Update();
}

void MainWindow::on_tab_choose_tabBarClicked(int index)
{
    figure_ = static_cast<figure_t>(index);
    controller_->SetFigType(index);
    Update();
}



void MainWindow::on_button_check_answer_clicked()
{
    float result = controller_->GetPercent();
    ui->label_answer->setText(QString::number(result));
    int answer = ui->spin_percents->value();

    QPalette sample_palette;


    if (std::abs(result-answer) < 5) {
        sample_palette.setColor(QPalette::WindowText, Qt::green);
        ui->label_level->setPalette(sample_palette);
        ui->label_level->setText("Глаз алмаз!!");
    } else if (std::abs(result-answer) < 10) {
        sample_palette.setColor(QPalette::WindowText, Qt::blue);
        ui->label_level->setPalette(sample_palette);
        ui->label_level->setText("Близко к ответу");
    } else if (std::abs(result-answer) < 20) {
        sample_palette.setColor(QPalette::WindowText, Qt::black);
        ui->label_level->setPalette(sample_palette);
        ui->label_level->setText("Немного не так");
    } else {
        sample_palette.setColor(QPalette::WindowText, Qt::red);
        ui->label_level->setPalette(sample_palette);
        ui->label_level->setText("Далеко от ответа");
    }
}

