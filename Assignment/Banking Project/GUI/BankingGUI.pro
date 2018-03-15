TEMPLATE = app
TARGET = Qt_Beg_Project

QT = core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets

HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    main.cpp
