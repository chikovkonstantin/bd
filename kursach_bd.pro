QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
INCLUDEPATH += C:\Qt\Docs\Qt-6.6.1\qtsql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwindow.cpp \
    deletewindow.cpp \
    editwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    viewwindow.cpp

HEADERS += \
    addwindow.h \
    deletewindow.h \
    editwindow.h \
    mainwindow.h \
    viewwindow.h

FORMS += \
    addwindow.ui \
    deletewindow.ui \
    editwindow.ui \
    mainwindow.ui \
    viewwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
