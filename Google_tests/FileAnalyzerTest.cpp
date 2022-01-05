//
// Created by SPAK on 1.01.2022.
//
#include "gtest/gtest.h"
#include "src/fileAnalyzer/FileAnalyzer.h"

std::string filePath()
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt";
    return ss.str();
}

struct FileAnalyzerTest : public testing::Test {
    std::unique_ptr<FileAnalyzer> fileAnalyzer_uptr;
    FileAnalyzerTest():fileAnalyzer_uptr {new FileAnalyzer{filePath()}} {}
};

TEST_F(FileAnalyzerTest, getlibrary)
{
    // Act
    std::string value = fileAnalyzer_uptr->getLibrary();
    // Assert
    ASSERT_STREQ(value.c_str(), filePath().c_str());
}

TEST_F(FileAnalyzerTest, getTxtVector)
{
    // Arrange
    std::stringstream ss1,ss2,ss3,ss4;
    char seperator = static_cast<char>(std::filesystem::path::preferred_separator);
    ss1 << filePath() << seperator << "a1" << seperator << "a3.txt";
    ss2 << filePath() << seperator << "a1.txt";
    ss3 << filePath() << seperator << "a2" << seperator << "a21" << seperator << "a3.txt";
    ss4 << filePath() << seperator << "a3" << seperator << "a2.txt";
    std::vector<std::string> expectedVec{ ss1.str(), ss2.str(), ss3.str(), ss4.str()};
    // Act
    auto txtFileVec = fileAnalyzer_uptr->getTxtFileVec();
    sort(begin(txtFileVec), end(txtFileVec));
    std::vector<std::string> results;
    transform(begin(txtFileVec), end(txtFileVec), back_inserter(results),
            [](const auto& path) { return path.string(); });
    // Assert
    EXPECT_TRUE(std::equal(begin(results), end(results), begin(expectedVec), end(expectedVec)));
}

