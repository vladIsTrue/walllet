cmake_minimum_required(VERSION 3.16)

project(wallet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp

        gui/mainwindow.h gui/mainwindow.cpp gui/mainwindow.ui
        gui/sendtab.h gui/sendtab.cpp gui/sendtab.ui
        gui/newwallet.h gui/newwallet.cpp gui/newwallet.ui
        gui/info.h gui/info.cpp gui/info.ui
        gui/changepass.h gui/changepass.cpp gui/changepass.ui

        logic/iwallet.h
        logic/wallet.h logic/wallet.cpp
        logic/utils.h logic/utils.cpp
        logic/paymentsystem.h logic/paymentsystem.cpp

        manager.h manager.cpp
)

add_executable(wallet
    ${PROJECT_SOURCES}
)

target_link_libraries(wallet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gui)
