cmake_minimum_required(VERSION 3.10.0)

project(osab-qt VERSION 0.0.1 LANGUAGES CXX)

# Directories
set(OSAB_SOURCE_DIR "src")
set(OSAB_INCLUDE_DIR "include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(osab-qt PUBLIC ${OSAB_SOURCE_DIR})
include_directories(osab-qt PUBLIC ${OSAB_INCLUDE_DIR})

# Sauce
file(GLOB_RECURSE SOURCES
                  "${OSAB_SOURCE_DIR}/*.qml"
                  "${OSAB_SOURCE_DIR}/*.qrc"
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
    ShaderTools)

set(QT_LIB
    Qt6::Core
    Qt6::Quick
    Qt6::Sql
    Qt6::Qml
    Qt6::Widgets
    Qt6::QuickControls2)
# Settings

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOQUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_IMPORT_SOURCE_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 COMPONENTS ${QT_COMP} REQUIRED)

if (WIN32)
   add_executable(osab-qt WIN32 ${SOURCES})
elseif (UNIX)
   add_executable(osab-qt ${SOURCES})
endif()

target_link_libraries(osab-qt PUBLIC ${QT_LIB} VISL)

