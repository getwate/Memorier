######################################################################
# Automatically generated by qmake (3.1) Wed Nov 18 23:39:54 2020
######################################################################

TEMPLATE = app
TARGET = LoginAndMainpage
INCLUDEPATH += .
QT += widgets core gui
QT += sql
CONFIG += debug


# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += LoginInfo.h loginwindow.h mainwindow.h signupwindow.h tools.h
FORMS += loginwindow.ui mainwindow.ui signupwindow.ui
SOURCES += LoginInfo.cpp \
           loginwindow.cpp \
           main.cpp \
           mainwindow.cpp \
           signupwindow.cpp \
           tools.cpp
