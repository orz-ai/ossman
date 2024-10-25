QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bend/service/log/basiclogger.cpp \
    config/loggerproxy.cpp \
    fend/uicommon/basedialog.cpp \
    fend/uicommon/emptydialog.cpp \
    fend/uilogin/logindialog.cpp \
    fend/uilogin/uimain.cpp \
    helper/filehelper.cpp \
    main.cpp \
    middle/globalmanager.cpp \
    middle/model/cloudmodel.cpp \
    middle/signal/signalmanager.cpp

HEADERS += \
    bend/service/log/basiclogger.h \
    config/common.h \
    config/global.h \
    config/loggerproxy.h \
    fend/uicommon/basedialog.h \
    fend/uicommon/emptydialog.h \
    fend/uilogin/logindialog.h \
    fend/uilogin/uimain.h \
    helper/filehelper.h \
    middle/globalmanager.h \
    middle/model/cloudmodel.h \
    middle/model/dbmodel.h \
    middle/signal/signalmanager.h

FORMS += \
    fend/uicommon/basedialog.ui \
    fend/uicommon/emptydialog.ui \
    fend/uilogin/logindialog.ui \
    fend/uilogin/uimain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
