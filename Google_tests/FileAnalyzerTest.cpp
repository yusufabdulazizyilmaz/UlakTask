//
// Created by SPAK on 1.01.2022.
//
#include "gtest/gtest.h"
#include "src/fileAnalyzer/FileAnalyzer.h"

TEST(FileAnalyzer, getlibrary)
{
    // Arrange
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt";
    FileAnalyzer fileAnalyzer(ss.str());
    // Act
    std::string value = fileAnalyzer.getLibrary();
    // Assert
    ASSERT_STREQ(value.c_str(), strdup(ss.str().c_str()));
}

/*TEST(FileAnalyzerTest, getTxtVector)
{
    // Act
    /*std::vector<std::string> expectedVec{"/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1/a2.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1/a3.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1/za1.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1/za4.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a1.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a2.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a21/a1.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a21/a2.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a21/a3.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a21/a4.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a3.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a4.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3/a1.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3/a2.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3/a3.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3/a4.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3.txt",
    "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a4.txt"};

    std::vector<std::string> expectedVec{"C:\\Users\\SPAK\\UlakTask\\data\\testtxt\\a1/a3.txt",
                                         "C:\\Users\\SPAK\\UlakTask\\data\\testtxt\\a1.txt",
                                         "C:\\Users\\SPAK\\UlakTask\\data\\testtxt\\a2\\a21\\a3.txt",
                                         "C:\\Users\\SPAK\\UlakTask\\data\\testtxt\\a3\\a2.txt"};

    auto txtFileVec = fileAnalyzer_uptr->getTxtFileVec();
    sort(begin(txtFileVec), end(txtFileVec));
    std::vector<std::string> results;
    transform(begin(txtFileVec), end(txtFileVec), std::back_inserter(results),
            [](const auto& path) { return path.string(); });
    // Assert
    EXPECT_TRUE(std::equal(begin(results), end(results), begin(expectedVec), end(expectedVec)));
}*/

