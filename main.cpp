
#include <iostream>
#include <vector>
#include <string>
#include "inc/DeckOfCards.h"
#include <tuple>

int main()
{

// Configuration //

unsigned int nDecks = 1;
unsigned int nCards = 5;

//include stuff
using std::cout; using std::endl;
using std::vector; using std::string;
using std::tuple; using std::get;

//Initialize game
cout<<"\n Initalizing Baccart Game (Get excited)!! \n"<<endl;

DeckOfCards deckofcards(nDecks,nCards);

//Sanity checks (TODO:: Comment out)
tuple<unsigned int,unsigned int> dstats = deckofcards.getDeckStats();
unsigned int _nDecks = get<0>(dstats);
unsigned int _nCards = get<1>(dstats);
cout<<"\n Game initialization sucessfull: ("<<_nDecks<<" decks and "<<_nCards<< " cards per deck)\n"<<endl;

//Start Game
vector<string>* deck = deckofcards.getDeck();
  
for (auto it = deck->begin(); it != deck->end(); ++it) {
int index  = std::distance(deck->begin(), it);
string val = (*deck)[index];

cout<<index<<endl;
cout<<val<<endl;
    
  }



  return 0;

}


// TODO::
//  cards per deck 
// command line arguments
