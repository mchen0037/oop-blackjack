#ifndef BjGame_hpp
#define BjGame_hpp

#include "BjPlayer.hpp"
#include "BjDealer.hpp"
#include "BjDeck.hpp"
#include "GlutApp.h"
#include "Shapes/TexRect.h"

class BjGame: public GlutApp {
private:
  BjPlayer* m_player;
  BjDealer* m_dealer;
  BjDeck* m_deck;

  TexRect* m_background;
  TexRect* card1;
  TexRect* card2;
  TexRect* Deck;
  
  int m_pos_x;
  
  bool m_gameEnded;
  bool m_isPlayerTurn;
  std::string m_end_str;
  
public:
  // Constructors
  BjGame(int argc, char** argv);
  
  // Destructor
  ~BjGame();

  // Methods
  void dealAdditionalCards(BjHand* t_hand);
  void dealOneCard(BjHand* t_hand);
  void play();
  void printState();
  
  
  void handleGameOver(std::string t_msg);

  // override from glutapp
  void draw();
  void keyDown(unsigned char key, float x, float y);
  void drawText(float, float, std::string);
  void drawDeck();
};


#endif
