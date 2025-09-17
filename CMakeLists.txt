cmake_minimum_required(VERSION 3.21)
project(MasterTennisApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "D:/Qt/6.7.0/msvc2019_64")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

qt6_standard_project_setup()

add_subdirectory(src/utility)
add_subdirectory(src/business_logic)
add_subdirectory(src/app)
    
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(extern/googletest)

enable_testing()
include(GoogleTest)

add_subdirectory(test)