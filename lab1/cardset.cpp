#include "cardset.h"
#include <stdexcept>

template <typename R, typename S>
bool CardSet<R,S>::is_empty() const {
    return cards.empty();
}

template <typename R, typename S>
CardSet<R,S>& CardSet<R,S>::operator>>(CardSet<R,S>& other)
{
    if (cards.empty())
    {
        throw std::runtime_error("CardSet is empty, cant shift");
    }

    other.cards.push_back(cards.back());

    cards.pop_back();

    return *this;
}

template <typename R, typename S>
void CardSet<R, S>::print(std::ostream& os, size_t size) const 
{
    typename std::vector< Card<R, S> >::const_iterator it = cards.begin();
    size_t count = 0; // count # of cards per line

    for (size_t count = 0; it != cards.end(); it++)
    {
        os << *it << " ";
        count++;
        if (count % size == 0)
        {
            os << std::endl;
        }
    }
    
    if (count % size != 0)
    {
        os << std::endl;
    }
}
