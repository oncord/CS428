#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "Game.h"
#include "PinochleDeck.h"
#include "cardset.h"
#include <vector>
#include <string>

class PinochleGame : public Game
{
protected:
    PinochleDeck deck;
    std::vector< CardSet<PinochleRank,Suit> > hands;
    virtual void deal() override;
    void printHands() const;
    void collectHands();
    bool askQuit() const;
public:
    PinochleGame(int argc, const char * argv[]);
    virtual int play() override;
};

#endif // PINOCHLEGAME_H
