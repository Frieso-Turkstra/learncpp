#include <iostream>

namespace animals
    {
        enum
        {
            chicken,
            dog,
            cat,
            elephant,
            duck,
            snake,
            maxAnimals,
        };
    }

int main()
{   
    // Declare an array to hold the high temperature (to the nearest tenth of a degree)
    // for each day of a year (assume 365 days in a year).
    // Initialize the array with a value of 0.0 for each day.
    double temperatures[365]{};

    // Set up an enum with the names of the following animals:
    // chicken, dog, cat, elephant, duck, and snake. Put the enum in a namespace.
    // Define an array with an element for each of these animals,
    // and use an initializer list to initialize each element
    // to hold the number of legs that animal has.
    // Write a main function that prints the number of legs an elephant has, using the enumerator.
    int legs[animals::maxAnimals]{ 2, 4, 4, 4, 2, 0 };

    std::cout << legs[animals::elephant] << '\n';

    return 0;
}
