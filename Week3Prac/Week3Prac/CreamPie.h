#pragma once
#include "Pie.h"
class CreamPie : public Pie
{
public:
	CreamPie();
	std::string description() override;

	std::string tastiness() override;

};

