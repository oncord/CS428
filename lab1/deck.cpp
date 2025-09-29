#include "deck.h"

template <typename R, typename S>
void Deck<R,S>::shuffle()
{
    std::random_device dev;
    std::mt19937 gen(dev());

    std::shuffle(CardSet<R,S>::cards.begin(), CardSet<R,S>::cards.end(), gen);
}
