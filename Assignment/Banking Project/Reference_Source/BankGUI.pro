TEMPLATE = app
TARGET = Qt_Beg_Project

QT = core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets

HEADERS += \
    account.h \
    checking.h \
    mainwindow.h \
    saving.h \
    user.h \
    sav_dep_amount.h \
    sav_wit_amount.h \
    transferwindow.h \
    withdrawwindow.h \
    che_dep_amount.h \
    che_wit_amount.h \
    depositwindow.h \
    historywindow.h


SOURCES += \
    account.cpp \
    checking.cpp \
    main.cpp \
    mainwindow.cpp \
    saving.cpp \
    user.cpp \
    sav_dep_amount.cpp \
    sav_wit_amount.cpp \
    transferwindow.cpp \
    withdrawwindow.cpp \
    che_dep_amount.cpp \
    che_wit_amount.cpp \
    depositwindow.cpp \
    historywindow.cpp

DISTFILES += \
    accountinfo.txt

