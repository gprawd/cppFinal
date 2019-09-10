#pragma once
/*
File:	CardGameClasses.h
Name:	Greg Prawdzik
Date:	10/1/2018
Descr:	File for classes in CardGame
*/

#pragma once
#include <string>
#include<iostream>
#include <ctime>


#ifndef CARDGAMECLASSES_H
#define CARDGAMECLASSES_H
// enumerated list of different ranks
enum Rank {
	ace = 1, two = 2, three = 3, four = 4, five = 5, six = 6,
	seven = 7, eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13
};

// enumerted list of differtn Suits
enum Suit { Spades, Hearts, Clubs, Diamonds };

// Card class
class Card
{


public:
	
	Card() { } // default constructor
	
	Card(Rank r, Suit s) { // copy constructor
		rank = r;
		suit = s;
	}

	Card(int r, int s) { // constructor for pair of ints
		rank = rankSwitch(r); // run switches to change to enum,  probably should have tried to staatic_cast<>
		suit = suitSwitch(s);
	}

	Suit suitSwitch(int s) { // switch for int to suit
		switch (s)
		{
		case 0:	suit = Spades;
			break;
		case 1: suit = Hearts;
			break;
		case 2:	suit = Clubs;
			break;
		case 3: suit = Diamonds;
		}
		return suit;
	}

	Rank rankSwitch(int r) { // switch for int to rank
		switch (r)
		{
		case 1:	rank = ace;
			break;
		case 2: rank = two;
			break;
		case 3:	rank = three;
			break;
		case 4: rank = four;
			break;
		case 5:	rank = five;
			break;
		case 6: rank = six;
			break;
		case 7:	rank = seven;
			break;
		case 8: rank = eight;
			break;
		case 9: rank = nine;
			break;
		case 10:	rank = ten;
			break;
		case 11: rank = jack;
			break;
		case 12:	rank = queen;
			break;
		case 13: rank = king;
		}
		return rank;
	}

	size_t get_suit() { // suit getter
		return suit;
	};
	size_t get_rank() { // rank getter
		return rank;
	};

	void operator =(const Card& source) { // overloaded assingment operator
		
		if (this == &source) {  // check for self assignment
			return;
		}
		rank = source.rank; // assign rank from given source
		suit = source.suit; // assign suit from given source
	}
	
	friend std::ostream& operator <<(std::ostream& outs, Card& source) { //	friend function overloaded <<
		int s = source.get_suit();										 // operator  to display a Card class
		int r = source.get_rank();										 // desctiptively
		std::string st;				// create function varaibles
		std::string rk;
		switch (s)					// switch enum to std::string
		{
		case 0:	st = "Spades";
			break;
		case 1: st = "Hearts";
			break;
		case 2:	st = "Clubs";
			break;
		case 3: st = "Diamonds";
		}

		switch (r)					// switch enum to std::string
		{
		case 1:	rk = "Ace";
			break;
		case 2: rk = "Two";
			break;
		case 3:	rk = "Three";
			break;
		case 4: rk = "Four";
			break;
		case 5:	rk = "Five";
			break;
		case 6: rk = "Six";
			break;
		case 7:	rk = "Seven";
			break;
		case 8: rk = "Eight";
			break;
		case 9: rk = "Nine";
			break;
		case 10: rk = "Ten";
			break;
		case 11: rk = "Jack";
			break;
		case 12: rk = "Queen";
			break;
		case 13: rk = "King";
		}
		outs << rk << " of " << st;
		return outs;

	}

	 int operator+(const Card& rhs) {	// overloaded + operator to return in int sum of left and right Card
			 int sum; 
			 sum = static_cast<int>(this->rank) + static_cast<int>(rhs.rank);	// convert to ints and add
			 return sum;
	};

	 friend static int operator+(int i, const Card& rhs)	// friend overloaded + operator to add a left
	 {														// int and a right Card to int sum
		 int sum;
		 sum = i + static_cast<int>(rhs.rank);
		 return sum;
	 }

	 friend int operator+(const Card& lhs, int i) {			// friend overloaded + operator to add a right
		 int sum;											// int and a left Card to int sum
		 sum = static_cast<int>(lhs.rank) + i;
		 return sum;
	 }

private:			// hidden data			
	Rank rank;		// Card Rank (ace - king)
	Suit suit;		// Card Suit(Spade, Heart, Club, Diamond)
};



struct hand			// hand structure to link Card in Deck
{
	Card data;
	hand *next;
};



class Deck{	// Deck class

public:

