
// from std
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// local
#include "inc/DeckOfCards.h"
#include "inc/BaccartGameEngine.h"

int main()
{

  // Configuration 

  unsigned int nDecks = 2;
// unsigned int nCards = 52;

//include stuff
using std::cout; using std::endl;
 using std::vector; using std::string;
using std::tuple; using std::get;

//Initialize game
 cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

 DeckOfCards deckofcards(nDecks);

 BaccartGameEngine gameEngine(deckofcards);
 
//Start Game
 tuple<unsigned int,unsigned int> dstats = deckofcards.getDeckStats();
 cout<<"\n Game initialization sucessfull: ("<<get<0>(dstats)<<" decks and "<<get<1>(dstats)<< " cards per deck)\n"<<endl;

 gameEngine.dumpCardValues();

 std::string result = gameEngine.playBaccart();

 cout<<"\n Player Hand: ";
 gameEngine.showPlayerHand();

 cout<<"\n Banker Hand: ";
 gameEngine.showBankerHand();

 cout<<" \n"<<endl;

// Game over



// Checks //
// dump deck

//  vector<string>* deck = deckofcards.getDeck();

// for (auto it = deck->begin(); it != deck->end(); ++it) {
// int index  = std::distance(deck->begin(), it);
// string val = (*deck)[index];

//  cout<<index<<" "<<val<<endl;
    
//   }

// // draw two cards
// cout<<"Deck size"<<deck->size()<<endl;
// cout<<"\n Now I will draw a card "<<deckofcards.drawCard()<<"\n"<<endl;
// cout<<"Deck size"<<deck->size()<<endl;
// cout<<"\n Now I will draw another card "<<deckofcards.drawCard()<<"\n"<<endl;

// cout<<"Deck size"<<deck->size()<<endl;


  return 0;

}


// TODO::
// Implement rules
// write make file 
// Check again the card values 
// test clear deck
// use const in some places that makes sence.
// Fix indendation
// TODO: Check better if it is indeed random over time
