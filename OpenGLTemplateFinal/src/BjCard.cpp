#include "BjCard.hpp"

BjCard::BjCard() {

}

BjCard::BjCard(char t_rank, char t_suit, bool t_face): Card(t_rank, t_suit, t_face) {
  // Fine for now
  switch (t_rank) {
    case 'A':
      this->m_value = 11;
      break;
    case '2':
      this->m_value = 2;
      break;
    case '3':
      this->m_value = 3;
      break;
    case '4':
      this->m_value = 4;
        break;
    case '5':
      this->m_value = 5;
      break;
    case '6':
      this->m_value = 6;
      break;
    case '7':
      this->m_value = 7;
      break;
    case '8':
      this->m_value = 8;
      break;
    case '9':
      this->m_value = 9;
      break;
    case '0':
      this->m_value = 10;
      break;
    case 'J':
      this->m_value = 10;
      break;
    case 'Q':
      this->m_value = 10;
      break;
    case 'K':
      this->m_value = 10;
      break;
    default:
      this->m_value = -100;
  }
}

BjCard::~BjCard() {
  delete m_card_display;
}

int BjCard::getValue() const {
  return this->m_value;
}
