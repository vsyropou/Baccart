
#include <vector>
#include <string>
#include <array>

class DeckOfCards{

 public: // Interace //
  //constructors
  inline DeckOfCards() {} // Default constructor
  DeckOfCards(unsigned int numDecks = 1, unsigned int cardsPerDeck = 52);

  //methods
  std::vector<std::string>* getDeck(); // return pointer to the current deck
  std::tuple<unsigned int,unsigned int> getDeckStats();
  std::string drawCard();
   
  //destructor
  ~DeckOfCards();

protected:

  //methods
  void initialize();
  void makeDeck();
  void newDeck();

  //members
  unsigned int _numDecks;
  unsigned int _cardsPerDeck;
std::array<std::string,4> _cardColors {{"spd","dim","hrt","clb"}};
  std::array<std::string,13>  _cardNames {{"A","2","3","4","5","6","7","8","9","10","J","Q","K"}};
  std::array<unsigned int,13> _cardVaues {{ 0,  2,  3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 0 , 0 , 0}};

// std::array<std::string,4> _cardColors {{"spd","dim","hrt","clb"}};

  std::vector<std::string>* _cards_ptr;
  std::vector<std::string> _cards;

};
