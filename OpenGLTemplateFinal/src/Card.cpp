#include "Card.hpp"
// #include <iostream>

Card::Card() {
  // std::cout << "Calling Card()" << std::endl;
  this->rank = 'N';
  this->suit = 'N';
  this->face_up = false;
}

Card::Card(char _rank, char _suit, bool _face) {
  this->rank = _rank;
  this->suit = _suit;
  this->face_up = _face;
}

char Card::getRank() const {
  return this->rank;
}
char Card::getSuit() const {
  return this->suit;
}
bool Card::getFace() const {
  return this->face_up;
}

void Card::setRank(const char _rank) {
  this->rank = _rank;
}
void Card::setSuit(const char _suit) {
  this->suit = _suit;
}
void Card::setFace(const bool _face) {
  this->face_up = _face;
}
