PREFIX = /usr
QT              += core widgets concurrent dbus
TEMPLATE         = lib
CONFIG          += plugin c++11 link_pkgconfig
PKGCONFIG       += dtkwidget

INCLUDEPATH += /usr/include/dde-dock
INCLUDEPATH += $$PWD/../../dde-file-manager-lib/interfaces \
#               $$PWD/../../dde-file-manager-lib/gvfs \
               $$PWD/../../dde-file-manager-lib

TARGET          = $$qtLibraryTarget(dde-disk-mount-plugin)
DESTDIR          = $$_PRO_FILE_PWD_/../
DISTFILES       += disk-mount.json

DEFINES += QT_MESSAGELOGCONTEXT

#unix: LIBS += -L$$OUT_PWD/../../dde-file-manager-lib -ldde-file-manager

HEADERS += \
    diskmountplugin.h \
    diskcontrolwidget.h \
    diskpluginitem.h \
    diskcontrolitem.h

SOURCES += \
    diskmountplugin.cpp \
    diskcontrolwidget.cpp \
    diskpluginitem.cpp \
    diskcontrolitem.cpp

target.path = $${PREFIX}/lib/dde-dock/plugins/
INSTALLS += target

include($$PWD/udisks2/udisks2.pri)

RESOURCES += \
    resources.qrc
