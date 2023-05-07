#pragma once

#include <string>
#include <vector>

#include "ModlInternal.h"
#include "ModlMacro.h"
#include "ModlObject.h"

class ModlFile
{
public:
	MODL_API ModlFile(std::string path);
private:
	std::vector<ModlMacro> m_macros;
	std::vector<ModlObject> m_objects;
};

