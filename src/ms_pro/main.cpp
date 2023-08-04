#include "view/mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include "model/model.h"
#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    Controller controller(&model);
    MainWindow window(&controller);
    window.setWindowTitle("Симулятор");
    window.show();
    return a.exec();
}
