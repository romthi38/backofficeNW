#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T14:36:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = backOfficeNewWorld
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    windowmenu.cpp \
    windowrayon.cpp \
    windowtypeproduit.cpp \
    windowproduit.cpp \
    windowmoderation.cpp \
    windowapercu.cpp

HEADERS  += mainwindow.h \
    windowmenu.h \
    windowrayon.h \
    windowtypeproduit.h \
    windowproduit.h \
    windowmoderation.h \
    windowapercu.h

FORMS    += mainwindow.ui \
    windowmenu.ui \
    windowrayon.ui \
    windowtypeproduit.ui \
    windowproduit.ui \
    windowmoderation.ui \
    windowapercu.ui
