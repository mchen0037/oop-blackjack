#include "Hand.hpp"
#include <iostream>

Hand::Hand() {}

// For Debugging
void Hand::printHand() {
  for (std::vector<Card*>::iterator it = m_cards.begin();
    it != m_cards.end(); ++it ) {
    std::cout << (*it)->getRank() << " " << (*it)->getSuit() << std::endl;
  }
}


void Hand::clear() {
  m_cards.clear();
}

void Hand::addCard(Card* c) {
  m_cards.push_back(c);
}
