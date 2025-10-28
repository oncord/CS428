#ifndef DECK_H
#define DECK_H

#include <iostream>

class Deck {
public:
    // pure virtual print method
    virtual void print(std::ostream& os) = 0;
    
    // virtual destructor for cleanup
    virtual ~Deck() = default;
};

#endif // DECK_H
