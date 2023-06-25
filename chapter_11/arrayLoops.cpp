#include <iostream>
#include <iterator>
#include <limits>

int getNumber()
{   
    int num{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> num;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (num < 1 || num > 9);
    
    return num;
}

void printArray(const int array[], const int length)
{   
    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << '\n';
}

int getIndex(const int array[], const int length, int num)
{   
    for (int i{ 0 }; i < length; ++i)
    {
        if (array[i] == num) return i;
    }
    return -1;
}

int main()
{
    // Print the following array to the screen using a loop:
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int length {std::size(array)};

    /*
    Given the array in question 1:
    Ask the user for a number between 1 and 9.
    If the user does not enter a number between 1 and 9,
    repeatedly ask for an integer value until they do.
    If the user enters a number followed by extraneous input,
    ignore the extraneous input.
    Once they have entered a number between 1 and 9,
    print the array.
    Then search the array for the value that the user entered
    and print the index of that element.
    */

    int num { getNumber() };
    printArray(array, length);
    std::cout << "The number " << num << " has index " << getIndex(array, length, num) << '\n';

    return 0;
}
