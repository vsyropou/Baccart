
// from std
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// local
#include "inc/DeckOfCards.h"
#include "inc/BaccartGameEngine.h"

using namespace std;

int main()
{

  // Configuration 
  unsigned int nDecks = 2;


  //Initialize game
  cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

  DeckOfCards deckofcards(nDecks);

  BaccartGameEngine gameEngine(deckofcards);

  tuple<unsigned int,unsigned int> dstats = deckofcards.getDeckStats();
  cout<<"\n Game initialization sucessfull: ("<<get<0>(dstats)<<" decks and "<<get<1>(dstats)<< " cards per deck)\n"<<endl;
 
  //  gameEngine.dumpCardValues();

  //Start Game

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
