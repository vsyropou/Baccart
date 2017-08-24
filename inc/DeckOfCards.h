
#include <vector>
#include <string>

class DeckOfCards{

 public: // Interace //
  //constructors
  inline DeckOfCards() {}
  DeckOfCards(unsigned int numDecks = 1, unsigned int cardsPerDeck = 52);

  //methods
  std::vector<std::string>* getDeck(); // return pointer to the current deck
  std::tuple<unsigned int,unsigned int> getDeckStats(); 
  //TODO:  draw from the deck and return card
   
  //destructor
  ~DeckOfCards();

protected:

  //methods
  void initialize();
  void newDeck();

  //members
  unsigned int _numDecks;
  unsigned int _cardsPerDeck;

  std::vector<std::string>* _cards_ptr;
  std::vector<std::string> _cards{std::vector<std::string>(_numDecks * _cardsPerDeck)};

};
