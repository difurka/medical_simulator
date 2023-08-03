#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>
#include <QImage>


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
//    auto circles = QImage( 300, 300, QImage::Format_ARGB32 );
    QPainter painter(this); // Create object of QPainter
    // Set Brush
//    QPainter::CompositionMode mode = currentMode();

    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
// painter.setCompositionMode(QPainter::CompositionMode_Source);
 painter.setPen(QPen(col_back_, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(col_back_, Qt::SolidPattern));

if (figure_ == figure_t::CIRCLE) {
    painter.drawEllipse(QPointF(kXcenter, kYcenter), radius_, radius_);
} else {
    painter.drawRect(kXcenter - height_/2, kXcenter - width_/2 , height_, width_);
}
//    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter.setPen(QPen(col_pixel_, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(col_pixel_, Qt::SolidPattern));
    double x = (kXcenter*1.4 - radius_)/ 1.4;
    double y = (kYcenter*1.4 - radius_)/ 1.4;
    painter.drawEllipse(QPointF(x, y), radius_pixel_, radius_pixel_);
QRect rect = this->geometry();

painter.setClipRegion(QRegion(rect.width()/2,
                                rect.height()/2,
                                150, 150,
                                QRegion::Ellipse));
//circles.fill(Qt::transparent);
//// Create a place to draw the circles.
//auto circles = QImage( 300, 300, QImage::Format_ARGB32 );

//// Init the painter
//QPainter p(&circles);

//// DestinationOver results in the current painting
//// going below the existing image.
//p.setCompositionMode( QPainter::CompositionMode_DestinationOver );
//p.setRenderHints( QPainter::HighQualityAntialiasing );


//    p.setPen(QPen(col_back_, 1, Qt::SolidLine, Qt::FlatCap));
//    p.setBrush(QBrush(col_back_, Qt::SolidPattern));

//    p.drawEllipse(QPointF(kXcenter, kYcenter), radius_, radius_);

//    p.setPen(QPen(col_pixel_, 1, Qt::SolidLine, Qt::FlatCap));
//    p.setBrush(QBrush(col_pixel_, Qt::SolidPattern));
//    p.drawEllipse(QPointF(kXcenter, kYcenter), 10, 10);




////// The above image is transparent. If you prefer to have
////// a while/color bg do this:
////auto final = QImage( 700 ,700, QImage::Format_ARGB32 );
//////final.fill( Qt::lightgray );

//auto p1 = QPainter( this);

////// Now we want the current painting to be above the existing
////p1.setCompositionMode( QPainter::CompositionMode_SourceOver );
////p1.setRenderHints( QPainter::HighQualityAntialiasing );

//p1.drawImage( QRect( 0, 0, 700, 700 ), circles );



}

void MainWindow::InitSettings_()
{
    QString qss = QString("background-color: %1").arg(col_pixel_.name());
    ui->button_choose_colour_pixel->setStyleSheet(qss);
    qss = QString("background-color: %1").arg(col_back_.name());
    ui->button_choose_colour_back->setStyleSheet(qss);

    ui->label_colour_background->setToolTip ("Colour of back");
    figure_ = figure_t::CIRCLE;

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
    repaint();
}


void MainWindow::on_button_choose_colour_pixel_clicked()
{
    QColor color = GetColor_(col_pixel_);
    SetButtonColor_(ui->button_choose_colour_pixel, color);
    col_pixel_ = color;
    repaint();
}

void MainWindow::on_slider_pixel_size_valueChanged(int value) {
//  controller_->RotationAroundAxis(s21::OX, value);
  ui->spin_pixel_size->setValue(value);
  radius_pixel_ = value;
  repaint();
}


void MainWindow::on_spin_pixel_size_editingFinished() {
  ui->slider_pixel_size->setSliderPosition(ui->spin_pixel_size->value());
  radius_pixel_ = ui->spin_pixel_size->value();
  repaint();
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


void MainWindow::on_tab_choose_tabBarClicked(int index)
{
    figure_ = static_cast<figure_t>(index);
    repaint();
}

