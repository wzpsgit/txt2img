#-------------------------------------------------
#
# Project created by QtCreator 2012-03-11T13:28:33
#
#-------------------------------------------------

QT       += core gui

TARGET = txt2img
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    boxbuilder.cpp

HEADERS  += mainwindow.h \
    setupdialog.h \
    boxbuilder.h \
    log.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    textbold.png
