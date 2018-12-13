#ifndef Card_hpp
#define Card_hpp

class Card {
private:
  char m_rank;
  char m_suit;
  bool m_face_up;

public:
  // static arrays, will be initialized only once in corresponding cpp file
  const static char SUITS[4];
  const static char RANKS[13];
  
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


#endif
