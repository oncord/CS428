#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "Game.h"
#include "PinochleDeck.h"
#include "cardset.h"
#include <algorithm>
#include <vector>
#include <string>
#include <array>

enum class PinochleMelds
{
    dix,
    offsuitmarriage,
    fortyjacks,
    pinochle,
    insuitmarriage,
    sixtyqueens,
    eightykings,
    hundredaces,
    insuitrun,
    doublepinochle,
    fourhundredjacks,
    sixhundredqueens,
    eighthundredkings,
    thousandaces,
    insuitdoublerun
};

class PinochleGame : public Game
{
private:
    void suit_independent_evaluation(
        const CardSet<PinochleRank, Suit>& hand,
        std::vector<PinochleMelds>& melds
    ) const;

protected:
    PinochleDeck deck;
    std::vector< CardSet<PinochleRank,Suit> > hands;
    virtual void deal() override;
    void collectHands();
    bool askQuit() const;
public:
    PinochleGame(int argc, const char * argv[]);
    virtual int play() override;
    static const std::array<unsigned int, 15> meldPoints;
};

std::ostream& operator<<(std::ostream &os, const PinochleMelds &meld);

#endif // PINOCHLEGAME_H
