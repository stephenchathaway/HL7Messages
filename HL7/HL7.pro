#-------------------------------------------------
#
# Project created by QtCreator 2015-06-17T10:52:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HL7
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hl7Message.cpp \
    hl7File.cpp \
    hl7Field.cpp

HEADERS  += mainwindow.h \
    hl7Message.h \
    hl7File.h \
    hl7Field.h

FORMS    += mainwindow.ui
