// Author: Vasilis Syropoulos (vsyropou5@gmail.com)
// Coding Exercise for the Math Analyst vacancy


// local
#include "inc/DeckOfCards.h"
#include "inc/BaccartGameEngine.h"

using namespace std;

int main(int argc, char *argv[])
{

  // Parse cmd args and configure
  unsigned int nDecks = 1;
  bool testRulesMode = false; // choose cards that are drawn useful when cheking the rules
  bool developerMode = ( argc>1 and argv[1]!=NULL ) ? static_cast<string>(argv[1])=="-d" : false; //  more info throught the game.

  //Initialize game
  cout<<"\n Initalizing Game (Get excited)!! \n"<<endl;

  DeckOfCards deckofcards(nDecks);

  BaccartGameEngine gameEngine(deckofcards,developerMode,testRulesMode);

  //Begin Game
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
  // Game over
  
  }
  return 0;
}


// TODO::
// use const in some declarations that makes sence.
// Check better if it is rng engine is indeed random over time, do histograms etc...
