cmake_minimum_required(VERSION 3.15)
project(ulak)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_definitions(-DROOT_PATH="${CMAKE_SOURCE_DIR}")

add_executable(cli ${SOURCES})

include_directories(ulak)
add_subdirectory(ulak)

target_link_libraries(cli ulak)
add_subdirectory(Google_tests)
