#include <iostream>

#include "BjDealer.hpp"

BjDealer::BjDealer() {
  this->setName("Dealer");
}

void BjDealer::bust() {
  std::cout << "Dealer Busted!" << std::endl;
}

void BjDealer::flipFirstCard() {
  this->m_cards[0]->setFace(true);
}
