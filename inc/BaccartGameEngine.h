#include <vector>
#include <string>
#include <map>
#include <utility>

#include "DeckOfCards.h"

class BaccartGameEngine{

 public: // Interace //
  
  //constructors
  BaccartGameEngine( DeckOfCards cards, bool developerMode );

  //methods
  void initialize();
  void playBaccart();
  void dumpCardValues();
  void showPlayerHand();
  void showBankerHand();
  int getPlayerSum();
  int getBankerSum();
  void declareWinner();

  //destructor
  ~BaccartGameEngine();

protected:

  // members
  DeckOfCards _cards;
  std::map<char,int> _cardValues;
  bool _developerMode;
  bool _isGameOver = false;

  std::vector<char> _player;
  std::vector<char> _banker;
  
  //methods
  unsigned int evaluateCard(char card);
  std::string compareHands(std::vector<char>, std::vector<char>);
  int evaluateHand(std::vector<char>);
  void applyRules();
  bool advancedBankerDessicion(std::pair<int, unsigned int>);
  void prepNewGame();

};
