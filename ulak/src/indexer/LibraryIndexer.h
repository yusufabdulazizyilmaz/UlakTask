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
public:
    explicit LibraryIndexer(const FileAnalyzer& fileAnalyzer);

    [[nodiscard]] const std::unordered_map<std::string, std::map<std::string, int>>& getInversedIndex() const;

private:
    [[nodiscard]] std::unordered_map<std::string, std::map<std::string, int>> indexLibrary();

    const FileAnalyzer& m_fileAnalyzer;
    std::unordered_map<std::string, std::map<std::string, int>> m_inversedIndex;
};

#endif //ULAK_LIBRARYINDEXER_H
