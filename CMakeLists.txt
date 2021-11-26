cmake_minimum_required(VERSION 3.10.0)

project(osab-qt VERSION 0.0.1 LANGUAGES CXX)

# Directories
set(OSAB_SOURCE_DIR "src")
set(OSAB_INCLUDE_DIR "include")
set(OSAB_QML_DIR "qml")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(osab-qt PUBLIC ${OSAB_SOURCE_DIR})
include_directories(osab-qt PUBLIC ${OSAB_INCLUDE_DIR})
include_directories(osab-qt PUBLIC ${OSAB_QML_DIR})

# Sauce
file(GLOB_RECURSE SOURCES
  #"${OSAB_QML_DIR}/*.qml"
                  "${OSAB_QML_DIR}/*.qrc"
                  "${OSAB_INCLUDE_DIR}/*.h"
                  "${OSAB_SOURCE_DIR}/*.cpp"

)
# Resources

add_subdirectory("lib/vis_parser")

set(QT_COMP
    Quick
    Core
    Sql
    Qml
    Widgets
    QuickControls2
    Positioning
    WebEngineQuick
    ShaderTools)

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Sql
    Qt6::Qml
    Qt6::Widgets
    Qt6::Positioning
    Qt6::WebEngineQuick
    Qt6::QuickControls2)
# Settings

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_IMPORT_SOURCE_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(QT_QML_DEBUG ON)

message(${SOURCES})
find_package(Qt6 COMPONENTS ${QT_COMP} REQUIRED)

qt6_add_executable(osab-qt WIN32 ${SOURCES})

target_link_libraries(osab-qt PUBLIC ${QT_LIB} VISL)


