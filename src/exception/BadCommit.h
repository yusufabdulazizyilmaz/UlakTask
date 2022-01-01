//
// Created by SPAK on 1.01.2022.
//

#ifndef ULAK_BADCOMMIT_H
#define ULAK_BADCOMMIT_H
#include <string>
class BadCommit {
public:
    explicit BadCommit(std::string info);
    void addInfo();
private:
    std::string m_info;
};
#endif //ULAK_BADCOMMIT_H
