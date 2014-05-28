#-------------------------------------------------
#
# Project created by QtCreator 2014-05-23T17:25:15
#
#-------------------------------------------------

QT       += core gui sql phonon webkit

TARGET = MySqlServer
TEMPLATE = app


SOURCES += main.cpp\
        src\mainwindow.cpp \
    src\sqlservermanage.cpp \
    src\login.cpp \
    src\selectsql.cpp

HEADERS  += src\mainwindow.h \
    src\sqlservermanage.h \
    src\login.h \
    src\selectsql.h

FORMS    += src\mainwindow.ui \
    src\login.ui \
    src\selectsql.ui

RESOURCES += \
    qm.qrc

