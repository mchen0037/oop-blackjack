#include <iostream>
#include <algorithm>
#include <random>

#include "Deck.hpp"
#include "Hand.hpp"

Deck::Deck() {
  Hand();
  // Maybe move these into the Game object?
  populate();
  shuffle();
}

void Deck::populate() {
  const char RANKS[] =
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
  const char SUITS[] = {'C', 'D', 'H', 'S'};

  for (auto suit : SUITS) {
    for (auto rank : RANKS) {
      this->m_cards.push_back(new Card(rank, suit, false));
    }
  }
}

void Deck::shuffle() {
  // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
  auto rng = std::default_random_engine {};
  std::shuffle(std::begin(this->m_cards), std::end(this->m_cards), rng);
}

// TODO
void Deck::deal(std::vector<Hand*> t_players, int t_per_hand) {

}

// Decks will only give the next card(m_cards->back())
void Deck::give(Hand* t_hand) {
  t_hand->addCard(m_cards.back());
  m_cards.pop_back();
}
