//
// Created by SPAK on 1.01.2022.
//

#include "FileHelper.h"

std::ifstream FileHelper::openReadFile(const std::string& fileName)
{
    std::ifstream ifs{fileName};
    if (!ifs)
        throw std::runtime_error{"file: "+fileName+" cannot opened"};
    return ifs;
}

std::ofstream FileHelper::openWriteFile(const std::string& fileName)
{
    std::ofstream ofs{fileName};
    if (!ofs)
        throw std::runtime_error{"file: "+fileName+" cannot created"};
    return ofs;
}
