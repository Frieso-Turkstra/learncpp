/*
In this quiz, implement the game as follows:

Numbers divisible by only 3 should print “fizz”.
Numbers divisible by only 5 should print “buzz”.
Numbers divisible by only 7 should print “pop”.
Numbers divisible by only 11 should print “bang”.
Numbers divisible by only 13 should print “jazz”.
Numbers divisible by only 17 should print “pow”.
Numbers divisible by only 19 should print “boom”.

Numbers divisible by more than one of the above should print each of the words associated with its divisors.
Numbers not divisible by any of the above should just print the number.
Use an array to hold the divisors, and another array to hold the words (as type std::string_view).
If the arrays do not have the same length, the program should fail to compile.
Produce output for 150 numbers.
*/

#include <iostream>
#include <string_view>
#include <iterator>

void fizzbuzz(int count)
{
    constexpr int divisors[7]{ 3, 5, 7, 11, 13, 17, 19 };
    constexpr std::string_view words[7]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    static_assert(std::size(divisors) == std::size(words), "arrays must be of similar length");

    for (int iteration{ 1 }; iteration <= count; ++iteration)
    {   
        bool foundDivisor { false };
        
        for (int divisor{ 0 }; divisor < std::size(divisors); ++divisor)
        {
            if (iteration % divisors[divisor] == 0)
            {
                std::cout << words[divisor];
                foundDivisor = true;
            }
        }

        if (!foundDivisor)
            std::cout << iteration;

        std::cout << '\n';
    }
}

int main()
{   
    fizzbuzz(150);
    return 0;
}
