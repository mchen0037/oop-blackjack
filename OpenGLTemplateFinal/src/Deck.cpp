#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

#include "Deck.hpp"
#include "Hand.hpp"

Deck::Deck() {
  Hand();
}

void Deck::populate() {
  const char RANKS[] =
    {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
  const char SUITS[] = {'C', 'D', 'H', 'S'};

  for (auto suit : SUITS) {
    for (auto rank : RANKS) {
      this->m_cards.push_back(new Card(rank, suit, true));
    }
  }
}

void Deck::shuffle() {
  // http://www.cplusplus.com/reference/random/linear_congruential_engine/seed/
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beginning = myclock::now();
  myclock::duration d = myclock::now() - beginning;

  unsigned seed2 = d.count();
  std::minstd_rand0 generator (seed2);

  std::shuffle(std::begin(this->m_cards), std::end(this->m_cards), generator);
}

// TODO
void Deck::deal(std::vector<Hand*> t_players, int t_per_hand) {

}

// Decks will only give the next card(m_cards->back())
void Deck::give(Hand* t_hand) {
  t_hand->addCard(m_cards.back());
  m_cards.pop_back();
}
