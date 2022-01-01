#include <iostream>
#include "src/fileAnalyzer/FileAnalyzer.h"
#include "src/commandLineUtility/CommandLine.h"
#include "src/exception/BadCommit.h"
#include "src/indexer/LibraryIndexer.h"
#include "src/fileHelper/FileHelper.h"
#include "src/searcher/LibrarySearcher.h"

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
        FileHelper::serialize(inversedIndex.getInversedIndex(), CommandLine::m_IndexedFile);
    }
        break;
    case COMMAND_TYPE::SEARCH:
        LibrarySearcher{commendUtility.getContext(), CommandLine::m_IndexedFile};
        break;
    }
    return 0;
}
