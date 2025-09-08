#include <iostream>
#include "PinochleDeck.h"
#include "HoldEmDeck.h"

using namespace std;

int main() {
    // create instances of both deck types
    PinochleDeck pinochleDeck;
    HoldEmDeck holdEmDeck;
    
    // print the Pinochle deck
    cout << "Pinochle Deck (48 cards | 2 of each rank/suit combination):" << endl;
    pinochleDeck.print(cout);
    cout << endl;
    
    // print the Texas Hold'em deck
    cout << "Texas Hold'em Deck (52 cards | 1 of each rank/suit combination):" << endl;
    holdEmDeck.print(cout);
    
    return 0;
}
