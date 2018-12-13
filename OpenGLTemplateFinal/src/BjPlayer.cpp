#include <iostream>

#include "BjPlayer.hpp"

BjPlayer::BjPlayer() {
  this->setName("Player");
}

BjPlayer::BjPlayer(std::string t_name) {
  this->setName(t_name);
}

bool BjPlayer::isHitting() {
  // TODO: Ask for user input and then return if true if they decide to hit.
  char ans;
  std::cout << "Hit? (Y/N): ";
  std::cin >> ans;

  return (ans == 'Y' || ans == 'y');
}

void BjPlayer::bust() {
  std::cout << "Looks like you're busted.. " << std::endl;
  lose();
  // TODO
}

void BjPlayer::win() {
  std::cout << this->getName() << " wins!" << std::endl;
}

void BjPlayer::lose() {
  std::cout << this->getName() << " loses.." << std::endl;
}

void BjPlayer::push() {
  std::cout << "PUSH!! Tie Game. "<< std::endl;
}
