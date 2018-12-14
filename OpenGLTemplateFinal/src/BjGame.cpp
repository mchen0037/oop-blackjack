#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include "BjGame.hpp"

BjGame::BjGame(int argc, char** argv): GlutApp(argc, argv) {
  m_pos_x = -0.8;
  m_player = new BjPlayer();
  m_dealer = new BjDealer();
  m_deck = new BjDeck();
  m_deck->populate();
  m_deck->shuffle();
  
  m_background = new TexRect("assets/green_board.png", -1.5, 1.5, 3, 3);
//  card1 = new TexRect("assets/cards/0c.png", -0.8, 0.9, 0.4, 0.6);
//  card2 = new TexRect("assets/cards/Qc.png", -0.8, 0.0, 0.4, 0.6);
  
  m_gameEnded = false;
  m_isPlayerTurn = true;
  m_end_str = "";
  this->play();
}

BjGame::~BjGame() {
  delete m_player;
  delete m_dealer;
  delete m_deck;
  
  delete m_background;
//  delete card1;
//  delete card2;
}

void BjGame::dealAdditionalCards(BjHand* t_hand) {
  const int PER_HAND = 1;
  std::vector<Hand*> players;
  players.push_back(t_hand);
  while (!(t_hand->isBusted()) && t_hand->isHitting()) {
    m_deck->deal(players, PER_HAND);
    this->printState();
  }
  
  
}

void BjGame::play() {
  const int PER_HAND = 2;
  // allocating vector on the stack, will be automatically deleted when play() method exits
  std::vector<Hand*> players;
  players.push_back(m_player);
  players.push_back(m_dealer);
  // deal initial 2 cards to everyone
  try {
    m_deck->deal(players, PER_HAND);
  }
  catch (const char* msg) {
    // handle attempted deal of empty deck
    // need to populate deck, shuffle, and attempt deal again
    m_deck->populate();
    m_deck->shuffle();
    // now we for sure have cards in the deck.
    m_deck->deal(players, PER_HAND);
  }
  
  // hide dealer's first card
  m_dealer->flipFirstCard();
  
  // after hiding card, we should update GUI and then wait for key press
  this->printState();
  redraw();
  return;
  
  // deal additional cards to player
  // Continue asking if the player wants to hit or not or if he's busted.
  this->dealAdditionalCards(m_player);
  m_isPlayerTurn = false;
  
  // reveal dealer's first card
  m_dealer->flipFirstCard();
  
  if (!m_player->isBusted()) {
    // Dealer's Turn.
    // deal additional cards to dealer
    this->printState();
    this->dealAdditionalCards(m_dealer);
    
    if (m_dealer->isBusted()) {
      // player wins
      this->handleGameOver("Dealer Busted. Player Wins!");
      
    }
    else {
      // compare player total to dealer total
      if (m_player->getTotal() > m_dealer->getTotal()) {
        this->handleGameOver("Player Wins!");
      }
      else if (m_player->getTotal() < m_dealer->getTotal()) {
        this->handleGameOver("Player Loses. Dealer Wins.");
      }
      else {
        this->handleGameOver("PUSH!");
      }
    }
  }
  else {
    // player busted
    this->handleGameOver("Player Busted. You Lose.");
  }
  // remove everyone's cards.
  m_player->clear();
  m_dealer->clear();
}

void BjGame::printState() {
  std::cout << "PLAYER: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_player->printHand();
  std::cout << "\tTotal Value: " << m_player->getTotal() << std::endl;

  std::cout << "DEALER: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_dealer->printHand();
  std::cout << "\tTotal Value: " << m_dealer->getTotal() << std::endl;

  std::cout << "DECK: " << std::endl;
  std::cout << "\t Hand: " << std::endl;
  m_deck->printHand();

}


void BjGame::handleGameOver(std::string t_msg) {
  std::cout << t_msg << std::endl;
  m_gameEnded = true;
  m_end_str = t_msg;
}

void BjGame::draw() {
  std::cout << "CALLING DRAW" << std::endl;
  if(m_gameEnded) {
    drawText(-0.2, 0.2, m_end_str);
    drawText(-0.2, 0.1, "Play Again? y for YES / n for NO ");
  }
  
  drawText(0.8, 0.6, "TOTAL: " + std::to_string(m_dealer->getTotal()));
  drawText(0.8, -0.3, "TOTAL: " + std::to_string(m_player->getTotal()));

  
  drawText(-0.8, -0.9, "Press h to HIT");
  drawText(0.2, -0.9, "Press s to STAND");
  m_background->draw(0.0);

//  card1->draw(0.10);
//  card2->draw(0.20);
  
  // draw dealer and player deck
  m_dealer->drawHand();
  m_player->drawHand();
  
  drawDeck();
}

void BjGame::keyDown(unsigned char key, float x, float y){
  if (key == 27){
    exit(0);
  }
  
  if (key == 'h'){
    
  }
  else if (key == 's'){
    
  }
  redraw();
}

/**
 Float, Float -> Void
 This is a helper method for drawing text onto the screen.  It is called from the draw() method.
 The Float parameters are taken in as x and y coordinates for where the text is displayed on the app.
 The string printed out will be from the 'strings' constant array of strings at the very top.
 */
void BjGame::drawText(float t_x, float t_y, std::string t_text) {
  glBegin(GL_TEXTURE);
  glRasterPos2f(t_x, t_y); // sets position of text in window
  const char* cstr = t_text.c_str();
  for (int i = 0; i < t_text.length(); i++) {
    // loop through characters of state string and print each out
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, cstr[i]);
  }
  glEnd();
}

void BjGame::drawDeck() {
  for(int i = 40; i > 0; i--) {
    TexRect* card = new TexRect("assets/cards/back.png", -1.4+(i*0.001), 0.45, 0.4, 0.6);
    card->draw(i*0.01);
    delete card;
  }

}

