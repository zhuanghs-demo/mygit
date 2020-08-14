#-------------------------------------------------
#
# Project created by QtCreator 2020-06-29T15:31:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo
TEMPLATE = app
QMAKE_CXXFLAGS  += -std=c++11
CONFIG += c++11

SOURCES += main.cpp\
        longestpalindrome.cpp \
    demo.cpp \
    demofactory.cpp \
    findmediansortedarrays.cpp

HEADERS  += longestpalindrome.h \
    demo.h \
    demofactory.h \
    findmediansortedarrays.h

FORMS    += \
    demo.ui
