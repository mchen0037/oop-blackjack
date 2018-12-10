#ifndef Card_h
#define Card_h

class Card {
private:
  char rank;
  char suit;
  bool face_up;

public:
  // Constructors
  Card();
  Card(char _rank, char _suit, bool _face);

  // Accessors
  char getRank() const;
  char getSuit() const;
  bool getFace() const;

  // Mutators
  void setRank(const char _rank);
  void setSuit(const char _suit);
  void setFace(const bool _face);


};

// static char* SUIT = {'c', 'd', 'h', 's'};
// static char* RANKS = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

#endif
