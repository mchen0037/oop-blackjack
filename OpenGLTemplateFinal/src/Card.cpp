#include "Card.hpp"
#include <iostream>
#include <string>

const char Card::SUITS[4] = {'c', 'd', 'h', 's'};
const char Card::RANKS[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
const std::string Card::BACK_OF_CARD_IMAGE_PATH = "assets/cards/back.png";

Card::Card() : m_rank('N'), m_suit('N'), m_face_up(false) {
}

Card::Card(char t_rank, char t_suit, bool t_face) : m_rank(t_rank), m_suit(t_suit), m_face_up(t_face) {
  setImageFilePath(t_rank, t_suit);
  // m_card_display = new TexRect(m_image_file_path, 0.0, 0.0, 0.4, 0.6);
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

std::string Card::getImageFilePath() const {
  if (!this->getFace()) {
    return BACK_OF_CARD_IMAGE_PATH;
  }
  else {
    return this->m_image_file_path;
  }
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

void Card::setImageFilePath(char t_rank, char t_suit) {
  m_image_file_path = "assets/cards/";
  m_image_file_path += t_rank;
  m_image_file_path += t_suit;
  m_image_file_path += ".png";
}

// draws the card onto the GUI given the x, y and z values.
void Card::drawCard(float t_x, float t_y, float t_z) {
  m_card_display = new TexRect(this->getImageFilePath(), t_x, t_y, 0.4, 0.6);
  // m_card_display->setX(t_x);
  // m_card_display->setY(t_y);
  m_card_display->draw(t_z);
}
