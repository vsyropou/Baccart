
// from std
#include <iostream>
#include <string.h>

// local
#include "inc/DeckOfCards.h"
#include "inc/BaccartGameEngine.h"

using namespace std;

int main()
{

  // Configuration 
  unsigned int nDecks = 2;
  bool developerMode = true;

  //Initialize game
  cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

  DeckOfCards deckofcards(nDecks);

  BaccartGameEngine gameEngine(deckofcards,developerMode);

  tuple<unsigned int,unsigned int> dstats = deckofcards.getDeckStats();
  cout<<"\n Game initialization sucessfull: ("<<get<0>(dstats)<<" decks and "<<get<1>(dstats)<< " cards per deck)\n"<<endl;
 
    if ( developerMode ) {
        cout<<"\n These are the card values"<<endl;
	gameEngine.dumpCardValues();}

  //Start Game
  cout<<"\n Press enter to start game.\n"<<endl;
  std::string line;
  std::getline( std::cin, line );
  unsigned int cnt = 1;
  while( line.empty() ){

    gameEngine.playBaccart();

    cout<<"\n --- Game number "<<cnt<<" ---"<<endl;
    cout<<"\n Player Hand: ";
    gameEngine.showPlayerHand();
    cout<<"  sum = "<<gameEngine.getPlayerSum();

    cout<<"\n Banker Hand: ";
    gameEngine.showBankerHand();
    cout<<"  sum = "<<gameEngine.getBankerSum()<<endl;
    gameEngine.declareWinner();

    std::cout<<"\n Game is over!! "
	     <<"Do you want to play more? "
	     <<"Just press enter. "
	     <<"Or type anything else to exit"<<std::endl;
    std::getline( std::cin, line );

    cnt +=1;
  
  }

// Game over


  return 0;

}


// TODO::
// Test rules and game
// Fix issue with 10 as char in the charcter values
//       //  auto show = [](char crd){ if (crd=='0'){ return "10";} else {return static_cast<std::string>(crd);} }
// write make file 
// Check again the card values (or point out to gli that these are the valeus I used )


// test clear deck
// use const in some places that makes sence.
// Check better if it is indeed random over time, do histograms etc...
