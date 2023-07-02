cmake_minimum_required(VERSION 3.0.0)
project(tray VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(tray src/tray.cpp src/raw_tray.c )
target_include_directories(tray
    PUBLIC
    include
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
add_executable(tray_test example/example.c)
target_link_libraries(tray_test PRIVATE tray)

add_executable(traypp_test example/example_pp.cpp)
target_link_libraries(traypp_test PRIVATE tray)

add_custom_command(
    TARGET tray_test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CMAKE_SOURCE_DIR}/example/
            ${CMAKE_BINARY_DIR}/
)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
