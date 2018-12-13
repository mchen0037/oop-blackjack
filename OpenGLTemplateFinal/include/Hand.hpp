#ifndef Hand_hpp
#define Hand_hpp

#include <vector>
#include "Card.hpp"

class Hand {
protected:
  std::vector<Card*> m_cards;

public:
  // Constructors
  Hand();
  // Accessors
  void printHand();
  void printValue();

  // Mutators
  void clear();
  void addCard(Card* c);


};

#endif
