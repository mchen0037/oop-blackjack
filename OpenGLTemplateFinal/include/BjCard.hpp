#ifndef BjCard_hpp
#define BjCard_hpp

#include "Card.hpp"

class BjCard : public Card {
private:
  int m_value;

public:
  // Constructors
  BjCard();
  BjCard(char t_rank, char t_suit, bool t_face);

  // Accessors
  int getValue() const;

};

#endif
