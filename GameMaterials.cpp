#include "GameMaterials.h"


// Card ////////////////////////////
Card::Card(int in_rank, char in_suit)  // a card cnostructor that takes the rank and the suits
{
	rank = in_rank; 
	suit = in_suit;
}

int Card::getRank()
{
	// returning and getting the rank and will use it in the basePerson class in the GetHandScore() method
	return rank;  
}

char Card::getSuit()
{
	return suit; // returning and getting the suit
}


// Deck ////////////////////////////
Deck::Deck(int quantity)// a deck constructor with passing the quantinty or the number of decks that we want to create  
{
	if (quantity > 0)
	{
		for (int i = 0; i < quantity; i++)
		{
			addDeck(); // we add a deck
		}
	}

	random_shuffle(CardDeck.begin(), CardDeck.end()); // then we shuffle them, so now we have shuffled deck ready to use
}

Card Deck::dealCard()
{
	Card c = CardDeck.back(); // we get a card from the vector of cards in a deck
	CardDeck.pop_back(); // after we get it, we remove it from the deck to make sure not using it again 
	return c; // we return the card
}

int Deck::DeckSize()
{
	return CardDeck.size(); // get how many cards left in a deck
}

void Deck::addDeck()
{
	// add normal card of each suit
	for (int i = 2; i < 11; i++) // adding the normal card that is 2,3,4,5,6,7,8,9,10
	{
		CardDeck.push_back(Card(i, Hearts));
		CardDeck.push_back(Card(i, Diamonds));
		CardDeck.push_back(Card(i, Clubs));
		CardDeck.push_back(Card(i, Spades));
	}

	// add jack, queen, kind card of each suit
	for (int i = 0; i < 3; i++)
	{
		CardDeck.push_back(Card(10, Hearts));
		CardDeck.push_back(Card(10, Diamonds));
		CardDeck.push_back(Card(10, Clubs));
		CardDeck.push_back(Card(10, Spades));
	}

	// add the ace of each suit
	CardDeck.push_back(Card(1, Hearts));
	CardDeck.push_back(Card(1, Diamonds));
	CardDeck.push_back(Card(1, Clubs));
	CardDeck.push_back(Card(1, Spades));
}