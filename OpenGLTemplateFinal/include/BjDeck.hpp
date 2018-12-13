#ifndef BjDeck_hpp
#define BjDeck_hpp

#include <vector>
#include "Deck.hpp"

class BjDeck : public Deck {
private:

public:
  // Constructors
  BjDeck();

  // Methods
  void populate() override;
};

#endif
