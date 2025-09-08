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
ostream& operator<<(ostream& o, &Suit s);

// increment Suit 
Suit& operator++(Suit& suit);

#endif // SUITS_H
