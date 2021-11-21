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


// suits /////////////////// using enum to create the character of suits by using the ASCII language
enum SuitType
{
	Hearts = 3, Diamonds = 4, Clubs = 5, Spades = 6
};


// card ///////////////////
class Card
{
private:
	int rank; // the card that holds the numbers : ace,2,3,4,5,6,7,8,9,10
	char suit; // the card that holds the character of cards : Hearts, Diamonds, Clubs, Spades

public:
	Card(int in_rank, char in_suit); // declaring the card constructor to use it later to create an object of cards
	int getRank();  // getting and returning the rank
	char getSuit();  // getting and returning the suit
};


// deck ///////////////////
class Deck
{
private:
	vector<Card> CardDeck;  // declaring a vector of card to create a deck of cards
	void addDeck(); // adding the card to the deck

public:
	Deck(int quantity); // declaring the constructor of deck to use it later to create an object of deck
	Card dealCard(); // a method to deal the cards
	int DeckSize();  // a method to get the number of the cards there
};

#endif /* GAME_MATERIALS_H */