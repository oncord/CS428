#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
protected:
    std::vector<std::string> players;
    virtual void deal() = 0;
public:
    Game(int argc, const char * argv[]);
    virtual int play() = 0;
};

#endif // GAME_H
