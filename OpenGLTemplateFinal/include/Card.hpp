#ifndef Card_hpp
#define Card_hpp

#include <string>

class Card {
  
protected:
  std::string m_image_file_path;
private:
  char m_rank;
  char m_suit;
  bool m_face_up;
  
  // private methods
  void setImageFilePath(char t_rank, char t_suit); // only used in constructor

public:
  // static arrays, will be initialized only once in corresponding cpp file
  const static char SUITS[4];
  const static char RANKS[13];
  
  // static file path for back of card. (all cards will use this image for back.)
  const static std::string BACK_OF_CARD_IMAGE_PATH;
  
  // Constructors
  Card();
  Card(char t_rank, char t_suit, bool t_face);

  // Accessors
  char getRank() const;
  char getSuit() const;
  bool getFace() const;
  std::string getImageFilePath() const;

  // Mutators
  void setRank(const char t_rank);
  void setSuit(const char t_suit);
  void setFace(const bool t_face);


};


#endif
