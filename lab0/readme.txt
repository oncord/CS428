CSE 4208 Lab 0: Cards and Decks
Student: Richard Meyer
Email: meyer.r.l@wustl.edu
Lab: 0

COMPILATION RESULTS:
===================

Compilation was successful with no errors or warnings encountered.

compiled with: g++ -std=c++17 -o lab0.exe lab0.cpp HoldEmDeck.cpp PinochleDeck.cpp suits.cpp

The compilation process completed without any compilation errors, warnings, or linker errors. All template instantiations resolved correctly, and the executable was generated successfully.

PROGRAM EXECUTION RESULTS:
=========================

The program executed successfully and produced the expected output:

Pinochle Deck (48 cards | 2 of each rank/suit combination):
9C 9C 9D 9D 9H 9H 9S 9S 
JC JC JD JD JH JH JS JS 
QC QC QD QD QH QH QS QS 
KC KC KD KD KH KH KS KS 
10C 10C 10D 10D 10H 10H 10S 10S 
AC AC AD AD AH AH AS AS 

Texas Hold'em Deck (52 cards | 1 of each rank/suit combination):
2C 2D 2H 2S 3C 3D 3H 3S 4C 4D 4H 4S 5C 
5D 5H 5S 6C 6D 6H 6S 7C 7D 7H 7S 8C 8D 
8H 8S 9C 9D 9H 9S 10C 10D 10H 10S JC JD JH 
JS QC QD QH QS KC KD KH KS AC AD AH AS 

VERIFICATION OF CORRECTNESS:
============================

Pinochle Deck Verification:
- Total cards: 48 (6 ranks × 4 suits × 2 copies = 48 cards) ✓
- Ranks present: 9, J, Q, K, 10, A (in correct order) ✓
- Suits present: C, D, H, S (in correct order) ✓
- Each rank/suit combination appears exactly twice ✓
- Format: 8 cards per line for readability ✓

Texas Hold'em Deck Verification:
- Total cards: 52 (13 ranks × 4 suits × 1 copy = 52 cards) ✓
- Ranks present: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A (in correct order) ✓
- Suits present: C, D, H, S (in correct order) ✓
- Each rank/suit combination appears exactly once ✓
- Format: 13 cards per line for readability ✓

IMPLEMENTATION DESIGN DECISIONS:
===============================

1. Template Design:
   - Used struct template for Card with two type parameters (R for rank, S for suit)
   - Implemented template definitions directly in header file for proper instantiation
   - Used explicit scoping with enum classes to avoid naming conflicts

2. Enum Class Design:
   - Suit enum: clubs, diamonds, hearts, spades, undefined
   - PinochleRank enum: nine, jack, queen, king, ten, ace, undefined
   - HoldEmRank enum: two through ace, undefined
   - All enums use monotonically increasing values as required

3. Operator Overloading:
   - Implemented operator<< for all enum types with appropriate string representations
   - Implemented prefix operator++ for all enum types with proper boundary checking
   - Used const references for input parameters to avoid unnecessary copying

4. Deck Class Hierarchy:
   - Abstract base class Deck with pure virtual print method
   - PinochleDeck and HoldEmDeck inherit from Deck
   - Used std::vector to store cards with appropriate template parameters

5. Print Formatting:
   - Pinochle deck: 8 cards per line (2 complete sets per line)
   - Hold'em deck: 13 cards per line (one complete rank per line)
   - Added descriptive headers for each deck type

6. Constructor Logic:
   - PinochleDeck: Creates 2 copies of each valid rank/suit combination
   - HoldEmDeck: Creates 1 copy of each valid rank/suit combination
   - Used nested loops with prefix increment operators to iterate through enums

ERRORS AND WARNINGS ENCOUNTERED:
================================

No compilation errors or warnings were encountered during development.

FILES INCLUDED IN SOLUTION:
===========================

Header Files:
- suits.h: Suit enum class and operator declarations
- card.h: Card struct template and operator declarations
- Deck.h: Abstract base class for decks
- PinochleDeck.h: PinochleRank enum and PinochleDeck class declarations
- HoldEmDeck.h: HoldEmRank enum and HoldEmDeck class declarations

Source Files:
- suits.cpp: Suit enum operator implementations
- PinochleDeck.cpp: PinochleRank operators and PinochleDeck implementation
- HoldEmDeck.cpp: HoldEmRank operators and HoldEmDeck implementation
- lab0.cpp: Main function with deck instantiation and printing

Build Files:
- CMakeLists.txt: CMake configuration for building the lab.


