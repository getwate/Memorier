######################################################################
# Automatically generated by qmake (3.1) Fri Nov 27 18:01:45 2020
######################################################################

TEMPLATE = app
TARGET = Memorier
INCLUDEPATH += . \
               ./APIs \
               ./tools \
               ./libraryPage \
               ./LoginAndMainpage \
               ./NotonlyAddCard \
               ./NotonlyAddCard/AddCard \
               ./NotonlyAddCard/Cards 
DESTDIR += ./debug
QT += widgets core gui
QT += sql
QT += network
CONFIG += debug

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += APIs/APIRequest.h \
           LoginAndMainpage/loginwindow.h \
           LoginAndMainpage/mainwindow.h \
           LoginAndMainpage/signupwindow.h \
           libraryPage/libwindow.h \
           tools/LoginInfo.h \
           tools/tools.h \
           AddCard/addcard.h \
           AddCard/addcardmain.h \
           AddCard/addchoices.h \
           AddCard/addtext.h \
           Cards/Card.h \
           Cards/Cards.h \
           Cards/Choices.h \
           Cards/Plain.h \
           Cards/Text.h \
           Cards/Word.h
FORMS += LoginAndMainpage/loginwindow.ui \
         LoginAndMainpage/mainwindow.ui \
         LoginAndMainpage/signupwindow.ui \
         AddCard/addcard.ui \
         AddCard/addcardmain.ui \
         AddCard/addchoices.ui \
         AddCard/addtext.ui \
         libraryPage/libwindow.ui
SOURCES += main.cpp \
           APIs/APIRequest.cpp \
           LoginAndMainpage/loginwindow.cpp \
           LoginAndMainpage/main_login.cpp \
           LoginAndMainpage/mainwindow.cpp \
           LoginAndMainpage/signupwindow.cpp \
           libraryPage/libwindow.cpp \
           tools/LoginInfo.cpp \
           tools/tools.cpp \
           AddCard/addcard.cpp \
           AddCard/addcardmain.cpp \
           AddCard/addchoices.cpp \
           AddCard/addtext.cpp \
           Cards/Card.cpp \
           Cards/Choices.cpp \
           Cards/Plain.cpp \
           Cards/Text.cpp \
           Cards/Word.cpp
RESOURCES += LoginAndMainpage/assets.qrc \
             libraryPage/assets_lib.qrc
