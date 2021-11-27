#ifndef GAME_MATERIALS_H
#define GAME_MATERIALS_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using std::vector;
using std::cout;
using std::endl;
using std::string;


// suits ///////////////////
enum SuitType
{
	Hearts = 3, Diamonds = 4, Clubs = 5, Spades = 6
};


// card ///////////////////
class Card
{
private:
	int rank;
	char suit;

public:
	Card(int in_rank, char in_suit);
	int getRank();
	char getSuit();
};


// deck ///////////////////
class Deck
{
private:
	vector<Card> CardDeck;
	void addDeck();

public:
	Deck(int quantity);
	Card dealCard();
	int DeckSize();
	void DeckShuffle();
};


#endif /* GAME_MATERIALS_H */
