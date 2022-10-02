#pragma once
#include <string>

class Book 
{
public:
    Book(std::string name, std::string author);

    std::string name() const { return _name; }
    std::string author() const { return _author; }

    void setName(std::string n) { _name = n; }
    void setAuthor(std::string a) { _author = a; }


protected:
    std::string _name;
    std::string _author;
};
