#include "Card.hpp"
// #include <iostream>

Card::Card() : m_rank('N'), m_suit('N'), m_face_up(false) {
}

Card::Card(char t_rank, char t_suit, bool t_face) : m_rank(t_rank), m_suit(t_suit), m_face_up(t_face) {
}

char Card::getRank() const {
  return this->m_rank;
}
char Card::getSuit() const {
  return this->m_suit;
}
bool Card::getFace() const {
  return this->m_face_up;
}

void Card::setRank(const char t_rank) {
  this->m_rank = t_rank;
}
void Card::setSuit(const char t_suit) {
  this->m_suit = t_suit;
}
void Card::setFace(const bool t_face) {
  this->m_face_up = t_face;
}
