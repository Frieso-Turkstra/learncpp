#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: " << '\n';
    std::string name {};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: " << '\n';
    int age{};
    std::cin >> age;

    int sum {static_cast<int>(name.length()) + age};
    std::cout << "You age + length of name is: " << sum;
    
    return 0;
}
