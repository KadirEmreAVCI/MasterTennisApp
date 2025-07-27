cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(TennisDesktopApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "D:/Qt/6.7.0/msvc2019_64")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)
qt_standard_project_setup()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../out")

option(RUN_TESTS "Build and run unit tests" OFF)
if(RUN_TESTS)
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(extern/googletest)

    enable_testing()
    include(GoogleTest)

    file(GLOB_RECURSE APP_SOURCES src/*.cpp src/*.h moc/*.cpp rcc/*.cpp)
    list(REMOVE_ITEM APP_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
    file(GLOB_RECURSE TEST_SOURCES test/src/*.cpp)
    file(GLOB UI_FILES *.ui)
    file(GLOB RESOURCE_FILES *.qrc)

    add_executable(${PROJECT_NAME}_test
        ${APP_SOURCES}
        ${TEST_SOURCES}
        ${UI_FILES}
        ${RESOURCE_FILES}
    )

    target_include_directories(${PROJECT_NAME}_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/inc
        ${CMAKE_SOURCE_DIR}/uic
        ${CMAKE_SOURCE_DIR}/test/inc
    )

    target_link_libraries(${PROJECT_NAME}_test
    PUBLIC
        gtest_main    
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Sql
    )

    gtest_discover_tests(${PROJECT_NAME}_test)

else()

    file(GLOB_RECURSE APP_SOURCES src/*.cpp src/*.h moc/*.cpp rcc/*.cpp)
    file(GLOB UI_FILES *.ui)
    file(GLOB RESOURCE_FILES *.qrc)

    add_executable(${PROJECT_NAME}
        ${APP_SOURCES}
        ${UI_FILES}
        ${RESOURCE_FILES}
    )

    target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/inc
        ${CMAKE_SOURCE_DIR}/uic
    )

    target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Sql
    )
endif()

