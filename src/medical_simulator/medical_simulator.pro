######################################################################
# Automatically generated by qmake (3.1) Wed Aug 2 11:19:36 2023
######################################################################

TEMPLATE = app
TARGET = medical_simulator
INCLUDEPATH += .
QT += widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += controller/controller.h \
           model/circle.h \
           model/figure.h \
           model/model.h \
           model/rectangle.h \
           view/mainwindow.h \
           view/paintwidget.h
FORMS += view/mainwindow.ui
SOURCES += main.cpp view/mainwindow.cpp view/paintwidget.cpp
