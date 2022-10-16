#include "profile.hpp"


Profile::Profile(std::string newName, int newAge, std::string newCity, std::string newCountry) :
	name{newName},
	age{newAge},
	city{newCity},
	country{newCountry},
	pronouns{"they/them"}	
{
}

Profile::Profile(std::string newName, int newAge, std::string newCity, std::string newCountry, std::string newPronouns) :
	name{newName},
	age{newAge},
	city{newCity},
	country{newCountry},
	pronouns{newPronouns}	
{
}

std::string Profile::view_profile(){
	std::string bio = "Name: " + name + "\nAge: " + std::to_string(age) + "\nPronouns: " + pronouns + "\nHobbies: ";
	for (auto a : hobbies)
	{
		bio += a + "\n";
	}
	return bio;
}

void Profile::add_hobby(std::string new_hobby){
	hobbies.push_back(new_hobby);
}