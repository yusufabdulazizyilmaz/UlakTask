//
// Created by SPAK on 1.01.2022.
//

#include <vector>
#include <iterator>
#include "LibraryIndexer.h"
#include "../fileHelper/FileHelper.h"
#include "../fileAnalyzer/FileAnalyzer.h"

LibraryIndexer::LibraryIndexer(const FileAnalyzer& fileAnalyzer)
        :m_fileAnalyzer(fileAnalyzer)
{
    m_inversedIndex = indexLibrary();
}

const std::unordered_map<std::string, std::map<std::string, int>>& LibraryIndexer::getInversedIndex() const
{
    return m_inversedIndex;
}

std::unordered_map<std::string, std::map<std::string, int>> LibraryIndexer::indexLibrary()
{
    for (const auto& txtFilepath: m_fileAnalyzer.getTxtFileVec()) {
        std::ifstream txtFile = FileHelper::openReadFile(txtFilepath.string());
        std::vector<std::string> svec{std::istream_iterator<std::string>{txtFile}, {}};
        std::string referencePath = txtFilepath.string().substr(m_fileAnalyzer.getLibrary().length()+1);
        for (const auto& word: svec) {
            ++m_inversedIndex[word][referencePath];
        }
    }
    return m_inversedIndex;
}