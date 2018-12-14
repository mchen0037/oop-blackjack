#ifndef BjHand_hpp
#define BjHand_hpp

#include "Hand.hpp"
#include <string>

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

  // virtual void bust();

  virtual bool isHitting() = 0;

};

#endif
