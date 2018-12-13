#include <iostream>
#include "BjGame.hpp"

BjGame::BjGame() {
  m_player = new BjPlayer();
  m_dealer = new BjDealer();
  m_deck = new BjDeck();
  m_deck->populate();
  m_deck->shuffle();
}

BjGame::~BjGame() {
  delete m_player;
  delete m_dealer;
  delete m_deck;
}

void BjGame::dealAdditionalCards(BjHand* t_hand) {
  const int PER_HAND = 1;
  std::vector<Hand*> players;
  players.push_back(t_hand);
  while (!(t_hand->isBusted()) && t_hand->isHitting()) {
    m_deck->deal(players, PER_HAND);
    this->printState();
    if (t_hand->isBusted()) {
      t_hand->bust();
    }
  }
}

void BjGame::play() {
  const int PER_HAND = 2;
  // allocating vector on the stack, will be automatically deleted when play() method exits
  std::vector<Hand*> players;
  players.push_back(m_player);
  players.push_back(m_dealer);
  // deal initial 2 cards to everyone
  try {
    m_deck->deal(players, PER_HAND);
  }
  catch (const char* msg) {
    // handle attempted deal of empty deck
    // need to populate deck, shuffle, and attempt deal again
    m_deck->populate();
    m_deck->shuffle();
    // now we for sure have cards in the deck.
    m_deck->deal(players, PER_HAND);
  }
  
  // hide dealer's first card
  m_dealer->flipFirstCard();
  this->printState();
  
  // deal additional cards to player
  // Continue asking if the player wants to hit or not or if he's busted.
  this->dealAdditionalCards(m_player);
  
  // reveal dealer's first card
  m_dealer->flipFirstCard();
  
  if (!m_player->isBusted()) {
    // Dealer's Turn.
    // deal additional cards to dealer
    this->printState();
    this->dealAdditionalCards(m_dealer);
    
    if (m_dealer->isBusted()) {
      // player wins
      m_player->win();
    }
    else {
      // compare player total to dealer total
      if (m_player->getTotal() > m_dealer->getTotal()) {
        m_player->win();
      }
      else if (m_player->getTotal() < m_dealer->getTotal()) {
        m_player->lose();
      }
      else {
        m_player->push();
      }
    }
  }
  // remove everyone's cards.
  m_player->clear();
  m_dealer->clear();
}

void BjGame::printState() {
  std::cout << "PLAYER: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_player->printHand();
  std::cout << "\tTotal Value: " << m_player->getTotal() << std::endl;

  std::cout << "DEALER: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_dealer->printHand();
  std::cout << "\tTotal Value: " << m_dealer->getTotal() << std::endl;

  std::cout << "DECK: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_deck->printHand();

}
