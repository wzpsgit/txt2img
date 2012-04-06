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
        boxbuilder.h \
        log.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    textbold.png

QMAKE_CXXFLAGS += -std=c++0x
OBJECTS_DIR += GeneratedFiles
MOC_DIR += GeneratedFiles
UI_DIR += GeneratedFiles
RCC_DIR += GeneratedFiles

