#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QPainter>

#include <controller/controller.h>
#include "utils/utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // enum class figure_t {
    //     CIRCLE = 1,
    //     RECTANGLE = 0,
    // };

public:
    explicit MainWindow(Controller* controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_choose_colour_back_clicked();

    void on_button_choose_colour_pixel_clicked();
    void on_slider_pixel_size_valueChanged(int value);
    void on_spin_pixel_size_editingFinished();
    void on_draw_pixels_clicked();

    void on_slider_circle_radius_valueChanged(int value);
    void on_spin_circle_radius_editingFinished();

    void on_slider_rect_width_valueChanged(int value);
    void on_spin_rect_width_editingFinished();

    void on_slider_rect_height_valueChanged(int value);
    void on_spin_rect_height_editingFinished();


    void on_tab_choose_tabBarClicked(int index);


private:
    QColor GetColor_(QColor current_color);
    void SetButtonColor_(QPushButton *button, QColor color);
    void InitSettings_();
    void Update();
    void Draw();

private:
    Ui::MainWindow *ui;
    QColor col_back_;
    QColor col_pixel_;
    float radius_ = 75;
    float radius_pixel_ = 10;
    float width_ = 150;
    float height_ = 150;
    Controller* controller_;

    figure_t figure_;

    // float const kXcenter = 160;
    // float const kYcenter = 160;
    // float const kMinSize = 10;
    // float const kMaxSize = 300;

//protected:
//    /* Define method of base class
//     * */
//    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
