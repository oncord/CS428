#ifndef CARDSET_H
#define CARDSET_H

#include "card.h"
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename R, typename S>
class CardSet {
protected:
    std::vector< Card<R, S> > cards;

public:
    CardSet() = default;
    CardSet(const CardSet<R,S>& other);

    static std::vector< Card<R,S> >* access(CardSet<R, S>& cs); 
    void print(std::ostream& os, size_t size) const;
    bool is_empty() const;
    CardSet<R,S>& operator>>(CardSet<R,S>& other);

    auto begin() { return cards.begin(); }
    auto end() { return cards.end(); }
    auto begin() const { return cards.begin(); }
    auto end() const { return cards.end(); }
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "cardset.cpp"
#endif

#endif // CARDSET_H
