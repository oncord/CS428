#ifndef CARD_CPP
#define CARD_CPP

// Card constructor 
template <typename R, typename S>
Card<R, S>::Card(R r, S s) : rank(r), suit(s) {}

// output stream operator
template <typename R, typename S>
std::ostream& operator<<(std::ostream& os, const Card<R, S>& card) {
    os << card.rank << card.suit;

    return os;
}

#endif // CARD_CPP
