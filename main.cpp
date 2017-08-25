
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

  //  gameEngine.dumpCardValues();

  gameEngine.playBaccart();

  cout<<"\n Player Hand: ";
  gameEngine.showPlayerHand();
  cout<<"  sum = "<<gameEngine.getPlayerSum();

  cout<<"\n Banker Hand: ";
  gameEngine.showBankerHand();
  cout<<"  sum = "<<gameEngine.getBankerSum()<<endl;
  cout<<gameEngine.declareWinner()<<" WINS\n"<<endl;

  std::cout<<"/n Game is over!! Do you want to play more? Just rerun the executable :-P/n"<<std::endl;

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
// Test rules and game
// Fix issue with 10 as char in the charcter values
// write make file 
// Check again the card values (or point out to gli that these are the valeus I used )


// test clear deck
// use const in some places that makes sence.
// Check better if it is indeed random over time, do histograms etc...
