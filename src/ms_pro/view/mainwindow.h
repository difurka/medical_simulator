#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_button_choose_colour_back_clicked();

    void on_button_choose_colour_pixel_clicked();
    void on_slider_pixel_size_valueChanged(int value);
    void on_spin_pixel_size_editingFinished();
    void on_draw_pixels_clicked();

    void on_slider_circle_radius_valueChanged(int value);

    void on_spin_circule_radius_editingFinished();

private:
    QColor GetColor_(QColor current_color);
    void SetButtonColor_(QPushButton *button, QColor color);
    void InitSettings_();

private:
    Ui::MainWindow *ui;
    QColor col_back_ = "#F1CFED";
    QColor col_pixel_ = Qt::blue;
    float radius_ = 75;
    float weigth_ = 150;
    float heigth_ = 150;
    float const kXcenter = 160;
    float const kYcenter = 160;


protected:
    /* Define method of base class
     * */
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
