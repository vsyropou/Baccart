

#include "../inc/BaccartGameEngine.h"

using namespace std;

//constructors
BaccartGameEngine::BaccartGameEngine( DeckOfCards cards, bool developerMode, bool testRulesMode ): 
  _cards(cards),
  _developerMode(developerMode),
  _testRulesMode(testRulesMode){ 

  initialize(); 

}

BaccartGameEngine::~BaccartGameEngine(){}

//methods
void BaccartGameEngine::initialize(){

  // set card values
  //  Not the most elgant way ...
  _cardValues['0'] = 0; _cardValues['J'] = 0; _cardValues['Q'] = 0;
  _cardValues['K'] = 0;

  _cardValues['A'] = 1; _cardValues['2'] = 2; _cardValues['6'] = 6;
  _cardValues['3'] = 3; _cardValues['7'] = 7; _cardValues['4'] = 4; 
  _cardValues['8'] = 8; _cardValues['5'] = 5; _cardValues['9'] = 9;

  // set card names (as we want them to apper for the user)
  // TODO:: This can be avoided if the _carValues keys where 
  //        strings instead of char.
  _cardNames['0'] = "10"; _cardNames['J'] = "J"; _cardNames['Q'] = "Q";  
  _cardNames['K'] = "K";

  _cardNames['A'] = "A"; _cardNames['2'] = "2"; _cardNames['6'] = "6";
  _cardNames['3'] = "3"; _cardNames['7'] = "7"; _cardNames['4'] = "4"; 
  _cardNames['8'] = "8"; _cardNames['5'] = "5"; _cardNames['9'] = "9";

  tuple<unsigned int,unsigned int> dstats = this->_cards.getDeckStats();
  cout<<"\n Game initialization sucessfull: ("
	   <<get<0>(dstats)<<" decks and "<<get<1>(dstats)
	   << " cards per deck)\n"<<endl;

}

void BaccartGameEngine::playBaccart(){
  
  if ( _isGameOver ){ 
    prepNewGame();
    _isGameOver = false;
  }

  // start by dealing two cards each 
  string pcard1 = _cards.drawCard();
  string bcard1 = _cards.drawCard();

  string pcard2;
  string bcard2;

  if ( _testRulesMode ){
    cout<<"First player card is "<<pcard1<<" Choose the second one:"<<endl;
    pcard2 = _cards.getSpecificCard();
    cout<<"First banker card is "<<bcard1<<" Choose the second one:"<<endl;
    bcard2 = _cards.getSpecificCard();
  }

  char p1c1 = pcard1.front();
  char p1c2 = pcard2.front();

  char p2c1 = bcard1.front();
  char p2c2 = bcard2.front();

  _player.emplace_back(p1c1);
  _player.emplace_back(p1c2);

  _banker.emplace_back(p2c1);
  _banker.emplace_back(p2c2);

  if ( _developerMode ){// dump natural hands
    cout<<"\n --Developer mode info--"
	     <<"\nPlayer natural hand: "<<pcard1<<" "<<pcard2
	     <<"\nBanker natural hand: "<<bcard1<<" "<<bcard2
	     <<"\nPlayer hand sum: "<<getPlayerSum()
	     <<"\nBanker hand sum: "<<getBankerSum()
	     <<"\n --End developer mode info--"<<endl;
  }

  // continue for a third card or stop ?
  auto stands = [this](vector<char> hnd){return (evaluateHand(hnd)==8 or evaluateHand(hnd)==9);};

  if ( not (stands(_player) and stands(_banker)) ){
	applyRules();
      
       }
  
_isGameOver = true;

}
            
unsigned int BaccartGameEngine::evaluateCard(char card){

  return _cardValues[card];

}

int BaccartGameEngine::evaluateHand(vector<char> hand){

  int sum = 0;
  for (unsigned int i = 0; i < hand.size(); ++i){

    int handValue = evaluateCard(hand[i]); 
    
    if ( (sum + handValue) >= 10){ sum += (handValue - 10 + 1);}
    else                         { sum += handValue;}
  }

  return sum;

}

