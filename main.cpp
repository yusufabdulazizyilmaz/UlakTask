#include <iostream>
#include "src/fileAnalyzer/FileAnalyzer.h"

int main() {
    FileAnalyzer fileAnalyzer("C:\\Users\\SPAK\\UlakTask\\data\\testtxt");
    auto fileVec=fileAnalyzer.getTxtFileVec();
    for (const auto & txtFile:fileVec)
        std::cout << txtFile.string()<<"\n";
    return 0;
}
