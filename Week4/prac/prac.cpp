#include <iostream>
#include <string>
#include <set>
#include <cmath>

/*
Write an application that prompts the user for a set of numbers (integers) and stores them in a 
std::set. You may ask the user for the number of values that they will enter or use some other 
means to end the set of numbers. 
• Refer to the lecture material and cppreference 
(https://en.cppreference.com/w/cpp/container/set/set) if you are having difficulty with the 
concepts. 
• Your application should not crash or enter an infinite loop if the user enters an invalid value. 
Be sure to follow good practice and validate the inputs: display an error and re-prompt if an 
invalid value is provided. 
*/

int main()
{
	std::cout << "How many numbers? \n";
	int i{};
	std::cin >> i;
	std::set<int> numbers;
	for (int a = 0; a < i; a++)
	{
		std::cout << "enter number:  \n";
		int b;
		std::cin >> b;
		numbers.insert(b);
	}





	return 0;
}