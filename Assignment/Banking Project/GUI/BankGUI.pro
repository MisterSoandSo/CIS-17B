TEMPLATE = app
TARGET = Qt_Beg_Project

QT = core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets

HEADERS += \
    account.h \
    checking.h \
    login.h \
    mainwindow.h \
    saving.h \
    user.h \
    database.h


SOURCES += \
    account.cpp \
    checking.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    saving.cpp \
    user.cpp \
    database.cpp

DISTFILES += \
    accountinfo.txt

