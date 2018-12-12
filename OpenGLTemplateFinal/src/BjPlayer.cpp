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

  return false;
}

void BjPlayer::bust() {
  // TODO
}

void BjPlayer::win() {
  // TODO
}

void BjPlayer::lose() {
  // TODO
}

void BjPlayer::push() {
  // TODO
}
