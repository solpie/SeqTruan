QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app
TARGET = SeqTruan
INCLUDEPATH += .

# Input
HEADERS += model/TrackModel.hpp view/SeqTruanWin.h view/viewport/ViewPort.h
SOURCES += main.cpp \
           model/TrackModel.cpp \
           view/SeqTruanWin.cpp \
           view/viewport/ViewPort.cpp
