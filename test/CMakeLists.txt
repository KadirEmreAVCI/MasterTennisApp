file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

qt_add_executable(${PROJECT_NAME}_test
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME}_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}_test
    PUBLIC
        gtest_main    
        ${PROJECT_NAME}_lib
)

gtest_discover_tests(${PROJECT_NAME}_test)