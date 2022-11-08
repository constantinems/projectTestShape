#-------------------------------------------------
#
# Project created by QtCreator 2022-08-31T16:04:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectTestShape
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

INCLUDEPATH += "include/"

SOURCES += \
    src/circle.cpp \
    src/ellipse.cpp \
    src/i_shape.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/rectangle.cpp \
    src/square.cpp \
    src/triangle.cpp \
    src/polygon.cpp \
    src/i_color.cpp

HEADERS += \
    include/circle.h \
    include/ellipse.h \
    include/i_shape.h \
    include/mainwindow.h \
    include/rectangle.h \
    include/square.h \
    include/triangle.h \
    include/i_color.h \
    include/red.h \
    include/green.h \
    include/polygon.h \
    include/equilateral_polygon.h

FORMS += \
    form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
