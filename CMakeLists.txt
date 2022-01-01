cmake_minimum_required(VERSION 3.21)
project(ulak)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_executable(ulak_run ${SOURCES})

include_directories(ulak)
add_subdirectory(ulak)

target_link_libraries(ulak_run ulak)
add_subdirectory(Google_tests)
