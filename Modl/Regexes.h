#pragma once
#include <string>

namespace modl
{
    namespace regex
    {
        static std::string macro = "^\\[.* ?: ?.*\\]";
        static std::string object = "^<.*>";
        static std::string macroUsage = "=.*\\(.*\\)";
        static std::string value = "^.* ?= ?.*";
    }
}