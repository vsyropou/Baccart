
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
  // TODO:: Make these into comand line arguments.
  unsigned int nDecks = 1;
  bool developerMode = true; // here you get more info throught the game.
  bool testRulesMode = false; // if true you get to choose cards that card drawn 
                              // useful for cheking the rules of the game

  //Initialize game
  cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

  DeckOfCards deckofcards(nDecks);

  BaccartGameEngine gameEngine(deckofcards,developerMode,testRulesMode);

    if ( developerMode ) {gameEngine.dumpCardValues();}

  //Start Game
    cout<<"\n Press enter to start game.\n>>>";
  std::string line;
  std::getline( std::cin, line );
  unsigned int cnt = 1;

  std::cout<<"\n-----------------------------"
	   <<"\n----- Begin Baccrat Game ----"
	   <<"\n-----------------------------\n"<<std::endl;

  while( line.empty() ){
    cout<<"\n --- Game number "<<cnt<<" ---"<<endl;

    gameEngine.playBaccart();

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

// use const in some declarations that makes sence.
// Check better if it is indeed random over time, do histograms etc...
// use namepsaces in GameEngin and remove all the std::
