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

