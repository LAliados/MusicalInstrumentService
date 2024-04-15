cmake_minimum_required(VERSION 3.27)
project(QtTest2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(untitled3 main.cpp
        Headers/UserWindow/userwindow.cpp
        Headers/UserWindow/userwindow.h
        Headers/UserWindow/userwindow.ui
        Headers/LoginWindow/loginwindow.cpp
        Headers/LoginWindow/loginwindow.h
        Headers/LoginWindow/loginwindow.ui
        Headers/AdminWindow/adminwindow.cpp
        Headers/AdminWindow/adminwindow.h
        Headers/AdminWindow/adminwindow.ui
        Headers/Application/Application.cpp
        Headers/Application/Application.h)
target_link_libraries(untitled3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql

)

