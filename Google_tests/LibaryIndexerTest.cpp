
//
// Created by yusufyilmaz on 3.01.2022.
//
#include "gtest/gtest.h"
#include "src/indexer/LibraryIndexer.h"
#include "src/fileAnalyzer/FileAnalyzer.h"

/*TEST(LibraryIndexerTest, getHashStrMap)
{
    //Arrange
    FileAnalyzer fileAnalyzer{"C:\\Users\\SPAK\\UlakTask\\data\\testtxt"};
    LibraryIndexer inversedIndex{fileAnalyzer};
    std::unordered_map<std::string, std::map<std::string, int>> expected;
    for (const auto& word: {"name", "yusuf", "selami"})
        for (const auto& txtfile: {"a1\\a3.txt", "a1.txt", "a2\\a21\\a3.txt", "a3\\a2.txt"})
            expected[word][txtfile] = 2;
    //Act
    auto hashmap = inversedIndex.getInversedIndex();
    //Assert
    for (const auto[word, map]: hashmap)
        for (const auto[txtfile, count]: map)
            ASSERT_EQ(hashmap[word][txtfile], expected[word][txtfile]);
}*/
