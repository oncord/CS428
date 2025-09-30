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

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "deck.cpp"
#endif

#endif // DECK_H
