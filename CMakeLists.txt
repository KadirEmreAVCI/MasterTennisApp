cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(TennisDesktopApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)
qt_standard_project_setup()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
file(GLOB UI_FILES *.ui)
file(GLOB RESOURCE_FILES *.qrc)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${UI_FILES}
    ${RESOURCE_FILES}
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/uic
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
      Qt6::Core
      Qt6::Gui
      Qt6::Widgets
      Qt6::Sql
)