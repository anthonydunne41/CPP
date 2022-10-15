#pragma once

#include <iostream>
#include <string>
#include <vector>

class Profile {
private:
	std::string name {};
	int age {};
	std::string city {};
	std::string country {};
	std::string pronouns {};
	std::vector<std::string> hobbies {};




public:
	Profile(std::string newName, int newAge, std::string newCity, std::string newCountry, std::string newPronouns);



}