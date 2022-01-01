//
// Created by SPAK on 1.01.2022.
//
#include "gtest/gtest.h"
#include "src/fileAnalyzer/FileAnalyzer.h"

struct FileAnalyzerTest : public testing::Test {
    std::unique_ptr<FileAnalyzer> fileAnalyzer_uptr;

    FileAnalyzerTest()
            :fileAnalyzer_uptr(new FileAnalyzer("C:\\Users\\SPAK\\UlakTask\\data\\testtxt")) { }
};

TEST_F(FileAnalyzerTest, getlibrary)
{
    // Act
    std::string value = fileAnalyzer_uptr->getLibrary();
    // Assert
    EXPECT_STREQ(value.c_str(), "C:\\Users\\SPAK\\UlakTask\\data\\testtxt");
}

TEST(basic_check, increment_by_10)
{
    int value = 100;
    int increment = 10;

    value += increment;
    ASSERT_EQ(value, 110);
}

