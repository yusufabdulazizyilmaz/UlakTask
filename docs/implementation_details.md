# Implemantation Details

In the CommandLine class, the command line utility is parsed with logical controls.

In the FileAnalyzer class, the absolute path of the documents with txt extension is vectored.

In the Indexer class, the vector that holds the files with the txt extension is indexed. 

Here, the data structure std::unordered_map<std::string, std::map<std::string, int>> is used.

In the FileHelper class, the data structure holding the indexing is written to the invertedIndex.txt file with the serialize function.

In the LibrarySearcher class, the data in the invertedIndex.txt file is transferred to the std::unordered_map<std::string, std::string> data structure with the deserialize function in the FileHelper class and the search is performed.

