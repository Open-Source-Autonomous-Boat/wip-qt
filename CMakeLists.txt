cmake_minimum_required(VERSION 3.10.0)

project(osab-qt VERSION 0.0.1 LANGUAGES CXX)

# Directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(FORM_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
include_directories(${SOURCE_DIR})
include_directories(${FORM_DIR})
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES
                  "${FORM_DIR}/*.ui"
                  "${FORM_DIR}/*.qrc"
                  "${INCLUDE_DIR}/*.h"
                  "${SOURCE_DIR}/*.cpp"
)

# Settings

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOQUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_IMPORT_SOURCE_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 COMPONENTS Widgets Core Sql REQUIRED)

if (WIN32)
   add_executable(osab-qt WIN32 ${SOURCES})
elseif (UNIX)
   add_executable(osab-qt ${SOURCES})
endif()

target_link_libraries(osab-qt Qt6::Widgets Qt6::Core Qt6::Sql)
