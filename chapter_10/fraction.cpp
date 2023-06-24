#include <iostream>

/*
Create a struct to hold a fraction.
The struct should have an integer numerator and an integer denominator member.

Write a function to read in a Fraction from the user,
and use it to read-in two fraction objects.
Write another function to multiply two Fractions together
and return the result as a Fraction (you don’t need to reduce the fraction).
Write another function that prints a fraction.
*/

struct Fraction
{
    int numerator{ 0 };
    int denominator{ 1 };
};

Fraction getFraction()
{   
    Fraction temp;
    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;
    return temp;
}

Fraction multiply(const Fraction& f1, const Fraction& f2)
{
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void printFraction(const Fraction& f)
{
    std::cout << f.numerator << '/' << f.denominator;
}

int main()
{   
    Fraction f1 { getFraction() };
    Fraction f2 { getFraction() };
    Fraction f3 { multiply(f1, f2) };

    std::cout << "Your fractions multiplied together: ";
    printFraction(f3);

    return 0;
}
