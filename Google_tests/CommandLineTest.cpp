//
// Created by SPAK on 1.01.2022.
//
#include <filesystem>
#include "gtest/gtest.h"
#include "src/commandLineUtility/CommandLine.h"
#include "src/exception/BadCommit.h"

TEST(CommandLineTestParse, not3argument1)
{
    char* argg[2] = {"cli", "-index"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(2, argg)};
    EXPECT_THROW(commandLine_uptr->parse(), BadCommit);
}

TEST(CommandLineTestParse, not3argument2)
{
    char* argg[4] = {"cli", "-index", "asd", "ali"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(4, argg)};
    EXPECT_THROW(commandLine_uptr->parse(), BadCommit);
}

TEST(CommandLineTestParse, valid3argument)
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt";
    char* argg[3] = {"cli", "-index", strdup(ss.str().c_str())};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}

TEST(CommandLineTestParse, notValidCommand)
{
    char* argg[3] = {"cli", "asd", "asd"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_THROW(commandLine_uptr->parse(), BadCommit);
}

TEST(CommandLineTestParse, ValidCommand)
{
    char* argg[3] = {"cli", "-search", "asd"};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}

TEST(CommandLineTestParse, notDirectory)
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "a1.txt";
    char* argg[3] = {"cli", "-index", strdup(ss.str().c_str())};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_THROW(commandLine_uptr->parse(), BadCommit);
}

TEST(CommandLineTestParse, validDirectory)
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt";
    char* argg[3] = {"cli", "-index", strdup(ss.str().c_str())};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}

TEST(CommandLineTestParse, validExistIndexedTxt)
{
    std::stringstream ss;
    ss << static_cast<char>(std::filesystem::path::preferred_separator)
       << static_cast<char>(std::filesystem::path::preferred_separator) << "invertedIndex.txt";
    char* argg[3] = {"cli", "-search", strdup(ss.str().c_str())};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    EXPECT_NO_THROW(commandLine_uptr->parse());
}

TEST(CommandLineTestParse, getContext)
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "data"
       << static_cast<char>(std::filesystem::path::preferred_separator) << "testtxt";
    char* argg[3] = {"cli", "-index", strdup(ss.str().c_str())};
    std::unique_ptr<CommandLine> commandLine_uptr{new CommandLine(3, argg)};
    auto expectContext = ss.str().c_str();
    commandLine_uptr->parse();
    std::string value = commandLine_uptr->getContext();
    ASSERT_STREQ(value.c_str(), expectContext);
}
