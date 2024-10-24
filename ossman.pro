QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fend/uicommon/basedialog.cpp \
    fend/uicommon/emptydialog.cpp \
    fend/uilogin/logindialog.cpp \
    fend/uilogin/uimain.cpp \
    main.cpp

HEADERS += \
    fend/uicommon/basedialog.h \
    fend/uicommon/emptydialog.h \
    fend/uilogin/logindialog.h \
    fend/uilogin/uimain.h

FORMS += \
    fend/uicommon/basedialog.ui \
    fend/uicommon/emptydialog.ui \
    fend/uilogin/logindialog.ui \
    fend/uilogin/uimain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
