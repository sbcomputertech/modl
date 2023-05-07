#pragma once
#include <string>
#include <vector>

#include "ModlParam.h"

struct ModlObject
{
    std::vector<std::string> path;
    std::vector<ModlParam> params;
    void loadPathFromDecl(std::string decl);
};
