#ifndef CARD_H
#define CARD_H

#include <iostream>

template <typename R, typename S>
struct Card {
    R rank;
    S suit;

    Card(R r, S s) : rank(r), suit(s) {}
};

template <typename R, typename S>
std::ostream& operator<<(std::ostream& os, const Card<R, S>& card) {
    os << card.rank << card.suit;
    return os;
}

#endif // CARD_H
