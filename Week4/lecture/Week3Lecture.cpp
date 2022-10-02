#include <iostream>
#include "book.h"

void ShowBookDetails(const Book* b)
{
    std::string name = b->name();
    std::string author = b->author();

    std::cout << name << " by " << author << std::endl;

}

int main()
{
    const Book b("Dune", "Frank Herbert");
    
    ShowBookDetails(&b);
    

    return 0;
}