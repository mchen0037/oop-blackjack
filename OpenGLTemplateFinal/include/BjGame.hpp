#ifndef BjGame_hpp
#define BjGame_hpp

#include "BjPlayer.hpp"
#include "BjDealer.hpp"
#include "BjDeck.hpp"


class BjGame{
private:
  BjPlayer* m_player;
  BjDealer* m_dealer;
  BjDeck* m_deck;

public:
  // Constructors
  BjGame();
  
  // Destructor
  ~BjGame();

  // Methods
  void dealAdditionalCards(BjHand* t_hand);
  void play();
  void printState();
  
  void handleGameOver(std::string t_msg);

};


#endif
