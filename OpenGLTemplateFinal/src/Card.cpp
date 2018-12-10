#include "Card.hpp"

Card::Card(char _rank, char _suit, bool _face): rank(_rank), suit(_suit), face_up(_face) {

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
