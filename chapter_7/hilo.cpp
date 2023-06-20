#include <iostream>
#include <limits>
#include <random>

bool playGame(int maxGuesses, int num);
bool playAgain();

int main()
{   
    // set up random number generator
    std::random_device rd;
    std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution dis{ 1, 100 };

    constexpr int maxGuesses { 7 };

    do
    {
        int num{ dis(mt) };

        std::cout << "Let's play a game. "
                  << "I'm thinking of a number between 1 and 100. "
                  << "You have " << maxGuesses << " tries to guess what it is.\n";

        bool won{ playGame(maxGuesses, num) };
        if (won)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct answer was " << num << ".\n";
    }
    while (playAgain());

    std::cout << "Thanks for playing!\n";
    return 0;
}

void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess(int count)
{   
    while (true)
    {   
        std::cout << "Guess #" << count << ": ";
        int guess{};
        std::cin >> guess;

        // extraction failed
        if (!std::cin)
        {   
            std::cout << "Invalid input, please try again!\n";
            std::cin.clear();
            clearBuffer();
            continue;
        }

        if (guess < 1 || guess > 100)
        {
            std::cout << "Guess must be between 1 and 100 (inclusive).\n";
            clearBuffer();
            continue;
        }

        clearBuffer();
        return guess;            
    }
}

bool playGame(int maxGuesses, int num)
{
    for (int i {1}; i <= maxGuesses; ++i)
    {   
        int guess { getGuess(i) };

        if (guess < num)
            std::cout << "Your guess is too low!\n";
        else if (guess > num)
            std::cout << "Your guess is too high!\n";
        else
            return true;
    }
    return false;

}

bool playAgain()
{
    while (true)
    {   
        std::cout << "Would you like to play again (y/n)? ";
        char userInput{};
        std::cin >> userInput;

        switch (userInput)
        {
            case 'y':
            case 'Y':
                return true;
            case 'n':
            case 'N':
                return false;
            default:
                std::cout << "Invalid input, please try again!\n";
                clearBuffer();
        }
    }
}
