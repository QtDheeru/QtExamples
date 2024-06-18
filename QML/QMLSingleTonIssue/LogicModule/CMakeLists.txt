#logicmodule/CMakeLists.txt
project(logicmodule VERSION 0.1 LANGUAGES CXX)

qt_add_library(${PROJECT_NAME} SHARED)

qt6_add_qml_module(${PROJECT_NAME}
    URI Main
    VERSION 1.0
    NO_PLUGIN
    RESOURCE_PREFIX "/qt/qml/dheeru"
    QML_FILES
        Main.qml
    SOURCES
        MySingleTon.h
    QML_FILES TestStatic.qml
    SOURCES TestStaticLib.h TestStaticLib.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        .
)
