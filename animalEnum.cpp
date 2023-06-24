#include <iostream>
#include <string_view>

enum class Animal 
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{   
    switch (animal)
    {
        case Animal::pig: return "pig";
        case Animal::chicken: return "chicken";
        case Animal::goat: return "goat";
        case Animal::cat: return "cat";
        case Animal::dog: return "dog";
        case Animal::duck: return "duck";
        default:
            std::cout << "Error message.\n";
            return "???";
    }
}

void printNumberOfLegs(Animal animal)
{   
    std::string_view name { getAnimalName(animal) };

    switch (animal)
    {
        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << "A " << name << " has 4 legs.\n";
            break;
        case Animal::chicken:
        case Animal::duck:
            std::cout << "A " << name << " has 2 legs.\n";
            break;
        default:
            std::cout << "Error message.\n";
            break;
    }
}

int main()
{   
    printNumberOfLegs( Animal::cat );
    printNumberOfLegs( Animal::chicken );
    return 0;
}
