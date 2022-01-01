//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_FILEHELPER_H
#define ULAK_FILEHELPER_H

#include <fstream>

class FileHelper {
public:
    [[nodiscard]]static std::ifstream openReadFile(const std::string& fileName);

    [[nodiscard]]static std::ofstream openWriteFile(const std::string& fileName);
};

#endif //ULAK_FILEHELPER_H
