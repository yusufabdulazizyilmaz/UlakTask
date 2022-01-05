project(ulak)
set(CMAKE_CXX_STANDARD 17)
set(HEADERS
        src/fileAnalyzer/FileAnalyzer.h
        src/commandLineUtility/CommandLine.h
        src/exception/BadCommit.h
        src/indexer/LibraryIndexer.h
        src/util/FileHelper.h
        src/searcher/LibrarySearcher.h)
set(SOURCES
        src/fileAnalyzer/FileAnalyzer.cpp
        src/commandLineUtility/CommandLine.cpp
        src/exception/BadCommit.cpp
        src/indexer/LibraryIndexer.cpp
        src/util/FileHelper.cpp
        src/searcher/LibrarySearcher.cpp)

add_library(ulak STATIC ${SOURCES} ${HEADERS})