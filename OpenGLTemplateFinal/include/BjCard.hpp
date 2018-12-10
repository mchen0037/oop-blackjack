#ifndef BjCard_h
#define BjCard_h

#include "Card.hpp"

class BjCard : public Card {
private:
  int value;

public:
  // Constructors
  BjCard();
  BjCard(char _rank, char _suit, bool _face);

  // Accessors
  int getValue() const;

  // Mutators
  // void setValue(const char _rank);

};

#endif
