TEMPLATE = app
TARGET = Qt_Beg_Project

QT = core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets

HEADERS += \
    mainwindow.h \
    user.h \
    login.h \
    account.h \
    saving.h \
    checking.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    user.cpp \
    login.cpp \
    account.cpp \
    saving.cpp \
    checking.cpp
