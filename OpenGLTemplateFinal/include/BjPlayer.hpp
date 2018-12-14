#ifndef BjPlayer_hpp
#define BjPlayer_hpp

#include <string>
#include "BjHand.hpp"

class BjPlayer : public BjHand {
private:

public:
  // Constructors
  BjPlayer();
  BjPlayer(std::string t_name);

  // Methods
  bool isHitting();
  // void bust();
  // void lose();
  // void win();
  // void push(); // tie
  void drawHand();

};


#endif
