#include "random.h"
#include <iostream>
#include <array>
#include <algorithm>

/*
A deck of cards has 52 unique cards (13 card ranks of 4 suits).
Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace)
and suits (clubs, diamonds, hearts, spades).
Those enumerators will not be used to index arrays.
*/

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king, 
    rank_ace,

    max_ranks
};

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

/*
Each card will be represented by a struct named Card that contains a rank and a suit.
*/

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int score{};
};

constexpr int g_maxScore{ 21 };
constexpr int g_minDealerScore{ 17 };

/*
Create a printCard() function that takes a const Card reference as a parameter
and prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).
*/

void printCard(const Card& card)
{
    switch(card.rank)
    {
        case CardRank::rank_2:      std::cout << '2';   break;
        case CardRank::rank_3:      std::cout << '3';   break;
        case CardRank::rank_4:      std::cout << '4';   break;
        case CardRank::rank_5:      std::cout << '5';   break;
        case CardRank::rank_6:      std::cout << '6';   break;
        case CardRank::rank_7:      std::cout << '7';   break;
        case CardRank::rank_8:      std::cout << '8';   break;
        case CardRank::rank_9:      std::cout << '9';   break;
        case CardRank::rank_10:     std::cout << "10";  break;
        case CardRank::rank_jack:   std::cout << 'J';   break;
        case CardRank::rank_queen:  std::cout << 'Q';   break;
        case CardRank::rank_king:   std::cout << 'K';   break;
        case CardRank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;

    }

    switch(card.suit)
    {
        case CardSuit::club:        std::cout << 'C';   break;
        case CardSuit::diamond:     std::cout << 'D';   break;
        case CardSuit::heart:       std::cout << 'H';   break;
        case CardSuit::spade:       std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
    }
}

/*
A deck of cards has 52 cards.
Create an array (using std::array) to represent the deck of cards,
and initialize it with one of each card.
Do this in a function named createDeck and call createDeck from main.
createDeck should return the deck to main.
*/

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

Deck createDeck()
{   
    Deck deck{};
    
    Index i{ 0 };
    for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
        {
            deck[i].suit = static_cast<CardSuit>(suit);
            deck[i].rank = static_cast<CardRank>(rank);
            ++i;
        }
    }
    
    return deck;
}

/*
Write a function named printDeck() that takes the deck as a const reference parameter
and prints the cards in the deck. Use a range-based for-loop.
*/

void printDeck(const Deck& deck)
{
    for (const auto& card: deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

/*
Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle.
Update your main function to shuffle the deck and print out the shuffled deck.
*/

void shuffleDeck(Deck& deck)
{   
    // mt is static so only seeded once.
    static std::mt19937 mt{ Random::generate() };
    std::shuffle(deck.begin(), deck.end(), mt);
}

/*
Write a function named getCardValue() that returns the value of a Card
(e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10.
Assume an Ace is worth 11).
*/
int getCardValue(const Card& card)
{   
    switch(card.rank)
    {
        case CardRank::rank_2:      return 2;
        case CardRank::rank_3:      return 3;
        case CardRank::rank_4:      return 4;
        case CardRank::rank_5:      return 5;
        case CardRank::rank_6:      return 6;
        case CardRank::rank_7:      return 7;
        case CardRank::rank_8:      return 8;
        case CardRank::rank_9:      return 9;
        case CardRank::rank_10:     return 10;
        case CardRank::rank_jack:   return 10;
        case CardRank::rank_queen:  return 10;
        case CardRank::rank_king:   return 10;
        case CardRank::rank_ace:    return 11;
        default:
            std::cout << '?';
            return 0;

    }
}



bool playBlackJack(Deck& deck)
{   
    Index deckIndex{ 0 };

    // The dealer gets one card to start
    Player dealer{ getCardValue(deck.at(deckIndex++)) };
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // The player gets two cards to start.
    Player player{ getCardValue(deck.at(deckIndex++)) + getCardValue(deck.at(deckIndex++)) };

    // Player's turn
    while (true)
    {   
        // print score
        std::cout << "Your score: " << player.score << '\n';

        // check if score is more than the goal
        if (player.score > g_maxScore)
        {
            return false;
        }

        // ask for user action
        std::cout << "Choose action (hit/stand): ";
        std::string action{};
        std::cin >> action;

        // check if stand or hit
        if (action == "hit")
            player.score += getCardValue(deck.at(deckIndex++));
        else if (action == "stand")
            break;
        else
            std::cout << "Invalid input, please try again.\n";
    }
    
    // Dealer's turn
    while (dealer.score < g_minDealerScore)
    {
        dealer.score += getCardValue(deck[deckIndex++]);
    }

    return (dealer.score > g_maxScore || dealer.score < player.score);
}

int main()
{   
    Deck deck{ createDeck() };
    shuffleDeck(deck);

    if (playBlackJack(deck))
        std::cout << "You won!\n";
    else
        std::cout << "You lost!\n";

    return 0;
}
