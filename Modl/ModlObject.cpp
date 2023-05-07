#include "ModlObject.h"

#include "StringUtils.h"

void ModlObject::loadPathFromDecl(std::string decl)
{
    std::string noBrackets = replace_all(replace_all(decl, "<", ""), ">", "");
    trim(noBrackets);
    this->path = split(noBrackets, "/");
    for(std::string& s : this->path)
    {
        trim(s);
    }
}
