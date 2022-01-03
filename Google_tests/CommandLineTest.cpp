//
// Created by SPAK on 1.01.2022.
//
#include "gtest/gtest.h"
#include "src/commandLineUtility/CommandLine.h"
#include "src/exception/BadCommit.h"

TEST(CommandLineTestParse, not3argument1){
    char* argg [2] = {"cli","-index"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(2,argg)};
    EXPECT_THROW(commandLine_uptr->parse(),BadCommit);
}
TEST(CommandLineTestParse, not3argument2){
    char* argg [4] = {"cli","-index","asd","ali"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(4,argg)};
    EXPECT_THROW(commandLine_uptr->parse(),BadCommit);
}
TEST(CommandLineTestParse, valid3argument){
    char* argg [3] = {"cli","-index","/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}
TEST(CommandLineTestParse, notValidCommand){
    char* argg [3] = {"cli","asd","asd"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_THROW(commandLine_uptr->parse(),BadCommit);
}
TEST(CommandLineTestParse, ValidCommand){
    char* argg [3] = {"cli","-search","asd"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}
TEST(CommandLineTestParse, notDirectory){
    char* argg [3] = {"cli","-index","/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt/a1.txt"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_THROW(commandLine_uptr->parse(),BadCommit);
}
TEST(CommandLineTestParse, validDirectory){
    char* argg [3] = {"cli","-index","/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}
TEST(CommandLineTestParse, validExistIndexedTxt){
    char* argg [3] = {"cli","-search","/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/invertedIndex.txt"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}

/*TEST(CommandLineTestParse, getContext){
    char* argg [3] = {"cli","-index","/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3,argg)};
    auto expectContext ="/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt";
    std::string value = commandLine_uptr->getContext();
    ASSERT_STREQ(value.c_str(),expectContext);
}*/

/*int gArgc;
char** gArgv;

struct CommandLineTest : public testing::Test {
    std::unique_ptr<CommandLine> commandLine_uptr;
    CommandLineTest()
            :commandLine_uptr(new CommandLine(gArgc,gArgv)) { }
};*/

/*TEST_F(CommandLineTest, getCommand){
    auto expectCommand =COMMAND_TYPE::INDEX;
    auto val= commandLine_uptr->getCommand();
    EXPECT_EQ(val,expectCommand);
}*/
/*TEST_F(CommandLineTest, getContext){
    auto expectContext ="/home/yusufyilmaz/Desktop/yusufgithub/UlakTask-firstbranch/data/testtxt";
    ASSERT_STREQ(commandLine_uptr->getContext().c_str(),expectContext);
}*/
/*int main(int argc, char **argv)
{
    gArgc = argc;
    gArgv = argv;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
