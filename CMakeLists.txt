cmake_minimum_required(VERSION 3.21)
project(ulak)

set(CMAKE_CXX_STANDARD 17)
set(HEADERS
        src/fileAnalyzer/FileAnalyzer.h
        src/commandLineUtility/CommandLine.h
        src/exception/BadCommit.h
        src/indexer/LibraryIndexer.h
        src/fileHelper/FileHelper.h)
set(SOURCES
        main.cpp
        src/fileAnalyzer/FileAnalyzer.cpp
        src/commandLineUtility/CommandLine.cpp
        src/exception/BadCommit.cpp
        src/indexer/LibraryIndexer.cpp
        src/fileHelper/FileHelper.cpp)

add_executable(${PROJECT_NAME}
        ${SOURCES} ${HEADERS})
