/*
 *  HoldEmGame.cpp
 *  Author: Richard Meyer
 *  Definitions for HoldEmGame class for dealing logic
 */

#include "HoldEmGame.h"
#include <stdexcept>
#include <map>
#include "util.h"

const size_t HOLDEM_HOLE_CARDS = 2;
const size_t HOLDEM_FLOP_CARDS = 3;
const size_t HOLDEM_TURN_CARDS = 1;
const size_t HOLDEM_RIVER_CARDS = 1;
const size_t HOLDEM_HAND_CARDS_PER_LINE = 2;
const size_t HOLDEM_BOARD_CARDS_PER_LINE = 5;
const std::string AFFIRMATIVE_RESPONSE = "yes";

HoldEmGame::HoldEmGame(int argc, const char * argv[]) : Game(argc, argv), state(HoldEmState::preflop)
{
    for (size_t i = 0; i < players.size(); i++)
    {
        hands.emplace_back();
    }
}

void HoldEmGame::deal()
{
    switch (state)
    {
        case HoldEmState::preflop:
            for (size_t round = 0; round < HOLDEM_HOLE_CARDS; round++)
            {
                for (auto& hand : hands)
                {
                    if (deck.is_empty())
                    {
                        throw std::runtime_error("deck empty during preflop deal.\n");
                    }
                    deck >> hand;
                }
            }
            state = HoldEmState::flop;
            break;

        case HoldEmState::flop:
            for (size_t i = 0; i < HOLDEM_FLOP_CARDS; i++)
            {
                if (deck.is_empty())
                {
                throw std::runtime_error("deck empty during flop.\n");
                }
                deck >> board;
            }
            state = HoldEmState::turn;
            break;

        case HoldEmState::turn:
            if (deck.is_empty())
            {
                throw std::runtime_error("deck empty during turn deal.\n");
            }
            deck >> board;
            state = HoldEmState::river;
            break;

        case HoldEmState::river:
            if (deck.is_empty())
            {
                throw std::runtime_error("deck empty during river deal.\n");
            }
            deck >> board;
            state = HoldEmState::undefined;
            break;

        case HoldEmState::undefined:
            break;
    }
}

void HoldEmGame::printHands() const
{
    for (size_t i = 0; i < players.size(); i++)
    {
        std::cout << players[i] << "'s hand: ";
        hands[i].print(std::cout, HOLDEM_HAND_CARDS_PER_LINE);
    }
}

void HoldEmGame::printBoard(const std::string& label) const
{
    std::cout << "BOARD (" << label << "): ";
    board.print(std::cout, HOLDEM_BOARD_CARDS_PER_LINE);
    std::cout << std::endl;
}

void HoldEmGame::collectAll()
{
    for (auto& hand : hands)
    {
        deck.collect(hand);
    }
    deck.collect(board);
}

int HoldEmGame::play()
{
    while (true)
    {
        deck.shuffle();
        state = HoldEmState::preflop;

        // deal hole cards to each player
        deal();
        printHands();

        // deal the flop (3 cards)
        deal();
        printBoard("flop");

        // create vector of PlayerHand structs per player
        std::vector<PlayerHand> playerHands;
        for (size_t i = 0; i < players.size(); i++)
        {
            playerHands.emplace_back(hands[i], players[i], HoldEmHandRank::undefined);
        }

        // combine each player's hand with flop
        for (auto &ph : playerHands)
        {
            // add 3 flop cards from board
            for (const auto &card : board)
            {
                CardSet<HoldEmRank, Suit>::access(ph.hand)->push_back(card);
            }

            // evaluate 5-card hand
            ph.rank = holdem_hand_evaluation(ph.hand);
        }

        // sort hands
        std::sort(playerHands.begin(), playerHands.end());

        std::cout << "\n--- after flop ---\n";
        for (auto it = playerHands.rbegin(); it != playerHands.rend(); it++)
        {
            std::cout << it->name << ": ";
            it->hand.print(std::cout, HOLDEM_HAND_CARDS_PER_LINE);
            std::cout << "Rank: " << it->rank << "\n";
        }
        std::cout << std::endl;

        // turn
        deal();
        printBoard("turn");
    
        // river
        deal();
        printBoard("river");

        // collect cards for next round
        collectAll();

        std::cout << "end the game? (yes/no): ";
        std::string res;
        std::cin >> res;

        if (res == AFFIRMATIVE_RESPONSE)
        {
            return ExitCode::Success;
        }
    }
}

static std::vector<HoldEmRank> getSortedRanks(const CardSet<HoldEmRank, Suit>& hand)
{
    std::vector<HoldEmRank> ranks;
    for (const auto& card : hand)
    {
        ranks.push_back(card.rank);
    }
    std::sort(ranks.begin(), ranks.end());

    return ranks;
}

