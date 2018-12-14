#ifndef BjHand_hpp
#define BjHand_hpp

#include <string>
#include "Hand.hpp"

class BjHand : public Hand {
private:
  std::string m_name;

public:
  // Constructors
  BjHand();
  BjHand(std::string name);

  // Accessors
  std::string getName();
  int getTotal();

  // Mutators
  void setName(std::string t_name);

  // Methods
  bool isBusted();

  // virtual methods
  virtual bool isHitting() = 0;
  virtual void drawHand() = 0;

};

#endif
