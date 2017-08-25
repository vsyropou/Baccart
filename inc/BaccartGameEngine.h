#include <vector>
#include <string>
#include <map>

#include "DeckOfCards.h"

class BaccartGameEngine{

 public: // Interace //
  
  //constructors
  BaccartGameEngine( DeckOfCards cards );
  
  // members

  //methods
  void initialize();
  void playBaccart();
  void dumpCardValues();
  void showPlayerHand();
  void showBankerHand();

  //destructor
  ~BaccartGameEngine();

protected:

  // members
  DeckOfCards _cards;
  std::map<char,int> _cardValues;

  std::vector<char> _player;
  std::vector<char> _banker;
  
  //methods
  unsigned int evaluateCard(char card);
  std::string compareHands(std::vector<char>, std::vector<char>);
  int evaluateHand(std::vector<char>);
  bool isGameOver();
  void applyRules();

};
