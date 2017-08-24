
#include "../inc/DeckOfCards.h"
#include <iostream>
#include <tuple>
#include <stdlib.h>
#include <time.h> 

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

string DeckOfCards::drawCard(){
  // Draw a random card from the deck. 
  // Maybe not as it is done in a physical deck.
  // But the pseudo randomenss effect is the same.

  if ( _cards_ptr->empty() ){ 
    cout<<"Deck is finished. Have a drink while waiting for new deck...."<<endl;
    newDeck(); }

  unsigned int idraw = rand() % _cards_ptr->size() + 0; // random number

  string rcrd = (*_cards_ptr)[idraw]; // get element

  _cards_ptr->erase(_cards_ptr->begin() + idraw); // and remove it from deck

  // Note: Do not use vectors for this again pop_back does not return the poped value;

  return rcrd;

}

//Protected

void DeckOfCards::initialize(){ makeDeck(); }

void DeckOfCards::makeDeck(){
  srand (time(NULL)); // TODO: Check better if it is indeed random over time
  for ( unsigned int cIdx = 0; cIdx < _cardColors.size(); cIdx += 1){ 
    for ( unsigned int nIdx = 0; nIdx < _cardNames.size(); nIdx += 1){
       _cards.push_back( _cardNames[nIdx] + _cardColors[cIdx] );
    }
  }

  _cards_ptr = &_cards ;
}

void DeckOfCards::newDeck(){
  _cards.clear();
  makeDeck();
}


