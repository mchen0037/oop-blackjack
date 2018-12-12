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
  // TODO
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
