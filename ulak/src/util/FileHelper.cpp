//
// Created by SPAK on 1.01.2022.
//

#include <filesystem>
#include <iostream>
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

void
FileHelper::serialize(const std::unordered_map<std::string, std::map<std::string, int>>& indexedMap, std::string outTxt)
{
    auto outputFileWriter = openWriteFile(outTxt);
    char delimeter = '|';
    for (const auto&[word, innermap]: indexedMap) {
        outputFileWriter << word << " ";
        for (const auto&[txtfile, count]: innermap)
            outputFileWriter << txtfile << "(" << count << ")" << delimeter;
        outputFileWriter << "\n";
    }
}

std::unordered_map<std::string, std::string> FileHelper::deSerialize(std::string outTxt)
{
    auto ifs = openReadFile(outTxt);
    std::string word, innermap;
    std::unordered_map<std::string, std::string> retUnorderedMap;
    while (ifs >> word >> innermap)
        retUnorderedMap[word] = std::move(innermap);
    return retUnorderedMap;
}

std::string FileHelper::getInvertedFilePath()
{
    std::stringstream ss;
    ss << ROOT_PATH << static_cast<char>(std::filesystem::path::preferred_separator) << "invertedIndex.txt";
    return ss.str();
}