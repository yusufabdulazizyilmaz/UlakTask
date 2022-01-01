//
// Created by SPAK on 1.01.2022.
//

#include "FileAnalyzer.h"
FileAnalyzer::FileAnalyzer(std::string library)
        :m_library(std::move(library))
{
    m_txtFileVec = fileAnalizer();
}
const std::string&
FileAnalyzer::getLibrary() const
{
    return m_library;
}
const std::vector<std::filesystem::path>&
FileAnalyzer::getTxtFileVec() const
{
    return m_txtFileVec;
}
std::vector<std::filesystem::path>
FileAnalyzer::fileAnalizer()
{
    auto dirIter = std::filesystem::recursive_directory_iterator{m_library};
    copy_if(begin(dirIter), end(dirIter), back_inserter(m_txtFileVec), [](auto& entry) {
        return entry.path().extension()==".txt";
    });
    return m_txtFileVec;
}