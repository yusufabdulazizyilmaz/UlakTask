//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_COMMANDLINE_H
#define ULAK_COMMANDLINE_H

#include <string>
#include <vector>

enum class COMMAND_TYPE {
    INDEX, SEARCH
};

class CommandLine {
public:

    CommandLine(int argc, char** argv);

    COMMAND_TYPE getCommand() const;

    const std::string& getContext() const;

    void parse();

private:
    int m_argc;
    std::vector<std::string> m_argVec;
    COMMAND_TYPE m_command;
    std::string m_context;
};

#endif //ULAK_COMMANDLINE_H
