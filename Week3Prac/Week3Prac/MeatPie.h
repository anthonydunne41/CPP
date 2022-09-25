#pragma once
#include "Pie.h"
class MeatPie : public Pie
{
public:
	MeatPie();
	std::string description() override;
	std::string tastiness() override;

};

