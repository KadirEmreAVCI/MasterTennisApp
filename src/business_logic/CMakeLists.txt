file(GLOB_RECURSE SOURCES   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

qt_add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}_lib 
    PUBLIC
        ${PROJECT_NAME}_utility
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Sql
)

target_include_directories(${PROJECT_NAME}_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})