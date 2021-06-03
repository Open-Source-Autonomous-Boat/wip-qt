cmake_minimum_required(VERSION 3.10.0)

project(osab-qt VERSION 0.0.1 LANGUAGES CXX)

# Directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

# Sauce
file(GLOB_RECURSE SOURCES
                  "${SOURCE_DIR}/*.qml"
                  "${SOURCE_DIR}/*.qrc"
                  "${INCLUDE_DIR}/*.h"
                  "${SOURCE_DIR}/*.cpp"
)

# Resources

set(QT_COMP
    Quick
    Core
    Sql
    Qml
    QuickControls2)

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Sql
    Qt6::Qml
    Qt6::QuickControls2)
# Settings

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOQUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_IMPORT_SOURCE_DIR ON)
set(CMAKE_BUILD_TYPE Debug)
set(QML_IMPORT_NAME "com.osab.qt")
set(QML_IMPORT_MAJOR_VERSION 1)

find_package(Qt6 COMPONENTS ${QT_COMP} REQUIRED)

if (WIN32)
   add_executable(osab-qt WIN32 ${SOURCES})
elseif (UNIX)
   add_executable(osab-qt ${SOURCES})
endif()

target_link_libraries(osab-qt ${QT_LIB})
