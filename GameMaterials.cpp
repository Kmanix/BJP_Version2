#include "GameMaterials.h"


// Card ////////////////////////////
Card::Card(int in_rank, char in_suit)
{
	rank = in_rank;
	suit = in_suit;
}


int Card::GetRank()
{
	return rank;
}


char Card::GetSuit()
{
	return suit;
}


// Deck ////////////////////////////
Deck::Deck(int quantity)
{
	if (quantity > 0)
	{
		for (int i = 0; i < quantity; i++)
		{
			AddOneDeck();
		}
	}

	DeckShuffle();
}


Card Deck::DealOneCard()
{
	Card c = CardDeck.back();
	CardDeck.pop_back();
	return c;
}


int Deck::DeckSize()
{
	return (int)CardDeck.size();
}


void Deck::DeckShuffle()
{
	random_shuffle(CardDeck.begin(), CardDeck.end());
}


void Deck::AddOneDeck()
{
	// add normal card of each suit
	for (int i = 2; i < 11; i++)
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
