#include <iostream>

#include "BjDeck.hpp"
#include "BjCard.hpp"

// Decks should be populated and shuffled inside the Game Object/Main.
BjDeck::BjDeck() {
}

// Fill the Hand with BjCards instead of Cards.
void BjDeck::populate() {
  const char RANKS[] =
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
  const char SUITS[] = {'C', 'D', 'H', 'S'};

  for (auto suit : SUITS) {
    for (auto rank : RANKS) {
      this->m_cards.push_back(new BjCard(rank, suit, false));
    }
  }
}
