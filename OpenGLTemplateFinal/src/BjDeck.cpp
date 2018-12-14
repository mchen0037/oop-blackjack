#include "BjDeck.hpp"
#include "BjCard.hpp"
#include <iostream>
#include <string>

// Decks should be populated and shuffled inside the Game Object/Main.
BjDeck::BjDeck() {
}

// Fill the Hand with BjCards instead of Cards.
void BjDeck::populate() {
  for (auto suit : Card::SUITS) {
    for (auto rank : Card::RANKS) {
      this->m_cards.push_back(new BjCard(rank, suit, true));
    }
  }
}
