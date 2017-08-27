// Author: Vasilis Syropoulos (vsyropou5@gmail.com)
// Coding Exercise for the Math Analyst vacancy


// local
#include "inc/DeckOfCards.h"
#include "inc/BaccartGameEngine.h"

using namespace std;

int main()
{

  // Configuration
  // TODO:: Make these into comand line arguments.
  unsigned int nDecks = 1;
  bool developerMode = true; // if true here you get more info throught the game.
  bool testRulesMode = false; // if true you get to choose cards that card drawn 
                              // useful for cheking the rules of the game

  //Initialize game
  cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

  DeckOfCards deckofcards(nDecks);

  BaccartGameEngine gameEngine(deckofcards,developerMode,testRulesMode);

  //Start Game
  cout<<"\n-------------------------------"
      <<"\n----- Awesome Baccrat Game ----"
      <<"\n-------------------------------\n"<<std::endl;

  cout<<"\n Press enter to start game.\n>>>";
  string line;
  getline( cin, line );
  unsigned int cnt = 1;

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
