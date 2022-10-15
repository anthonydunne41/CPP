#include "profile.hpp"

Profile::Profile(std::string newName, int newAge, std::string newCity, std::string newCountry, std::string newPronouns) :
	name{newName},
	age{newAge},
	city{newCity},
	country{newCountry},
	pronouns{newPronouns}	
{
}