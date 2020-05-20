cmake_minimum_required(VERSION 3.5)

project(Screman LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Screman
    main.cpp
    bgwgt.cpp
    bgwgt.h
    draftwgt.cpp
    draftwgt.h
    appbtn.cpp
    appbtn.h
    toolpanel.cpp
    toolpanel.h
	toolbtn.cpp
	toolbtn.h
    resource.qrc
)

target_link_libraries(Screman PRIVATE Qt5::Widgets)
