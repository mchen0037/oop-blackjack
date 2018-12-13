#include "BjHand.hpp"
#include "BjCard.hpp"

BjHand::BjHand() : m_name("Player") {};

BjHand::BjHand(std::string t_name) {
  this->m_name = t_name;
}

std::string BjHand::getName() {
  return this->m_name;
}

int BjHand::getTotal() {
  int sum = 0;
  for (auto card: m_cards) {
    BjCard* b = (BjCard*) card;
    sum += b->getValue();
  }
  return sum;
}

void BjHand::setName(std::string t_name) {
  this->m_name = t_name;
  return;
}

bool BjHand::isBusted() {
  return (this->getTotal() > 21) ? true : false;
}
