#include <iostream>
#include "src/fileAnalyzer/FileAnalyzer.h"
#include "src/commandLineUtility/CommandLine.h"
#include "src/exception/BadCommit.h"
#include "src/indexer/LibraryIndexer.h"

int main(int argc, char** argv)
{
    CommandLine commendUtility = CommandLine(argc, argv);
    try {
        commendUtility.parse();
    }
    catch (BadCommit& badcommit) {
        badcommit.addInfo();
        return -1;
    }
    switch (commendUtility.getCommand()) {
    case COMMAND_TYPE::INDEX: {
        FileAnalyzer fileAnalyzer(commendUtility.getContext());
        LibraryIndexer inversedIndex{fileAnalyzer};
    }
        break;
    case COMMAND_TYPE::SEARCH:
        std::cout << "search";
        break;
    }

    return 0;
}
