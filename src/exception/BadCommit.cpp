//
// Created by SPAK on 1.01.2022.
//

#include "BadCommit.h"
#include <iostream>
#include "BadCommit.h"

BadCommit::BadCommit(std::string info)
        :m_info{std::move(info)} { }

void BadCommit::addInfo()
{
    std::cerr << m_info << "\n";
}