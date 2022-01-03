//
// Created by yusufyilmaz on 3.01.2022.
//
#include <filesystem>
#include "gtest/gtest.h"
#include "src/fileHelper/FileHelper.h"


class FileHelperMultipleParametersTest1 :public ::testing::TestWithParam<std::string> {
protected:
    FileHelper myFileHelper;
};
TEST_P(FileHelperMultipleParametersTest1,openReadnothrow){
    std::string fileName = GetParam();
    EXPECT_NO_THROW(myFileHelper.openReadFile(fileName));
}
INSTANTIATE_TEST_CASE_P(
        openReadnothrow,
        FileHelperMultipleParametersTest1,
        ::testing::Values("/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1/a3.txt",
        "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a2/a21/a3.txt",
        "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a3/a2.txt"));

class FileHelperMultipleParametersTest2 :public ::testing::TestWithParam<std::string> {
protected:
    FileHelper myFileHelper;
};
TEST_P(FileHelperMultipleParametersTest2,openReadthrow){
    std::string fileName = GetParam();
    EXPECT_THROW(myFileHelper.openReadFile(fileName),std::runtime_error);
}
INSTANTIATE_TEST_CASE_P(
        openReadthrow,
        FileHelperMultipleParametersTest2,
        ::testing::Values("a3.txt", "a4.txt", "a5.txt", "/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a10.txt"));