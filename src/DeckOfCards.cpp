
#include "../inc/DeckOfCards.h"
#include <iostream>
#include <tuple>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::tuple;

// Interface //

//constructors
DeckOfCards::DeckOfCards(unsigned int numDecks, unsigned int cardsPerDeck):
  _numDecks(numDecks),
  _cardsPerDeck(cardsPerDeck){

  initialize();
}

DeckOfCards::~DeckOfCards(){_cards.clear();}

//methods
vector<string>* DeckOfCards::getDeck(){ return _cards_ptr; }

tuple<unsigned int,unsigned int> DeckOfCards::getDeckStats(){
  return std::make_tuple(_numDecks,_cardsPerDeck);
}


//Protected

void DeckOfCards::initialize(){

  for ( unsigned int i = 0; i < _numDecks * _cardsPerDeck ; i += 1){
    _cards[i] = "foo";
   }

  _cards_ptr = &_cards ;

}

void DeckOfCards::newDeck(){_cards.clear();}


