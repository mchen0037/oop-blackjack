#include <iostream>
#include "BjGame.hpp"

BjGame::BjGame() {
  m_player = new BjPlayer();
  m_dealer = new BjDealer();
  m_deck = new BjDeck();
}

bool BjGame::stillPlaying() {
  // TODO
  return true;
}

void BjGame::dealCards(BjHand* t_hand) {
  // TODO
}

void BjGame::play() {
  // Player's turn
  // Continue asking if the player wants to hit or not or if he's busted.
  while (!this->m_player->isBusted() && this->m_player->isHitting()) {
    this->m_deck->give(m_player);
    this->printState();
  }
  if (m_player->isBusted()) {
    m_player->bust();
    goto playerBusted;
  }

  // Dealer's Turn.
  while (!this->m_dealer->isBusted() && this->m_dealer->isHitting()) {
    this->m_deck->give(m_dealer);
    this->printState();
  }
  if (m_dealer->isBusted()) {
    m_dealer->bust();
    goto dealerBusted;
  }

  if (m_player->getTotal() > m_dealer->getTotal()) {
dealerBusted:
    m_player->win();
  }
  else if (m_player->getTotal() < m_dealer->getTotal()){
playerBusted:
    m_player->lose();
  }
  else {
    m_player->push();
  }
}

void BjGame::init() {
  this->m_deck->populate();
  this->m_deck->shuffle();

  this->m_deck->give(m_player);
  this->m_deck->give(m_dealer);
  this->m_deck->give(m_player);
  this->m_deck->give(m_dealer);
  this->m_dealer->flipFirstCard();
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
