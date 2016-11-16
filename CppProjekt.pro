QT       += core
QT       -= gui
QT       += webkit webkitwidgets
QT       += sql
CONFIG   += console
CONFIG   -= x86_64
SOURCES += main.cpp
QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
QMAKE_LFLAGS += -mmacosx-version-min=10.7
CONFIG += c++11

TARGET = CppProjekt
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=
