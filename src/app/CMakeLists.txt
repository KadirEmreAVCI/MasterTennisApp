file(GLOB_RECURSE SOURCES   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS   ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE UI_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

qt_add_resources(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/Resource.qrc)

qt_add_executable(${PROJECT_NAME} 
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        ${PROJECT_NAME}_lib
)