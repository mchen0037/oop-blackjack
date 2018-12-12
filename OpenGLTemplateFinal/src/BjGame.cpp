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
}
