#include "../inc/BaccartGameEngine.h"
#include <iostream>
#include <utility>

// Interface //

//constructors
BaccartGameEngine::BaccartGameEngine( DeckOfCards cards ): _cards(cards){ 
  initialize(); }

BaccartGameEngine::~BaccartGameEngine(){}

//methods

void BaccartGameEngine::initialize(){

  // set card values
  // Not the most elgant way ...
  _cardValues['10'] = 0; _cardValues['J'] = 0;
  _cardValues['Q'] = 0;  _cardValues['K'] = 0;

  _cardValues['A'] = 1;
  _cardValues['2'] = 2; _cardValues['6'] = 6;
  _cardValues['3'] = 3; _cardValues['7'] = 7;
  _cardValues['4'] = 4; _cardValues['8'] = 8;
  _cardValues['5'] = 5; _cardValues['9'] = 9;

}

void BaccartGameEngine::playBaccart(){

  std::cout<<"Beginplayin Baccrat"<<std::endl;

  // start by dealing two cards each 
  std::string pcard1 = _cards.drawCard();
  std::string pcard2 = _cards.drawCard();

  std::string bcard1 = _cards.drawCard();
  std::string bcard2 = _cards.drawCard();

  // dump status // TODO:: Make this into a function that dumps hands and sums
  std::cout<<"\n\n Player hand: "<<pcard1<<" "<<pcard2<<" "<<std::endl;
  std::cout<<"Banker hand: "<<bcard1<<" "<<bcard2<<" "<<std::endl;
  std::cout<<" /n "<<std::endl;
  
  char p1c1 = pcard1.front();
  char p1c2 = pcard2.front();

  char p2c1 = bcard1.front();
  char p2c2 = bcard2.front();

  _player.emplace_back(p1c1);
  _player.emplace_back(p1c2);

  _banker.emplace_back(p2c1);
  _banker.emplace_back(p2c2);


  std::string winner = compareHands(_player,_banker);// ATTENTION: Order of arguments matter!!
  std::cout<<"Internal test:"<<std::endl;
  std::cout<<"\nPlayer hand sum: "<<evaluateHand(_player)<<std::endl;
  std::cout<<   " Banker hand sum: "<<evaluateHand(_banker)<<std::endl;

  std::cout<<"Winner is: "<<winner<<std::endl;
  // std::cout<<"GameOver : "<<isGameOver()<<std::endl; 

  std::cout<<"End internal test:"<<std::endl;

  applyRules();
    

  std::cout<<"Game is over!! Do you want to play more? Just rerun the executable :-P"<<std::endl;

}

void BaccartGameEngine::dumpCardValues(){
  std::cout<<"\n Card Values are:"<<std::endl;
  for ( auto it = _cardValues.begin(); it != _cardValues.end(); it++ )
    {
      std::cout << it->first  << ':'
		<< it->second <<std::endl ;
    }
} 

unsigned int BaccartGameEngine::evaluateCard(char card){

  return _cardValues[card];

}

int BaccartGameEngine::evaluateHand(std::vector<char> hand){

  // std::cout<<" checking summing function"<<std::endl;
  // std::cout<<hand[0]<<" "<<hand[1]<<std::endl;

  int sum = 0;
  for (unsigned int i = 0; i < hand.size(); ++i){

    int handValue = evaluateCard(hand[i]); 
    
    // std::cout<<"Inside for sum:"<<sum<<" value:"<<handValue<<std::endl;
    
    if ( (sum + handValue) >= 10){
      sum += (handValue - 10 + 1);
      // std::cout<<"Inside if:"<<sum<<" arg:"<<(sum + handValue - 10 + 1)<<std::endl;
    }
    else{
      sum += handValue;
      // std::cout<<"Inside else:"<<sum<<" arg:"<<(sum + handValue - 10 + 1)<<std::endl;
    }
  }

  // std::cout<<"Outside for sum:"<<sum<<std::endl; 
  return sum;

}


std::string BaccartGameEngine::compareHands(std::vector<char> player, std::vector<char> banker){

  int playerSum = evaluateHand(player);
  int bankerSum = evaluateHand(banker);

  std::string winner = (playerSum>bankerSum) ? "PLAYER" : "BANKER"; 

  return winner;

}

void BaccartGameEngine::showPlayerHand(){

  for (unsigned int i = 0; i < _player.size(); ++i)
    std::cout << _player[i] << ' ';

}

void BaccartGameEngine::showBankerHand(){

  for (unsigned int i = 0; i < _banker.size(); ++i)
    std::cout << _banker[i] << ' ';

}

void BaccartGameEngine::applyRules(){
  
  auto playerDrawDecission = [this](std::vector<char> hand){ return evaluateHand(hand) <= 5;};

  // Dessice who and draws a third card
  bool playerDraws = playerDrawDecission(_player);
  if ( playerDraws ){

    char playerCard = _cards.drawCard().front();
    
    _player.emplace_back( playerCard);

    // Now apply the more complicated rules for the banker
    std::pair<int,unsigned int> action;
    action.first = evaluateCard(playerCard);
    action.second = evaluateHand(_banker);
    
    bool bankerDraws = advancedBankerDessicion(action);

    std::cout<<"/n Card:"<<playerCard<<std::endl;
    std::cout<<"evalCard:"<<evaluateCard(playerCard)<<std::endl;
    std::cout<<"evalHand:"<<evaluateHand(_banker)<<std::endl;
    std::cout<<"evalCard test:"<<action.first<<std::endl;
    std::cout<<"evalHand test:"<<action.second<<std::endl;
    std::cout<<"test laction:"<<bankerDraws<<std::endl;

  }
  else {
    if ( playerDrawDecission(_banker) ){
      _banker.emplace_back( _cards.drawCard().front());
    }
  }


  std::cout<<"Draw dession"<<" "<<playerDraws<<std::endl;


}


bool BaccartGameEngine::advancedBankerDessicion(std::pair<int,unsigned int> action){

  auto case1 = [action](){return (action.first>=2 and action.first<=3 and action.second<=4) ;};
  auto case2 = [action](){return (action.first>=4 and action.first<=5 and action.second<=5) ;};
  auto case3 = [action](){return (action.first>=6 and action.first<=7 and action.second<=6) ;};
  auto case4 = [action](){return (action.first==8 and action.second<=2) ;};
  auto case5 = [action](){return ((action.first==9 or action.first==0) and action.second<=3) ;};

  return case1() or case2() or case3() or case4() or case5();

}



// bool BaccartGameEngine::isGameOver(){

//   bool gameover = (evaluateHand(_player) == 9) or (evaluateHand(_banker) == 9);

//   return gameover;

// }
