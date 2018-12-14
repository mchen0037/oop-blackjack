#include <iostream>

#include "BjPlayer.hpp"

BjPlayer::BjPlayer() {
  this->setName("Player");
}

BjPlayer::BjPlayer(std::string t_name) {
  this->setName(t_name);
}

// This function waso nly being used for the terminal version
// but after integrating it to the glutapp, it is no longer being used.
// Will keep this here because the function is pure virtual in BjHand.
bool BjPlayer::isHitting() {
  char ans;
  std::cout << "Hit? (Y/N): ";
  std::cin >> ans;

  return (ans == 'Y' || ans == 'y');
}

void BjPlayer::drawHand() {
  float j = 0.1;
  for (int i = 0; i < m_cards.size(); ++i) {
    m_cards[i]->drawCard(-0.8 + j, 0.0, 0.1 + j);
    j += 0.1;
  }
}
