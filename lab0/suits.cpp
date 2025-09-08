#include "suits.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, &Suit suit)
{
    switch(suit)
    {
        case clubs:
            os << "C";
            break;
        case diamonds:
            os << "D";
            break;
        case hearts:
            os << "H";
            break;
        case spades:
            os << "S";
            break;
        default:
            os << "?";
            break;
    }

    return os;
}

Suit& operator<<(&Suit suit)
{
    if (static_cast<int>(suit) < static_cast<int>(Suit::undefined))
    {
        suit = static_cast<Suit>(static_cast<int>(suit) + 1);
    }

    return suit;
}
