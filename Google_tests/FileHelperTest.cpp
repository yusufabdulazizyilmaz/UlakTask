//
// Created by yusufyilmaz on 3.01.2022.
//
#include <filesystem>
#include "gtest/gtest.h"
#include "src/util/FileHelper.h"

class FileHelperMultipleParametersTest1 : public ::testing::TestWithParam<std::string> {
protected:
    FileHelper myFileHelper;

};

TEST_P(FileHelperMultipleParametersTest1, openReadnothrow)
{
    std::string fileName = GetParam();
    EXPECT_NO_THROW(myFileHelper.openReadFile(fileName));
}

INSTANTIATE_TEST_CASE_P
(
        openReadnothrow,
        FileHelperMultipleParametersTest1,
        ::testing::Values(FileHelper::getInvertedFilePath()));

class FileHelperMultipleParametersTest2 : public ::testing::TestWithParam<std::string> {
protected:
    FileHelper myFileHelper;
};

TEST_P(FileHelperMultipleParametersTest2, openReadthrow)
{
    std::string fileName = GetParam();
    EXPECT_THROW(myFileHelper.openReadFile(fileName), std::runtime_error);
}

INSTANTIATE_TEST_CASE_P
(
        openReadthrow,
        FileHelperMultipleParametersTest2,
        ::testing::Values("a3.txt", "a4.txt", "a5.txt", "C:\\Users\\SPAK\\UlakTask\\data\\testtxt\\a10.txt"));
