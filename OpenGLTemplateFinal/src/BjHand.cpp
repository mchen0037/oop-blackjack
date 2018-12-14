#include <iostream>
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

  // add up card values, treat each Ace as 1
  int sum = 0;
  for (auto card: m_cards) {
    BjCard* bjCard = (BjCard*) card;
    if (!bjCard->getFace()) {
      continue;
    }
    if (bjCard->getRank() == 'A') {
      sum += 1;
    }
    else {
      sum += bjCard->getValue();
    }
  }
  // determine if hand contains an Ace
  bool containsAce = false;
  for (auto card: m_cards) {
    BjCard* bjCard = (BjCard*) card;
    if (!bjCard->getFace()) {
      continue;
    }
    if (bjCard->getRank() == 'A') {
      containsAce = true;
      break;
    }
  }
  // if hand contains Ace and total is low enough, treat Ace as 11
  if (containsAce && sum <= 11) {
    // add only 10, since we have already added 1 for the Ace when computing sum
    sum += 10;
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

// void BjHand::bust() {
//   std::cout << "Busted." << std::endl;
// }
