######################################################################
# Automatically generated by qmake (3.1) Mon Aug 7 16:33:53 2023
######################################################################

TEMPLATE = app
TARGET = ms_pro
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
           model/model.h \
           utils/utils.h \
           view/mainwindow.h \
           view/paintwidget.h
FORMS += view/mainwindow.ui
SOURCES += main.cpp \
           controller/controller.cpp \
           view/mainwindow.cpp \
           view/paintwidget.cpp
