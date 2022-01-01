//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_FILEANALYZER_H
#define ULAK_FILEANALYZER_H
#include <string>
#include <filesystem>
#include <vector>
class FileAnalyzer {
public:
    explicit FileAnalyzer(std::string library);
    [[nodiscard]] const std::string&
    getLibrary() const;
    [[nodiscard]] const std::vector<std::filesystem::path>&
    getTxtFileVec() const;
private:
    [[nodiscard]] std::vector<std::filesystem::path>
    fileAnalizer();
    std::string m_library;
    std::vector<std::filesystem::path> m_txtFileVec;
};
#endif //ULAK_FILEANALYZER_H
