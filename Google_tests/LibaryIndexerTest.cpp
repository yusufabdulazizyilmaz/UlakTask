
//
// Created by yusufyilmaz on 3.01.2022.
//
#include "gtest/gtest.h"
#include "src/indexer/LibraryIndexer.h"
#include "src/fileAnalyzer/FileAnalyzer.h"

TEST(LibraryIndexerTest, getHashStrMap)
{
    //Arrange
    std::stringstream ss;
    char seperator = static_cast<char>(std::filesystem::path::preferred_separator);
    ss << ROOT_PATH << seperator << "data" << seperator << "testtxt";
    FileAnalyzer fileAnalyzer{ss.str()};
    LibraryIndexer inversedIndex{fileAnalyzer};

    std::stringstream ss1,ss2,ss3,ss4;
    ss1 << "a1" << seperator << "a3.txt";
    ss2 << "a1.txt";
    ss3 << "a2" << seperator << "a21" << seperator << "a3.txt";
    ss4 << "a3" << seperator << "a2.txt";
    std::unordered_map<std::string, std::map<std::string, int>> expected;
    for (const auto& word: {"name", "yusuf", "selami"})
        for (const auto& txtfile: {ss1.str(), ss2.str(), ss3.str(), ss4.str()})
            expected[word][txtfile] = 2;
    //Act
    auto hashmap = inversedIndex.getInversedIndex();
    //Assert
    for (const auto[word, map]: hashmap)
        for (const auto[txtfile, count]: map)
            ASSERT_EQ(hashmap[word][txtfile], expected[word][txtfile]);
}
