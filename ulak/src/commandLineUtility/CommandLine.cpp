//
// Created by SPAK on 1.01.2022.
//

#include <filesystem>
#include "CommandLine.h"
#include "../exception/BadCommit.h"

CommandLine::CommandLine(int argc, char** argv)
        :m_argc{argc}
{
    for(std::size_t i = 1; i < m_argc;++i)
        m_argVec.push_back(std::move(argv[i]));
}

COMMAND_TYPE CommandLine::getCommand() const
{
    return m_command;
}

const std::string& CommandLine::getContext() const
{
    return m_context;
}

void CommandLine::parse()
{
    std::string command;
    if (m_argc!=3)
        throw BadCommit{"Invalid command line!"};

    command = std::move(m_argVec[0]);
    m_context = std::move(m_argVec[1]);

    if (command!="-index" and command!="-search")
        throw BadCommit{"Invalid command."};
    if (command=="-index" and !std::filesystem::is_directory(m_context))
        throw BadCommit{"No such a library folder."};
    if (command=="-search" and !std::filesystem::exists(m_IndexedFile))
        throw BadCommit{"First should index any library folder."};

    m_command = command=="-index" ? COMMAND_TYPE::INDEX : COMMAND_TYPE::SEARCH;
}
