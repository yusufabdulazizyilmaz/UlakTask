project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        CommandLineTest.cpp
        FileAnalyzerTest.cpp
        FileHelperTest.cpp
        LibaryIndexerTest.cpp)
target_link_libraries(Google_Tests_run ulak)
target_link_libraries(Google_Tests_run gtest gtest_main)
