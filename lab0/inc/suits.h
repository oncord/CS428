#ifndef SUITS_H
#define SUITS_H

#include <iostream>

// enum class for card suits
enum class Suit {
    clubs,          // 0
    diamonds,       // 1
    hearts,         // 2
    spades,         // 3
    undefined       // 4 -> MAX
};

// output stream operator for displaying Suit
std::ostream& operator<<(std::ostream& os, const Suit& suit);

// prefix increment operator for Suit
Suit& operator++(Suit& suit);

#endif // SUITS_H
