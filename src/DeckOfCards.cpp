
#include <tuple>

#include "../inc/DeckOfCards.h"

using namespace std;

//constructors
DeckOfCards::DeckOfCards(unsigned int numDecks, unsigned int cardsPerDeck):
  _numDecks(numDecks),
  _cardsPerDeck(cardsPerDeck){

  initialize();

}

DeckOfCards::~DeckOfCards(){}

//methods
void DeckOfCards::initialize(){ makeDeck(); }

void DeckOfCards::makeDeck(){
  srand (time(NULL)); // Change seed every time you make a new deck

  for ( unsigned int dIdx = 0; dIdx <  _numDecks; dIdx += 1){ 
    for ( unsigned int cIdx = 0; cIdx < _cardColors.size(); cIdx += 1){ 
      for ( unsigned int nIdx = 0; nIdx < _cardNames.size(); nIdx += 1){
       _cards.push_back( _cardNames[nIdx] + _cardColors[cIdx] );
      }
    }
  }
  _cards_ptr = &_cards ;
}

void DeckOfCards::newDeck(){
  _cards.clear();
  makeDeck();
}

string DeckOfCards::drawCard(){
  // Draw a random card from the deck. 
  // Maybe not as it is done in a physical deck.
  // But the pseudo randomenss effect is the same.

  if ( _cards_ptr->empty() ){ 
    cout<<"\n INFO:: Deck is finished. Have a drink while waiting for new deck....\n"<<endl;
    newDeck(); }

  unsigned int idraw = rand() % _cards_ptr->size() + 0; // throw a random number

  string rcrd = (*_cards_ptr)[idraw]; // get card

  _cards_ptr->erase(_cards_ptr->begin() + idraw); // and remove it from deck

  // Note: Do not use vectors for this again, pop_back does not return the poped value;

  return rcrd;
}

string DeckOfCards::getSpecificCard(){
  // This is for testing the rules of the game faster.

  cout<<"\n Type a specific card to be draw from the deck (Carefull 10 is mapped to 0).\n"<<endl;
  cout<<"  Format of faces is: ";
  dumpCardNames();
  cout<<"\n  Format of colors is: ";
  dumpCardColors();
  cout<<"\n>>>";

  string line;
  getline( cin, line );

  return line;

}

vector<string>* DeckOfCards::getDeck(){ return _cards_ptr; }

tuple<unsigned int,unsigned int> DeckOfCards::getDeckStats(){
  return make_tuple(_numDecks,_cardsPerDeck);
}

