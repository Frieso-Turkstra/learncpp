#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    int x{ getInteger() };

    if ( isEven(x) )
        std::cout << x << " is even\n";
    else
        std::cout << x << " is odd\n";

    return 0;
}
