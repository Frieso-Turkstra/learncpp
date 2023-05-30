#include <iostream>

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

void calculateHeight(double towerHeight, int seconds)
{   
    constexpr double gravity {9.8};
    const double distanceFallen { (gravity * seconds * seconds) / 2 };

    std::cout << "At " << seconds << " seconds, ";

    if (distanceFallen > towerHeight)
        std::cout << "the ball is on the ground." << '\n';
    else
        std::cout << "the ball is at height: " << towerHeight - distanceFallen << " meters" << '\n';
}

int main()
{   
    // ask user for the height of the tower in meters
    double towerHeight { getTowerHeight() };

    // calculate height for 5 seconds
    calculateHeight(towerHeight, 0);
    calculateHeight(towerHeight, 1);
    calculateHeight(towerHeight, 2);
    calculateHeight(towerHeight, 3);
    calculateHeight(towerHeight, 4);
    calculateHeight(towerHeight, 5);
    calculateHeight(towerHeight, 6);

    return 0;
}
