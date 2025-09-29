#include "cardset.h"
#include <stdexcept>

template <typename R, typename S>
bool CardSet<R,S>::is_empty() const {
    return cards.empty();
}

template <typename R, typename S>
void CardSet<R, S>::print(std::ostream& os, size_t size) 
{
    typename std::vector< Card<R, S> >::iterator it = cards.begin();
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
