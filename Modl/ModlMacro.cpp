#include "ModlMacro.h"

#include <iostream>
#include <vector>

#include "StringUtils.h"

void ModlMacro::loadFromDecl(const std::string& decl)
{
    std::string noBrackets = replace_all(replace_all(decl, "[", ""), "]", "");
    trim(noBrackets);
    std::vector<std::string> kv = split(noBrackets, ":");
    this->name = kv.at(0);
    trim(this->name);
    this->value = kv.at(1);
    trim(this->value);
}

void ModlMacro::dumpToCout() const
{
    std::cout << "ModlMacro{ " << name << " = " << value << " }" << std::endl;
}
