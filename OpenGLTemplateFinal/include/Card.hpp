#ifndef Card_hpp
#define Card_hpp

class Card {
private:
  char m_rank;
  char m_suit;
  bool m_face_up;

public:
  // Constructors
  Card();
  Card(char t_rank, char t_suit, bool t_face);

  // Accessors
  char getRank() const;
  char getSuit() const;
  bool getFace() const;

  // Mutators
  void setRank(const char t_rank);
  void setSuit(const char t_suit);
  void setFace(const bool t_face);


};

// static char* SUIT = {'c', 'd', 'h', 's'};
// static char* RANKS = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

#endif
