#include "suits.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Suit& suit)
{
    switch(suit)
    {
        case Suit::clubs:
            os << "C";
            break;
        case Suit::diamonds:
            os << "D";
            break;
        case Suit::hearts:
            os << "H";
            break;
        case Suit::spades:
            os << "S";
            break;
        case Suit::undefined:
        default:
            os << "?";
            break;
    }

    return os;
}

Suit& operator++(Suit& suit)
{
    // type casting to int to compare
    if (static_cast<int>(suit) < static_cast<int>(Suit::undefined))
    {
        suit = static_cast<Suit>(static_cast<int>(suit) + 1);
    }

    return suit;
}