	Deck(){										// default constructor
		int r;									// declare function variable 
		int s;
		int num = 0;
		for (r = 1; r <= 13; r++){				// iterate r 1 through 13
			for (s = 0; s <= 3; s++){			// iterate s 0 through 3
			cards[num] = Card(r,s);				// create a new Card for given cards[]
			num++;								// incrament num to move array location
			}
		}
		/*for (int i = 0; i < 52; i++)			// test to confirm full deck created
			std::cout << cards[i] << std::endl;*/
	};
	
	
	void Shuffle() {							// shuffle function
		srand((unsigned)time(0));				// random number generator based off of system time <ctime>
		int random_integer;						// declare function variable
		
		for (int index = 0; index < 52; index++) {	// loop through cards[] from 0 - 51
			random_integer = (rand() % 52);		// create random int from 0 - 51
			int k = random_integer;				// assign random int to k
			Card temp = cards[k];				// 
			cards[k] = cards[index];			// switch cards[index] with cards[k]
			cards[index] = temp;				// 
		}
	/*	for (int i = 0; i < 52; i++)			// test to confirm full deck shuffled
			std::cout << cards[i] << std::endl;*/
	}
	Card getCard(int num) {		// returns specified Card& in array
		Card c;					// creates new Card
		c = cards[num];			// copies Card in current location to the new Card c
		return c;				// returns specified card
	};

private:						// hide data

	Card cards[52] ;			// array that holds 52 Card
	int  index;					// int index of array
};




class Player {		// Player class
public:

Player()			// default constructor
	{
		head = NULL;
		tail = NULL;
		std::string name = "player";
	}

void display()		// displays list of players cards
{
	hand *temp = new hand;	// declare function variables
	temp = head;
	while (temp != NULL)	// while ther is something in temp
	{
		Card card = temp->data;		// assign temp data to card
		std::cout << temp->data << std::endl;		// display Card in temp
		temp = temp->next;	// assign next Card to temp
	}
}

void insert_start(Card value)  // function to insert Card at head of linked list
{
	hand *temp = new hand;	// create and fill head with Card value given
	temp->data = value;
	temp->next = head;
	head = temp;
}

void delete_first()		// function deletes first Card in linked list
{
	hand *temp = new hand;
	temp = head;		// assign head to temp
	head = head->next;	// assign next hand to head 
	Card c;
	c = temp->data;		// create card for display
	std::cout << c << " was removed, your score is now: ";	//desctiptively explain what card was removed
	delete temp;	// release memory
}

int displayScore()	// function that retuns int sum of all Card in hand
{
	int sum = 0;			// declare function variables
	hand *temp = new hand;
	temp = head;			
	while (temp != NULL)	// while there is a hand
	{
		sum = sum + (temp->data);	// add value of card to int sum
		temp = temp->next;			// move to next hand
	}
	return sum;
}

std::string displayName() {	// display players name
	return name;
};
 
void setName(std::string n) { // setter of players name
	name = n;
};

Player operator=(const Player& rhs) {	// overloaded = operator 
	Player assigned;
	if (this == &rhs) {
		return *this;
	}
	
	assigned.head = rhs.head;
	assigned.name = rhs.name;
	return assigned;
};
private:		// hide data
	hand *head, *tail;	// pointers
	std::string name;	// name
};




struct player			// player structure to link Player in Game
{
	Player data;
	player *next;
};




class Game {
public:
	Game() {
		head = NULL;
		last = NULL;
		current = NULL;
		//current->next = head;
	}
	Game(player& a, player& b, player& c, player& d) {
		current = head = &a;
		a.next = &b;
		b.next = &c;
		c.next = &d;
		d.next = &a;

	}
	 
	/*friend player getHead(){
		return head;
	}*/

	//player *head;
/*	player getLastNode() {
		return *last;
	}*/

	void advance() {

		current = current->next;
		/*for (int i = 0; i < a; i++) {
			Game* temp = new Game;
			temp = current;
			= current->next;
		}*/
		
	}
	void advance(int a) {

		
		for (int i = 0; i < a; i++) {
			current = current->next;
		}

	}

	void addAtEnd(player *p) {
		//If list is empty
		if (head == NULL) {
			//making the new Node as Head
			current = head = last = p;
			//making the next pointer of the new Node as Null
			//p->next = head;
			//last = p;
		}
		else {
			
			
			last->next = p;
			//making the next pointer of new node point to head
			p->next = head;
			
		}
	}
	player *current;
private:
	player *head, *last;

};


#endif