#include "Hand.hpp"
#include "BjCard.hpp"
#include <iostream>

Hand::Hand() {}

// For Debugging
void Hand::printHand() {
  for (std::vector<Card*>::iterator it = this->m_cards.begin();
    it != this->m_cards.end(); ++it ) {
    std::cout << "[" << (*it)->getRank() << " " << (*it)->getSuit() << " " << (*it)->getFace() << "], ";
  }
  std::cout << std::endl;
}

void Hand::printValue() {
  for (std::vector<Card*>::iterator it = this->m_cards.begin();
    it != this->m_cards.end(); ++it ) {
    BjCard* b = (BjCard*)*it;
    std::cout << (*it)->getRank() << " " << (*it)->getSuit() << ": " << b->getValue() << " " << std::endl;
  }
}

void Hand::clear() {
  m_cards.clear();
}

void Hand::addCard(Card* c) {
  m_cards.push_back(c);
}
