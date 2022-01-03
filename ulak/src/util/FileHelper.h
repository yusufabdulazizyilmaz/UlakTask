//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_FILEHELPER_H
#define ULAK_FILEHELPER_H

#include <fstream>
#include <unordered_map>
#include <map>
#include <string>

class FileHelper {
public:
    [[nodiscard]]static std::ifstream openReadFile(const std::string& fileName);

    [[nodiscard]]static std::ofstream openWriteFile(const std::string& fileName);

    static void
    serialize(const std::unordered_map<std::string, std::map<std::string, int>>& indexedMap, std::string outTxt);

    static std::unordered_map<std::string, std::string> deSerialize(std::string outTxt);
    static std::string getInvertedFilePath();
};

#endif //ULAK_FILEHELPER_H