bool operator<(const HoldEmGame::PlayerHand& lhs, const HoldEmGame::PlayerHand& rhs)
{
    // compare overall hand rank
    if (lhs.rank != rhs.rank)
    {
        return lhs.rank < rhs.rank;
    }

    // get sorted ranks 
    std::vector<HoldEmRank> lRanks = getSortedRanks(lhs.hand);
    std::vector<HoldEmRank> rRanks = getSortedRanks(rhs.hand);

    // helper lambda to reverse-compare high to low
    auto lexicographicCompare = [](const std::vector<HoldEmRank>& a, const std::vector<HoldEmRank>& b)
    {
        for (int i = (int)a.size() - 1; i >= 0; i--)
        {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    };

    switch (lhs.rank)
    {
        case HoldEmHandRank::pair:
        case HoldEmHandRank::twopair:
        case HoldEmHandRank::threeofakind:
        case HoldEmHandRank::straight:
        case HoldEmHandRank::flush:
        case HoldEmHandRank::fullhouse:
        case HoldEmHandRank::fourofakind:
        case HoldEmHandRank::straightflush:
        case HoldEmHandRank::xhigh:
        {
            break;
        }

        default:
            return false;
    }

    // for flushes, straights, xhigh compare ranks descend
    if (lhs.rank == HoldEmHandRank::flush ||
        lhs.rank == HoldEmHandRank::xhigh ||
        lhs.rank == HoldEmHandRank::straight)
    {
        return lexicographicCompare(lRanks, rRanks);
    }

    // Straight flush is same logic as straight
    if (lhs.rank == HoldEmHandRank::straightflush)
        return lRanks.back() < rRanks.back();

    // Four of a kind
    if (lhs.rank == HoldEmHandRank::fourofakind)
    {
        // find 4-of-a-kind rank
        auto getFourRank = [](const std::vector<HoldEmRank>& v) {
            std::map<HoldEmRank, int> cnt;
            for (auto r : v) cnt[r]++;
            for (auto& p : cnt)
                if (p.second == 4) return p.first;
            return v.front();
        };
        HoldEmRank lFour = getFourRank(lRanks);
        HoldEmRank rFour = getFourRank(rRanks);
        if (lFour != rFour) return lFour < rFour;
        return lexicographicCompare(lRanks, rRanks);
    }

    // Full house
    if (lhs.rank == HoldEmHandRank::fullhouse)
    {
        auto getTripAndPair = [](const std::vector<HoldEmRank>& v) {
            std::map<HoldEmRank, int> cnt;
            for (auto r : v) cnt[r]++;
            HoldEmRank trip{}, pair{};
            for (auto& p : cnt) {
                if (p.second == 3) trip = p.first;
                else if (p.second == 2) pair = p.first;
            }
            return std::make_pair(trip, pair);
        };
        auto [lTrip, lPair] = getTripAndPair(lRanks);
        auto [rTrip, rPair] = getTripAndPair(rRanks);
        if (lTrip != rTrip) return lTrip < rTrip;
        return lPair < rPair;
    }

    // Three of a kind
    if (lhs.rank == HoldEmHandRank::threeofakind)
    {
        std::map<HoldEmRank, int> lCount, rCount;
        for (auto r : lRanks) lCount[r]++;
        for (auto r : rRanks) rCount[r]++;
        HoldEmRank lThree{}, rThree{};
        for (auto& p : lCount) if (p.second == 3) lThree = p.first;
        for (auto& p : rCount) if (p.second == 3) rThree = p.first;
        if (lThree != rThree) return lThree < rThree;
        return lexicographicCompare(lRanks, rRanks);
    }

    // Two pair
    if (lhs.rank == HoldEmHandRank::twopair)
    {
        auto getPairs = [](const std::vector<HoldEmRank>& v) {
            std::map<HoldEmRank, int> cnt;
            for (auto r : v) cnt[r]++;
            std::vector<HoldEmRank> pairs;
            HoldEmRank kicker{};
            for (auto& p : cnt) {
                if (p.second == 2) pairs.push_back(p.first);
                else kicker = p.first;
            }
            std::sort(pairs.begin(), pairs.end());
            return std::make_tuple(pairs[1], pairs[0], kicker); // high, low, kicker
        };
        auto [lHigh, lLow, lKick] = getPairs(lRanks);
        auto [rHigh, rLow, rKick] = getPairs(rRanks);
        if (lHigh != rHigh) return lHigh < rHigh;
        if (lLow != rLow) return lLow < rLow;
        return lKick < rKick;
    }

    // Pair
    if (lhs.rank == HoldEmHandRank::pair)
    {
        auto getPairAndKickers = [](const std::vector<HoldEmRank>& v) {
            std::map<HoldEmRank, int> cnt;
            for (auto r : v) cnt[r]++;
            HoldEmRank pair{};
            std::vector<HoldEmRank> kickers;
            for (auto& p : cnt) {
                if (p.second == 2) pair = p.first;
                else kickers.push_back(p.first);
            }
            std::sort(kickers.begin(), kickers.end());
            return std::make_pair(pair, kickers);
        };
        auto [lPair, lKick] = getPairAndKickers(lRanks);
        auto [rPair, rKick] = getPairAndKickers(rRanks);
        if (lPair != rPair) return lPair < rPair;
        return lexicographicCompare(lKick, rKick);
    }

    return false; // equal
}

std::ostream& operator<<(std::ostream& os, const HoldEmHandRank& rank)
{
    switch (rank)
    {
        case HoldEmHandRank::xhigh:          os << "xhigh"; break;
        case HoldEmHandRank::pair:           os << "pair"; break;
        case HoldEmHandRank::twopair:        os << "twopair"; break;
        case HoldEmHandRank::threeofakind:   os << "threeofakind"; break;
        case HoldEmHandRank::straight:       os << "straight"; break;
        case HoldEmHandRank::flush:          os << "flush"; break;
        case HoldEmHandRank::fullhouse:      os << "fullhouse"; break;
        case HoldEmHandRank::fourofakind:    os << "fourofakind"; break;
        case HoldEmHandRank::straightflush:  os << "straightflush"; break;
        case HoldEmHandRank::undefined:      os << "undefined"; break;
        default:                             os << "unknown"; break;
    }

    return os;
}

HoldEmHandRank HoldEmGame::holdem_hand_evaluation(const CardSet<HoldEmRank, Suit>& hand) const
{
    // 5 card rule
    if (std::distance(hand.begin(), hand.end()) != 5)
    {
        return HoldEmHandRank::undefined;
    }

    // deep copy and sort by rank, suit
    CardSet<HoldEmRank, Suit> copy(hand);
    std::sort(copy.begin(), copy.end(), cardRankLess<HoldEmRank, Suit>);

    // count ranks and suits
    std::map<HoldEmRank, int> rankCount;
    std::map<Suit, int> suitCount;

    for (const auto &card : *CardSet<HoldEmRank, Suit>::access(copy))
    {
        rankCount[card.rank]++;
        suitCount[card.suit]++;
    }

    bool flush = (suitCount.size() == 1);
    std::vector<HoldEmRank> ranks;
    for (const auto &card : *CardSet<HoldEmRank, Suit>::access(copy))
    {
        ranks.push_back(card.rank);
    }

    // helper lambda to check consecutive ranks
    auto isConsecutive = [&](std::vector<HoldEmRank> r) -> bool
    {
        std::vector<int> vals;
        for (auto rank : r)
        {
            vals.push_back(static_cast<int>(rank));
        }

        std::sort(vals.begin(), vals.end());

        bool lowAce = (vals == std::vector<int>{0, 1, 2, 3, 12});
        bool highAce = (vals == std::vector<int>{8, 9, 10, 11, 12});

        if (lowAce || highAce)
        {
            return true;
        }

        for (size_t i = 1; i < vals.size(); i++)
        {
            if (vals[i] != vals[i - 1] + 1)
            {
                return false;
            }
        }

        return true;
    };

    bool straight = isConsecutive(ranks);

    std::vector<int> freq;
    for (auto &p : rankCount)
    {
        freq.push_back(p.second);
    }
    std::sort(freq.begin(), freq.end(), std::greater<int>());

    // Straight Flush
    if (flush && straight)
        return HoldEmHandRank::straightflush;

    // Four of a Kind
    if (freq[0] == 4)
        return HoldEmHandRank::fourofakind;

    // Full House
    if (freq[0] == 3 && freq[1] == 2)
        return HoldEmHandRank::fullhouse;

    // Flush
    if (flush)
        return HoldEmHandRank::flush;

    // Straight
    if (straight)
        return HoldEmHandRank::straight;

    // Three of a Kind
    if (freq[0] == 3)
        return HoldEmHandRank::threeofakind;

    // Two Pair
    if (freq[0] == 2 && freq[1] == 2)
        return HoldEmHandRank::twopair;

    // One Pair
    if (freq[0] == 2)
        return HoldEmHandRank::pair;

    // High Card
    return HoldEmHandRank::xhigh;
}

