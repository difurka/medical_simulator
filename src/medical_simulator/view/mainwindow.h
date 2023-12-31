#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

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

private:
    Ui::MainWindow *ui;
    QColor col_back_ = "#F1CFED";
    QColor col_pixel_ = Qt::blue;
};
#endif // MAINWINDOW_H
