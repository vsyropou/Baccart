#include <iostream>
#include <utility>

#include "../inc/BaccartGameEngine.h"

//constructors
BaccartGameEngine::BaccartGameEngine( DeckOfCards cards, bool developerMode ): 
  _cards(cards),
  _developerMode(developerMode){ 
  initialize(); }

BaccartGameEngine::~BaccartGameEngine(){}

//methods

void BaccartGameEngine::initialize(){

  // set card values
  //  Not the most elgant way ...
  _cardValues['10'] = 0; _cardValues['J'] = 0;
  _cardValues['Q'] = 0;  _cardValues['K'] = 0;

  _cardValues['A'] = 1;
  _cardValues['2'] = 2; _cardValues['6'] = 6;
  _cardValues['3'] = 3; _cardValues['7'] = 7;
  _cardValues['4'] = 4; _cardValues['8'] = 8;
  _cardValues['5'] = 5; _cardValues['9'] = 9;

}

void BaccartGameEngine::playBaccart(){

  std::cout<<"\n-----------------------------"<<std::endl;
  std::cout<<"----- Begin Baccrat Game ----"<<std::endl;
  std::cout<<"-----------------------------\n"<<std::endl;

  // start by dealing two cards each 
  std::string pcard1 = _cards.drawCard();
  std::string pcard2 = _cards.drawCard();

  std::string bcard1 = _cards.drawCard();
  std::string bcard2 = _cards.drawCard();

  char p1c1 = pcard1.front();
  char p1c2 = pcard2.front();

  char p2c1 = bcard1.front();
  char p2c2 = bcard2.front();

  _player.emplace_back(p1c1);
  _player.emplace_back(p1c2);

  _banker.emplace_back(p2c1);
  _banker.emplace_back(p2c2);

  if ( _developerMode ){// dump natural hands
    std::cout<<"\n --Developer mode info--"<<std::endl;
    std::cout<<"Player natural hand: "<<pcard1<<" "<<pcard2<<" "<<std::endl;
    std::cout<<"Banker natural hand: "<<bcard1<<" "<<bcard2<<" "<<std::endl;
    std::cout<<"Player hand sum: "<<getPlayerSum()<<std::endl;
    std::cout<<"Banker hand sum: "<<getBankerSum()<<std::endl;
  }

  // draw a third card ?
  applyRules();

  if ( _developerMode ){  std::cout<<"\n --End developer mode info--"<<std::endl;}
  
  _isGameOver = true;

}


unsigned int BaccartGameEngine::evaluateCard(char card){

  return _cardValues[card];

}

int BaccartGameEngine::evaluateHand(std::vector<char> hand){

  int sum = 0;
  for (unsigned int i = 0; i < hand.size(); ++i){

    int handValue = evaluateCard(hand[i]); 
    
    if ( (sum + handValue) >= 10){
      sum += (handValue - 10 + 1);
    }
    else{
      sum += handValue;

    }
  }

  return sum;

}

std::string BaccartGameEngine::compareHands(std::vector<char> player, std::vector<char> banker){

  return (evaluateHand(_player)>evaluateHand(_banker)) ? "PLAYER" : "BANKER"; 
}

void BaccartGameEngine::applyRules(){
  
  auto playerDrawDecission = [this](std::vector<char> hand){ return evaluateHand(hand) <= 5;};

  // Dessice who and draws a third card
  bool playerDraws = playerDrawDecission(_player);
  std::cout<<"player draws third card"<<" "<<playerDraws<<std::endl;
  if ( playerDraws ){

    char playerCard = _cards.drawCard().front();
    
    _player.emplace_back( playerCard);

    // Now apply the more complicated rules for the banker
    std::pair<int,unsigned int> action;
    action.first = evaluateCard(playerCard);
    action.second = evaluateHand(_banker);
    
    bool bankerDraws = advancedBankerDessicion(action);
    std::cout<<"banker draws third card"<<" "<<bankerDraws<<std::endl;
    if ( bankerDraws ){ _player.emplace_back(_cards.drawCard().front());}

    // std::cout<<"/n Card:"<<playerCard<<std::endl;
    // std::cout<<"evalCard:"<<evaluateCard(playerCard)<<std::endl;
    // std::cout<<"evalHand:"<<evaluateHand(_banker)<<std::endl;
    // std::cout<<"evalCard test:"<<action.first<<std::endl;
    // std::cout<<"evalHand test:"<<action.second<<std::endl;
    // std::cout<<"test laction:"<<bankerDraws<<std::endl;

  }
  else {
    if ( playerDrawDecission(_banker) ){
      _banker.emplace_back( _cards.drawCard().front());
    }
  }

  std::cout<<"\nPlayer hand sum: "<<evaluateHand(_player)<<std::endl;
  std::cout<<  "Banker hand sum: "<<evaluateHand(_banker)<<std::endl;

  std::cout<<"player draws third card"<<" "<<playerDraws<<std::endl;
  std::cout<<   "End third card hand test: "<<std::endl;

}


bool BaccartGameEngine::advancedBankerDessicion(std::pair<int,unsigned int> action){

  auto case1 = [action](){return (action.first>=2 and action.first<=3 and action.second<=4) ;};
  auto case2 = [action](){return (action.first>=4 and action.first<=5 and action.second<=5) ;};
  auto case3 = [action](){return (action.first>=6 and action.first<=7 and action.second<=6) ;};
  auto case4 = [action](){return (action.first==8 and action.second<=2) ;};
  auto case5 = [action](){return ((action.first==9 or action.first==0) and action.second<=3) ;};

  return case1() or case2() or case3() or case4() or case5();

}

void BaccartGameEngine::dumpCardValues(){
  std::cout<<"\n Card Values are:"<<std::endl;
  for ( auto it = _cardValues.begin(); it != _cardValues.end(); it++ )
    {
      std::cout << it->first  << ':'
		<< it->second <<std::endl ;
    }
} 

void BaccartGameEngine::showPlayerHand(){

  for (unsigned int i = 0; i < _player.size(); ++i)
    std::cout << _player[i] << ' ';

}

void BaccartGameEngine::showBankerHand(){

  for (unsigned int i = 0; i < _banker.size(); ++i)
    std::cout << _banker[i] << ' ';

}

int BaccartGameEngine::getPlayerSum(){ return evaluateHand(_player); }

int BaccartGameEngine::getBankerSum(){ return evaluateHand(_banker); }

void BaccartGameEngine::declareWinner(){

  if ( _isGameOver ){
    if ( evaluateHand(_player) == evaluateHand(_banker) ) 
      { std::cout<<"TIE"<<std::endl;}
    else{
      std::string wnr = (evaluateHand(_player)>evaluateHand(_banker)) ? "PLAYER" : "BANKER";
      std::cout<<"Winner is "<<wnr<<std::endl; }
  }
  else {std::cout<<"Cannot declare winner, game is not over yet."<<std::endl; }

}
