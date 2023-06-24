/*
In designing a game, we decide we want to have monsters,
because everyone likes fighting monsters.
Declare a struct that represents your monster.
The monster should have a type that can be one of the following:
an ogre, a dragon, an orc, a giant spider, or a slime.
Use an enum class for this.

Each individual monster should also have a name
(use a std::string or std::string_view),
as well as an amount of health that represents
how much damage they can take before they die.
Write a function named printMonster()
that prints out all of the struct’s members.
Instantiate an ogre and a slime,
initialize them using an initializer list,
and pass them to printMonster().
*/

#include <string>
#include <string_view>
#include <iostream>

enum class MonsterType
    {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime,
    };

struct Monster
{   
    MonsterType type{};
    std::string name{};
    int health{};
};

constexpr std::string_view getMonsterTypeString(MonsterType type)
{   
    switch (type)
    {
        case MonsterType::ogre: return "Ogre";
        case MonsterType::dragon: return "Dragon";
        case MonsterType::orc: return "Orc";
        case MonsterType::giantSpider: return "Giant Spider";
        case MonsterType::slime: return "Slime";
        default: return "Unknown";
    }

}

void printMonster(const Monster& monster)
{   
    std::cout << "This " << getMonsterTypeString(monster.type)
              << " is named " << monster.name
              << " and has " << monster.health << " health.\n";
}

int main()
{   
    Monster ogre { MonsterType::ogre, "Torg", 145 };
    Monster slime { MonsterType::slime, "Blurp", 23 };

    printMonster( ogre );
    printMonster( slime );
    return 0;
}
