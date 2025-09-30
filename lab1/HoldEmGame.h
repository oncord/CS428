#ifndef HOLDEMGAME_H
#define HOLDEMGAME_H

#include "cardset.h"
#include "HoldEmDeck.h"
#include "Game.h"
#include <vector>

enum class HoldEmState {
    preflop = 0,
    flop,
    turn,
    river,
    undefined,
};

class HoldEmGame : public Game
{
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

#endif // HOLDEMGAME_H
