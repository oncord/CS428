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

// compare by rank first, suit second
template <typename R, typename S>
bool cardRankLess(const Card<R,S>& c1, const Card<R,S>& c2)
{
    if (c1.rank < c2.rank) return true;
    if (c2.rank < c1.rank) return false;

    return c1.suit < c2.suit;
}

// compare by suit first, rank second
template <typename R, typename S>
bool cardSuitLess(const Card<R,S>& c1, const Card<R,S>& c2)
{
    if (c1.suit < c2.suit) return true;
    if (c2.suit < c1.suit) return false;

    return c1.rank < c2.rank;
}

#endif // CARD_H
