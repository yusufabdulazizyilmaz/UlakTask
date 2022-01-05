//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_COMMANDLINE_H
#define ULAK_COMMANDLINE_H

#include <string>
#include <vector>

class CommandLine {
public:
    enum class COMMAND_TYPE {
        INDEX, SEARCH
    };
    CommandLine(int argc, char** argv);

    [[nodiscard]] COMMAND_TYPE getCommand() const;

    [[nodiscard]] const std::string& getContext() const;

    void parse();

private:
    int m_argc;
    std::vector<std::string> m_argVec;
    COMMAND_TYPE m_command;
    std::string m_context;
};

#endif //ULAK_COMMANDLINE_H
