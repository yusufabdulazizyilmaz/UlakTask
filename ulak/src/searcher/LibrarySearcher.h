//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_LIBRARYSEARCHER_H
#define ULAK_LIBRARYSEARCHER_H

#include <string>
class LibrarySearcher {
public:
    LibrarySearcher(std::string searchWord, std::string invertedIndexPath);

private:
    void search();

    void splitWriter(const std::string_view& searchResult, const char& delimeter);

    std::string m_searchWord;
    std::string m_invertedIndexPath;

};

#endif //ULAK_LIBRARYSEARCHER_H
