#include "ModlFile.h"

#include <fstream>
#include <iostream>
#include <boost/regex.hpp>

#include "ModlMacro.h"
#include "Regexes.h"
#include "StringUtils.h"

void logLines(std::vector<std::string> lines)
{
    for(auto i : lines)
    {
        std::cout << i << std::endl;
    }
}

ModlFile::ModlFile(std::string path)
{
    std::ifstream file(path);
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line))
    {
        lines.push_back(trim_copy(line));
    }
    file.close();

    // remove any comments
    std::erase_if(lines, [](const std::string& s) { return s.starts_with('-'); });

    // macros
    this->m_macros = std::vector<ModlMacro>();
    for(const std::string& i : lines)
    {
        if(boost::regex r{ modl::regex::macro }; !regex_match(i, r)) continue;
        ModlMacro macro;
        macro.loadFromDecl(i);
#ifdef MODL_VERB
        macro.dumpToCout();
#endif
        m_macros.push_back(macro);
    }

    // objects
    this->m_objects = std::vector<ModlObject>();
    int lineI = 0;
    for(const std::string& i : lines)
    {
        if(boost::regex r{ modl::regex::object }; !regex_match(i, r)) continue;
        ModlObject obj;
        obj.loadPathFromDecl(i);

        for(int loopI = lineI + 1; loopI < static_cast<int>(lines.size()); loopI++)
        {
            std::string loopLine = lines.at(loopI);
            if(boost::regex r{ modl::regex::object }; regex_match(loopLine, r)) break; // break if we hit another object declaration
            if(boost::regex r{ modl::regex::value }; !regex_match(loopLine, r)) continue; // skip if it's not a param decl
            // not done yet lmao
        }
        
        m_objects.push_back(obj);
        lineI++;
    }
}
