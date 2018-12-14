#ifndef BjDealer_hpp
#define BjDealer_hpp

#include "BjHand.hpp"

class BjDealer : public BjHand {
private:

public:
  // Constructors
  BjDealer();

  // Accessors

  // Methods
  bool isHitting();
  // void bust();
  void flipFirstCard();


};


#endif
