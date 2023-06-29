#include <algorithm> // for std::sort
#include <iostream>
#include <string>

int main()
{   
    // Ask the user how many names they wish to enter.
    std::cout << "How many names would you like to enter? ";
    int count{ 0 }; 
    std::cin >> count;

    // Dynamically allocate a std::string array.
    auto* names{ new std::string[count]{} };

    // Ask the user to enter each name.
    for (int i{ 0 }; i < count; ++i)
    {   
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    // Call std::sort to sort the names.
    std::sort(names, names + count);

    // Prints the sorted list of names.
    std::cout << "Here is your sorted list:\n";

    for (int i{ 0 }; i < count; ++i)
    {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }

    delete[] names;

    return 0;
}
