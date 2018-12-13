#include <algorithm>
#include <random>
#include <chrono>

#include "Deck.hpp"
#include "Hand.hpp"

Deck::Deck() {
  Hand();
}

Deck::~Deck() { }

void Deck::populate() {
  for (auto suit : Card::SUITS) {
    for (auto rank : Card::RANKS) {
      this->m_cards.push_back(new Card(rank, suit, true));
    }
  }
}

void Deck::shuffle() {
  // http://www.cplusplus.com/reference/random/linear_congruential_engine/seed/
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beginning = myclock::now();
  myclock::duration d = myclock::now() - beginning;

  unsigned int seed2 = (unsigned int) d.count();
  std::minstd_rand0 generator (seed2);

  std::shuffle(std::begin(this->m_cards), std::end(this->m_cards), generator);
}

// TODO
void Deck::deal(std::vector<Hand*> t_players, int t_per_hand) {
  for (std::vector<Hand*>::iterator it = t_players.begin() ; it != t_players.end(); ++it) {
    Hand* currHand = *it;
    for (int i = 0; i < t_per_hand; ++i) {
      if (m_cards.size() > 0) {
        Card* top_card = m_cards.back();
        currHand->addCard(top_card);
        m_cards.pop_back();
      }
      else {
        throw "Can't continue deal.  Out of cards!";
      }
    }
  }
}

// Decks will only give the next card(m_cards->back())
void Deck::give(Hand* t_hand) {
  t_hand->addCard(m_cards.back());
  m_cards.pop_back();
}
