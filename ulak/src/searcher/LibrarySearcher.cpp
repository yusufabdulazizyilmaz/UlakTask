//
// Created by SPAK on 1.01.2022.
//

#include <iostream>
#include <string_view>
#include "LibrarySearcher.h"
#include "../util/FileHelper.h"

LibrarySearcher::LibrarySearcher(std::string searchWord, std::string invertedIndexPath)
        :m_searchWord{std::move(searchWord)}, m_invertedIndexPath{std::move(invertedIndexPath)}
{
    search();
}

void LibrarySearcher::search()
{
    auto ssUnorderedMap = FileHelper::deSerialize(m_invertedIndexPath);
    if (auto iter = ssUnorderedMap.find(m_searchWord); iter!=ssUnorderedMap.end())
        splitWriter(iter->second, '|');
    else
        std::cout << m_searchWord << "is not found! \n";
}

void LibrarySearcher::splitWriter(const std::string_view& searchResult, const char& delimeter)
{
    for (std::size_t pos = 0; pos<searchResult.length();) {
        if (std::size_t idx = searchResult.find(delimeter, pos); idx!=std::string::npos) {
            std::cout << searchResult.substr(pos, idx-pos) << "\n";
            pos = idx+1;
        }
    }
}