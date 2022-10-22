#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <map>

int main()
{
	int value_length;
	int number;
	std::set<int> values;
	std::map<int, std::string> value_map;

	std::cout << "How many numbers do you want to give me? \n";

	std::cin >> value_length;
	for (int i = 0; i < value_length; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> number;
		while (values.count(number))
		{
			std::cout << "Number already in set, try again: ";
			std::cin >> number;
		}
		values.insert(number);
	}

	std::cout << "Your numbers : ";
	for (auto a : values)
	{
		std::cout << a << " ";
	}

	std::cout << "\nGive me a number to erase: ";
	std::cin >> number;

	if (values.count(number))
	{
		values.erase(number);
	}

	std::cout << "Your numbers : ";
	for (auto a : values)
	{
		std::cout << a << " ";
	}
	std::cout << '\n';

	std::string ass_string;
	for (auto a : values)
	{
		std::cout << "Enter string to be associated with " << a << ": \n";
		std::cin >> ass_string;
		value_map[a] = ass_string;
	}

	for (std::map<int, std::string>::iterator it = value_map.begin(); it != value_map.end(); ++it) {
		std::cout << it->first << " = " << it->second << '\n';
	}




	return 0;
}