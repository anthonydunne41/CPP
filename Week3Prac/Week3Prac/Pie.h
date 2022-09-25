#pragma once

#include <string>

class Pie
{
public:
	Pie();
	virtual std::string description() = 0;
	virtual std::string tastiness();
};

