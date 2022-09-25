// Week3Prac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pie.h"
#include "CreamPie.h"
#include "MeatPie.h"
#include "ApplePie.h"

int main()
{

    /*std::cout << "Hello World!\n";
    //Pie a;

    CreamPie a{};
    MeatPie b{};
    ApplePie c{};

    std::cout << a.description() << std::endl;
    std::cout << b.description() << std::endl;
    std::cout << c.description() << std::endl;
    */

    Pie* piePtr = nullptr;
    int choice{};
    std::cout << "what pie do you want? 1 = Cream, 2 = Meat, 3 = Apple\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        piePtr = new CreamPie();
        break;
    case 2:
        piePtr = new MeatPie();
        break;
    case 3:
        piePtr = new ApplePie();
        break;
    }

    std::cout << piePtr->description();

    

}
