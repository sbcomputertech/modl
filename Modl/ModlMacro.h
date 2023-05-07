#pragma once
#include <string>

struct ModlMacro
{
    std::string name;
    std::string value;

    void loadFromDecl(const std::string& decl);
    void dumpToCout() const;
};
