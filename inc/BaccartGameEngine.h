
#include <map>

#include "DeckOfCards.h"

using namespace std;

class BaccartGameEngine{

 public: // Interace //
  
  //constructors
  BaccartGameEngine( DeckOfCards cards, 
		     bool developerMode = false, 
		     bool testRulesMode = false );

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
  map<char,int> _cardValues;
  bool _developerMode;
  bool _testRulesMode;
  bool _isGameOver = false;

  vector<char> _player;
  vector<char> _banker;
  
  //methods
  unsigned int evaluateCard(char card);
  int evaluateHand(vector<char>);
  void applyRules();
  bool advancedBankerDessicion(pair<int, unsigned int>);
  void prepNewGame();

};
