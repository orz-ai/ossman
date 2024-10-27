cmake_minimum_required(VERSION 3.24)
project(ossman)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# FIXME change to your local's CMAKE_PREFIX_PATH
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\msvc2019_64")

# Include all directories at the same level as the CMakeLists.txt file.
include_directories(.)

add_executable(ossman
        bend/mgr/cloudmanager.cpp
        bend/mgr/cloudmanager.h
        bend/service/cloud/commoncloud.h
        bend/service/cloud/coscloud.cpp
        bend/service/cloud/coscloud.h
        bend/service/cloud/kodocloud.cpp
        bend/service/cloud/kodocloud.h
        bend/service/cloud/osscloud.cpp
        bend/service/cloud/osscloud.h
        bend/service/cloud/s3cloud.cpp
        bend/service/cloud/s3cloud.h
        bend/service/config/versionconfig.cpp
        bend/service/config/versionconfig.h
        bend/service/log/basiclogger.cpp
        bend/service/log/basiclogger.h
        config/baseexception.cpp
        config/baseexception.h
        config/common.h
        config/global.h
        config/loggerproxy.cpp
        config/loggerproxy.h
        config/versioncmd.cpp
        config/versioncmd.h
        fend/uicommon/basedialog.cpp
        fend/uicommon/basedialog.h
        fend/uicommon/emptydialog.cpp
        fend/uicommon/emptydialog.h
        fend/uilogin/logindialog.cpp
        fend/uilogin/logindialog.h
        fend/uilogin/uimain.cpp
        fend/uilogin/uimain.h
        helper/filehelper.cpp
        helper/filehelper.h
        middle/model/cloudmodel.cpp
        middle/model/cloudmodel.h
        middle/model/dbmodel.h
        middle/signal/signalmanager.cpp
        middle/signal/signalmanager.h
        middle/globalmanager.cpp
        middle/globalmanager.h
        plugin/pluginmanager.cpp
        plugin/pluginmanager.h
        main.cpp)

target_link_libraries(ossman Qt5::Core Qt5::Gui Qt5::Widgets)
