#include <iostream>

/*
You are running a website, and you are trying to keep track of how much money
you make per day from advertising. Declare an advertising struct that keeps
track of how many ads you’ve shown to readers, what percentage of ads
were clicked on by users, and how much you earned on average from each ad
that was clicked. Read in values for each of these fields from the user.
Pass the advertising struct to a function that prints each of the values,
and then calculates how much you made for that day (multiply all 3 fields together).
*/

struct Advertising
{
    int numberOfAds{};
    double clickThroughRate{};
    double earningsPerClick{};
};

Advertising getAdvertising()
{   
    Advertising temp;
    std::cout << "Number of ads shown: ";
    std::cin >> temp.numberOfAds;

    std::cout << "Click-through rate: ";
    std::cin >> temp.clickThroughRate;

    std::cout << "Average earnings per click: ";
    std::cin >> temp.earningsPerClick;

    return temp;
}

void printAdvertising(const Advertising& ad)
{   
    std::cout << "Number of ads shown: " << ad.numberOfAds << "\n";
    std::cout << "Click-through rate: " << ad.clickThroughRate << "\n";
    std::cout << "Average earning per click: $" << ad.earningsPerClick << "\n";

    std::cout << "Advertisment earnings today: $"
              << ad.numberOfAds * ad.clickThroughRate / 100 * ad.earningsPerClick
              << "\n";
}

int main()
{   
    printAdvertising( getAdvertising() );
    return 0;
}