void BaccartGameEngine::applyRules(){ // Dessice who draws a third card

  auto asPlayerDrawDecission = [this](vector<char> hand){ return evaluateHand(hand) <= 5;};

  bool playerDraws = asPlayerDrawDecission(_player);

  if ( _developerMode ){cout<<"\n --Developer mode info-- \n"
				 <<"player draws third card "<<playerDraws<<endl;}

  if ( playerDraws ){//Player draws

    char playerCard;
    if ( _testRulesMode ){ playerCard = _cards.getSpecificCard().front(); }
    else                 { playerCard = _cards.drawCard().front(); }
    
    _player.emplace_back( playerCard);

    // Now apply the more complicated rules for the banker
    pair<int,unsigned int> action;
    action.first = evaluateCard(playerCard);
    action.second = evaluateHand(_banker);
    
    bool bankerDraws = advancedBankerDessicion(action);
    if ( _developerMode ){cout<<"banker draws according to advanced rules"<<" "<<bankerDraws<<endl;}
    if ( bankerDraws ){ 
      _banker.emplace_back(_cards.drawCard().front());}

  }
  else {// Player stands
    if ( asPlayerDrawDecission(_banker) ){
      if ( _developerMode ){cout<<"banker draws as player 1"<<endl;}
      _banker.emplace_back( _cards.drawCard().front());
    }
  }

  if ( _developerMode ){
    cout<<"\nPlayer hand sum: "<<evaluateHand(_player)
	     <<"\nBanker hand sum: "<<evaluateHand(_banker)
	     <<"\n--End developer mode info--"<<endl;
  }
}

bool BaccartGameEngine::advancedBankerDessicion(pair<int,unsigned int> action){

  auto case1 = [action](){return (action.first>=2 and action.first<=3 and action.second<=4) ;};
  auto case2 = [action](){return (action.first>=4 and action.first<=5 and action.second<=5) ;};
  auto case3 = [action](){return (action.first>=6 and action.first<=7 and action.second<=6) ;};
  auto case4 = [action](){return (action.first==8 and action.second<=2) ;};
  auto case5 = [action](){return ((action.first==9 or action.first==0 or action.first==1) and action.second<=3) ;};

  return case1() or case2() or case3() or case4() or case5();

}

void BaccartGameEngine::prepNewGame(){
  _player.clear(); 
  _banker.clear();
}

void BaccartGameEngine::dumpCardValues(){
  cout<<"\n Card Values are (Carefull 10 is maped to 0 internally!!):"<<endl;
  for ( auto it = _cardValues.begin(); it != _cardValues.end(); it++ )
    {
      cout<<"  "<<it->first << ':' <<it->second<<" ,";
    }
  cout<<" "<<endl;
} 

void BaccartGameEngine::showHand(vector<char> hand){
  for (auto it = hand.begin(); it != hand.end(); it++) 
    cout<<_cardNames[*it]<<' ';
}

void BaccartGameEngine::showPlayerHand(){ showHand(_player); }

void BaccartGameEngine::showBankerHand(){ showHand(_banker); }

int BaccartGameEngine::getPlayerSum(){ return evaluateHand(_player); }

int BaccartGameEngine::getBankerSum(){ return evaluateHand(_banker); }

void BaccartGameEngine::declareWinner(){

  if ( _isGameOver ){
    if ( evaluateHand(_player) == evaluateHand(_banker) ) 
      { cout<<"TIE"<<endl;}
    else{
      string wnr = (evaluateHand(_player)>evaluateHand(_banker)) ? "PLAYER" : "BANKER";
      cout<<"Winner is "<<wnr<<endl; }
  }
  else {cout<<"Cannot declare winner, game is not over yet."<<endl; }

}
