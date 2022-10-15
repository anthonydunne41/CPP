#include <iostream>
#include <vector>
#include <string>
 
int main() {
 
  // Whale, whale, whale.
  // What have we got here?
  std::string str1 = "turpentine and turtles";
  std::vector<char> vowles = {'a', 'e', 'i', 'o', 'u'};
  std::vector<char> result;
 
  for (int i = 0; i < str1.length(); i++)
  {
    for (int j = 0; j < vowles.size(); j++)
    {
      if (str1[i] == vowles[j])
      {
        result.push_back(str1[i]);
      }
    }
  }
  for (char a : result)
  {
    std::cout << a;
  }

  
}
