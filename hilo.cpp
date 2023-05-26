#include <iostream>

int generateNumber();
int getUserInput();

int main()
{   
    // generate a number to be guessed between 1 and 10
    int num { generateNumber() };
    int guess {0};

    // while the number is not guessed
    while (num != guess)
    {
        // get user input
        guess = getUserInput();

        if (guess < num)
        {
            std::cout << "Higher!" << "\n";
        }
        else if (guess > num)
        {
            std::cout << "Lower!" << "\n";
        }
        else
        {
            std::cout << "Correct!" << "\n";
        }
    }

    return 0;
}

int generateNumber()
{
    return 5;
}

int getUserInput()
{   
    std::cout << "Enter your guess: ";
    int x{};
    std::cin >> x;
    return x;
}
