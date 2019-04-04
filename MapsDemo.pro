#-------------------------------------------------
#
# Project created by QtCreator 
#
#-------------------------------------------------

QT       += core gui location positioning serialport testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = MapsDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += "C:/QMapControl/QMapControl-develop/debug/include"

win32: LIBS += "C:/QMapControl/QMapControl-develop/debug/lib/qmapcontrold1.lib"
#LIBS += "C:\\QMapControl\\QMapControl-develop\\debug\\lib\\qmapcontrold1.lib"
#win32: LIBS += -L D:/Tools/QMapControl/QMapControl-develop/debug/lib -lqmapcontrold1

#win32:CONFIG(release, debug|release): LIBS += -LD:/QMapControl/QMapControl-develop/debug/lib/ -lqmapcontrold1
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/QMapControl/QMapControl-develop/debug/lib/ -lqmapcontrold1d
#else:unix: LIBS += -LD:/QMapControl/QMapControl-develop/debug/lib/ -lqmapcontrold1

#INCLUDEPATH += C:/QMapControl/QMapControl-develop/debug/include
#DEPENDPATH += C:/QMapControl/QMapControl-develop/debug/include

DISTFILES += \
    C:/QMapControl/QMapControl-develop/debug/lib/qmapcontrold1.pdb \
    C:/QMapControl/QMapControl-develop/debug/lib/qmapcontrold1.dll \
    C:/QMapControl/QMapControl-develop/debug/bin/qmapcontrold1.exp \
    C:/QMapControl/QMapControl-develop/debug/bin/qmapcontrold1.ilk \
    C:/QMapControl/QMapControl-develop/debug/bin/qmapcontrold1.pdb \
    C:/QMapControl/QMapControl-develop/debug/bin/qmapcontrold1.lib \
    C:/QMapControl/QMapControl-develop/debug/bin/qmapcontrold1.dll
