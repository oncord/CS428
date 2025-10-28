#ifndef HOLDEMGAME_H
#define HOLDEMGAME_H

#include "cardset.h"
#include "HoldEmDeck.h"
#include "Game.h"
#include <vector>

enum class HoldEmHandRank {
    xhigh,
    pair,
    twopair,
    threeofakind,
    straight,
    flush,
    fullhouse,
    fourofakind,
    straightflush,
    undefined,
};

enum class HoldEmState {
    preflop = 0,
    flop,
    turn,
    river,
    undefined,
};

class HoldEmGame : public Game
{
private:
    struct PlayerHand {
        CardSet<HoldEmRank, Suit> hand;
        std::string name;
        HoldEmHandRank rank;

        PlayerHand(const CardSet<HoldEmRank, Suit>& h, const std::string& n, HoldEmHandRank r) : hand(h), name(n), rank(r) {}
    };

    HoldEmHandRank holdem_hand_evaluation(const CardSet<HoldEmRank, Suit>& hand) const;

    friend bool operator<(const PlayerHand& lhs, const PlayerHand& rhs);
protected:
    HoldEmState state;
    HoldEmDeck deck;
    std::vector<CardSet<HoldEmRank, Suit>> hands;
    CardSet<HoldEmRank, Suit> board;
    virtual void deal() override;

    void printHands() const;
    void printBoard(const std::string &label) const;
    void collectAll();
    bool askQuit() const;
public:
    HoldEmGame(int argc, const char * argv[]);
    virtual int play() override;
};

std::ostream& operator<<(std::ostream& os, const HoldEmHandRank& rank);

#endif // HOLDEMGAME_H
