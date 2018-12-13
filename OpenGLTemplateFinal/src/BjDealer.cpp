#include <iostream>

#include "BjDealer.hpp"

BjDealer::BjDealer() {
  this->setName("Dealer");
}

bool BjDealer::isHitting() {
  return (this->getTotal() < 17);
}

void BjDealer::bust() {
  std::cout << "Dealer Busted!" << std::endl;
}

void BjDealer::flipFirstCard() {
  // by default, all cards will be face up initially.
  // this will just inverse the face up flag of the first card
  const bool isFaceUp = this->m_cards[0]->getFace();
  this->m_cards[0]->setFace(!isFaceUp); // flip
}
