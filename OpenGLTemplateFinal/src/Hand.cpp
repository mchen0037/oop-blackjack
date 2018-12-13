#include "Hand.hpp"
#include "BjCard.hpp"
#include <iostream>

Hand::Hand() {}

// For Debugging
void Hand::printHand() {
  std::cout << "\t\t";
  for (std::vector<Card*>::iterator it = this->m_cards.begin();
    it != this->m_cards.end(); ++it ) {
    // handle case for face down
    if (!(*it)->getFace()) {
      // show XX
      std::cout << "XX, ";
    }
    else {
      std::cout << "[" << (*it)->getRank() << " " << (*it)->getSuit() << " " << (*it)->getFace() << "], ";
    }
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
  // When you give a card, set it to face up.
  c->setFace(true);
}
