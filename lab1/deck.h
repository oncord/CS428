#ifndef DECK_H
#define DECK_H

#include "cardset.h"
#include <random>
#include <algorithm>

template<typename R, typename S>
class Deck : public CardSet<R, S> {
public:
    void shuffle();
    void collect(CardSet<R,S>& c);
};

template <typename R, typename S>
void Deck<R,S>::collect(CardSet<R,S>& c)
{
    while (!c.is_empty())
    {
        c >> *this;
    }
}

template <typename R, typename S>
void Deck<R,S>::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(this->cards.begin(), this->cards.end(), gen);
}

#endif // DECK_H
