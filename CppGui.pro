#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T15:28:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CppGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dodajnaczepe.cpp \
    dodajciagnik.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dodajnaczepe.h \
    dodajciagnik.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dodajnaczepe.ui \
    dodajciagnik.ui

QT       += webkit webkitwidgets
QT       += sql
CONFIG   += console
CONFIG   -= x86_64
QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
QMAKE_LFLAGS += -mmacosx-version-min=10.7
CONFIG += c++11
CONFIG -= app_bundle
