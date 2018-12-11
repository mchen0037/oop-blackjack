#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include "Card.hpp"
#include "Hand.hpp"

class Deck : public Hand {
private:

public:
  // Constructors
  Deck();

  // Methods
  void populate();
  void shuffle();
  void deal(std::vector<Hand*> t_players, int t_per_hand);
  void give(Card* t_card, Hand* t_hand);
};

#endif
