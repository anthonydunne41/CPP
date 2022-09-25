#pragma once
#include "Pie.h"
class ApplePie : public Pie
{
public:
	ApplePie();
	std::string description() override;
	std::string tastiness() override;
};

