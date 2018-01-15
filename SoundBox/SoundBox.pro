#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T18:29:20
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = VideoPlayer
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
    colorkeyerhsv.cpp

HEADERS  += videoplayer.h \
    colorkeyerhsv.h

FORMS    += videoplayer.ui

include(../drumstick/drumstick.pro)
include(../opencv/videoengine.pri)

RESOURCES += \
    img.qrc
