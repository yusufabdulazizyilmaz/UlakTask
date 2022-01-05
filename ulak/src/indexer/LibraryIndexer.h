//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_LIBRARYINDEXER_H
#define ULAK_LIBRARYINDEXER_H

#include <string>
#include <unordered_map>
#include <map>

class FileAnalyzer;

class LibraryIndexer {
    using hashstrmap = std::unordered_map<std::string, std::map<std::string, int>>;
public:
    explicit LibraryIndexer(const FileAnalyzer& fileAnalyzer);

    [[nodiscard]] const hashstrmap& getInversedIndex() const;

private:
    [[nodiscard]] hashstrmap indexLibrary();

    const FileAnalyzer& m_fileAnalyzer;
    hashstrmap m_inversedIndex;
};

#endif //ULAK_LIBRARYINDEXER_H
