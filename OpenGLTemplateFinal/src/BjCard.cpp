#include "BjCard.hpp"
#include <iostream>

BjCard::BjCard() {

}

BjCard::BjCard(char _rank, char _suit, bool _face) {
  // std::cout << "Creating a BjCard with: " << _rank << " " << _suit << std::endl;
  this->setRank(_rank);
  this->setSuit(_suit);
  this->setFace(_face);

  // Better way to handle this?
  switch (_rank) {
    case 'A':
      this->value = 11;
      break;
    case '2':
      this->value = 2;
      break;
    case '3':
      this->value = 3;
      break;
    case '4':
      this->value = 4;
        break;
    case '5':
      this->value = 5;
      break;
    case '6':
      this->value = 6;
      break;
    case '7':
      this->value = 7;
      break;
    case '8':
      this->value = 8;
      break;
    case '9':
      this->value = 9;
      break;
    case '0':
      this->value = 10;
      break;
    case 'J':
      this->value = 10;
      break;
    case 'Q':
      this->value = 10;
      break;
    case 'K':
      this->value = 10;
      break;
    default:
      this->value = -100;
  }

  // std::cout << "Created a BjCard with value " << this->value << std::endl;
}

int BjCard::getValue() const {
  return this->value;
}

// char BjCard::getRank() const {
//   return this->rank;
// }
// char BjCard::getSuit() const {
//   return this->suit;
// }
// bool BjCard::getFace() const {
//   return this->face_up;
// }
//
// void BjCard::setRank(const char _rank) {
//   this->rank = _rank;
// }
// void BjCard::setSuit(const char _suit) {
//   this->suit = _suit;
// }
// void BjCard::setFace(const bool _face) {
//   this->face_up = _face;
// }
