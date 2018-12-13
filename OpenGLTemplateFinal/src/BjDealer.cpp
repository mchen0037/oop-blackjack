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
  // It makes more sense to flip every card face up when you give it to them
  // and then setting the dealer's card to face down at the init of a turn.
  this->m_cards[0]->setFace(false);
}
