
#include <iostream>
#include <vector>
#include <array>

using namespace std;

#ifndef DECKOFCARDS
#define DECKOFCARDS

class DeckOfCards{

 public: // Interace //

  //constructors
  DeckOfCards() {} // Default constructor
  DeckOfCards(unsigned int numDecks = 1, unsigned int cardsPerDeck = 52);

  //methods
  vector<string>* getDeck(); // return pointer to the current deck
  tuple<unsigned int,unsigned int> getDeckStats();
  string drawCard();
  string getSpecificCard();
  
  inline void dumpCardNames() { for( auto it = _cardNames.begin(); it != _cardNames.end(); it++){ cout<<" "<<*it;}  };
  inline void dumpCardColors() { for( auto it = _cardColors.begin(); it != _cardColors.end(); it++){ cout<<" "<<*it;}  };
  

  //destructor
  ~DeckOfCards();

protected:

  //methods
  void initialize();
  void makeDeck();
  void newDeck();

  //members
  unsigned int _numDecks;
  unsigned int _cardsPerDeck;
  array<string,4>  _cardColors {{"spd","dim","hrt","clb"}};
  array<string,13> _cardNames  {{"A","2","3","4","5","6","7","8","9","0","J","Q","K"}};

  vector<string>* _cards_ptr;
  vector<string>  _cards;

};

#endif
