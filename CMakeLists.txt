cmake_minimum_required(VERSION 3.0.0)
project(tray VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(tray src/tray.cpp src/raw_tray.c)
target_include_directories(tray
    PUBLIC
    include
)

if(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    message(STATUS "To install appindicator3[ayatana-appindicator3-0.1],  sudo apt install libayatana-appindicator3-dev")
    pkg_check_modules(APPINDICATOR REQUIRED ayatana-appindicator3-0.1)
    target_compile_options(tray PRIVATE ${APPINDICATOR_CFLAGS})
    target_link_libraries(tray PRIVATE ${APPINDICATOR_LIBRARIES})
    target_link_directories(tray PRIVATE ${APPINDICATOR_LIBRARY_DIRS})

    pkg_check_modules(GTK REQUIRED     gtk+-3.0)
    target_compile_options(tray PRIVATE ${GTK_CFLAGS})
    target_link_libraries(tray PRIVATE ${GTK_LIBRARIES})
    target_link_directories(tray PRIVATE ${GTK_LIBRARY_DIRS})
elseif(APPLE)
    target_link_libraries(tray PRIVATE "-framework Cocoa")
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

add_executable(pw_tray example/example_pp.cpp)
set_target_properties(pw_tray PROPERTIES CXX_STANDARD 17)
target_link_libraries(pw_tray PRIVATE tray)

endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
