#include "ulak/src/fileAnalyzer/FileAnalyzer.h"
#include "ulak/src/commandLineUtility/CommandLine.h"
#include "ulak/src/exception/BadCommit.h"
#include "ulak/src/indexer/LibraryIndexer.h"
#include "ulak/src/util/FileHelper.h"
#include "ulak/src/searcher/LibrarySearcher.h"

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
    case CommandLine::COMMAND_TYPE::INDEX: {
        FileAnalyzer fileAnalyzer(commendUtility.getContext());
        LibraryIndexer inversedIndex{fileAnalyzer};
        FileHelper::serialize(inversedIndex.getInversedIndex(), FileHelper::getInvertedFilePath());
    }
        break;
    case CommandLine::COMMAND_TYPE::SEARCH:
        LibrarySearcher{commendUtility.getContext(), FileHelper::getInvertedFilePath()};
        break;
    }
    return 0;
}
