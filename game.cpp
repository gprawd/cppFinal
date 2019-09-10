/*
File:	CardGame
Name:	Greg Prawdzik
Date:	10/1/2018
Descr:	Card game that shuffles a deck and deals cards to four players.
		Each players name is displayed with thier cards, and the sum of thier cards.
		The highest sum of the cards wins. The game continues with each player discarding
		1 card and updating the total.*/


#include <iostream>     // Provides cout.
#include <cstdlib>		// Provides size_t
#include <string>
#include <array>
#include <ctime>
#include "Classes.h"  // Provides classes.

using namespace std;

//void getPlayers();
//void deal();
//void displayHand();
//void startGame();
void play();


int main() {

	//Game game;
	Player Player1;
	player player1;
	Player Player2;
	player player2;
	Player Player3;
	player player3;
	Player Player4;
	player player4;
	Game game(player1,player2,player3,player4);
	Deck deck;
	deck.Shuffle();
	string name;
	std::cout << "Please enter Player 1's name: ";
	std::cin >> name;
	Player1.setName(name);
	for (int j = 0; j < 13; j++) {
		Card x = (deck.getCard(j));
		Player1.insert_start(x);
	}
	player1.data = Player1;
	//game.addAtEnd(&player1);
	cout << Player1.displayName() << endl;
	Player1.display();
	cout << Player1.displayScore() << endl;

	std::cout << "Please enter Player 2's name: ";
	std::cin >> name;
	Player2.setName(name);
	for (int j = 13; j < 26; j++) {
		Card x = (deck.getCard(j));
		Player2.insert_start(x);
	}
	player2.data = Player2;
	//game.addAtEnd(&player2);
	cout << Player2.displayName() << endl;
	Player2.display();
	cout << Player2.displayScore() << endl;

	std::cout << "Please enter Player 3's name: ";
	std::cin >> name;
	Player3.setName(name);
	for (int j = 26; j < 39; j++) {
		Card x = (deck.getCard(j));
		Player3.insert_start(x);
	}
	player3.data = Player3;
	//game.addAtEnd(&player3);
	cout << Player3.displayName() << endl;
	Player3.display();
	cout << Player3.displayScore() << endl;


	std::cout << "Please enter Player 4's name: ";
	std::cin >> name;
	Player4.setName(name);
	for (int j = 39; j < 52; j++) {
		Card x = (deck.getCard(j));
		Player4.insert_start(x);
	}
	player4.data = Player4;
	//game.addAtEnd(&player4);
	cout << Player4.displayName() << endl;
	Player4.display();
	cout << Player4.displayScore() << endl;
	
	printf("Press Enter Key to Continue\n");	// pause game
	system("pause>nul");

	
	
	
	//Player *ptr = &Player1;
	//Game c;
//	((game.current)->data).displayScore;
	//int e = ptr.displayScore();
	//cout << ptr.displayScore() << endl;
	//game.advance(1);
	//cout << ptr.displayScore() << endl;
	while (game.current) {
		srand((unsigned)time(0));				// random number generator based off of system time <ctime>
		int random_integer;
		for (int i = 0; i < 12; i++) {		// iterate 13 times through players linked list hand


			random_integer = (rand() % 4);	// random number between 0-3
			switch (random_integer)			// switch to change order of discard based on random_integer
			{
			case 0:
				
					std::cout << Player1.displayName() << " the ";		// display players name
					Player1.delete_first();								// remove first card from list and display it
					std::cout << " " << Player1.displayScore() << std::endl;	// display players updated score
				
					std::cout << Player2.displayName() << " the ";		// display players name
					Player2.delete_first();								// remove first card from list and display it
					std::cout << " " << Player2.displayScore() << std::endl;	// display players updated score

					std::cout << Player3.displayName() << " the ";		// display players name
					Player3.delete_first();								// remove first card from list and display it
					std::cout << " " << Player3.displayScore() << std::endl;	// display players updated score

					std::cout << Player4.displayName() << " the ";		// display players name
					Player4.delete_first();								// remove first card from list and display it
					std::cout << " " << Player4.displayScore() << std::endl;	// display players updated score

				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 1:
				std::cout << Player2.displayName() << " the ";		// display players name
				Player2.delete_first();								// remove first card from list and display it
				std::cout << " " << Player2.displayScore() << std::endl;	// display players updated score

				std::cout << Player3.displayName() << " the ";		// display players name
				Player3.delete_first();								// remove first card from list and display it
				std::cout << " " << Player3.displayScore() << std::endl;	// display players updated score

				std::cout << Player4.displayName() << " the ";		// display players name
				Player4.delete_first();								// remove first card from list and display it
				std::cout << " " << Player4.displayScore() << std::endl;	// display players updated score

				std::cout << Player1.displayName() << " the ";		// display players name
				Player1.delete_first();								// remove first card from list and display it
				std::cout << " " << Player1.displayScore() << std::endl;	// display players updated score
				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 2:
				std::cout << Player3.displayName() << " the ";		// display players name
				Player3.delete_first();								// remove first card from list and display it
				std::cout << " " << Player3.displayScore() << std::endl;	// display players updated score

				std::cout << Player4.displayName() << " the ";		// display players name
				Player4.delete_first();								// remove first card from list and display it
				std::cout << " " << Player4.displayScore() << std::endl;	// display players updated score

				std::cout << Player1.displayName() << " the ";		// display players name
				Player1.delete_first();								// remove first card from list and display it
				std::cout << " " << Player1.displayScore() << std::endl;	// display players updated score

				std::cout << Player2.displayName() << " the ";		// display players name
				Player2.delete_first();								// remove first card from list and display it
				std::cout << " " << Player2.displayScore() << std::endl;	// display players updated score

				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 3:
				std::cout << Player4.displayName() << " the ";		// display players name
				Player4.delete_first();								// remove first card from list and display it
				std::cout << " " << Player4.displayScore() << std::endl;	// display players updated score

				std::cout << Player1.displayName() << " the ";		// display players name
				Player1.delete_first();								// remove first card from list and display it
				std::cout << " " << Player1.displayScore() << std::endl;	// display players updated score

				std::cout << Player2.displayName() << " the ";		// display players name
				Player2.delete_first();								// remove first card from list and display it
				std::cout << " " << Player2.displayScore() << std::endl;	// display players updated score

				std::cout << Player3.displayName() << " the ";		// display players name
				Player3.delete_first();								// remove first card from list and display it
				std::cout << " " << Player3.displayScore() << std::endl;	// display players updated score

				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;

			}
		}
		printf("Press Enter Key to Continue\n");	// pause game
		system("pause>nul");
	}
	/*	string name;			// declare variables and objects
	Player player[4];
	Deck deck;

	deck.Shuffle();			// randomizes the order of the deck 
	for (int i = 0; i < 4; i++) {
		cout << "Please enter Player " << i+1 << "'s name: ";
		cin >> name;
		player[i].setName(name);	// set player[i]'s name
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0 +(i*13); j < 13+(i*13); j++) {	// iterate 13 times
			player[i].insert_start(deck.getCard(j));		// deal the player a card
		}
	}

	for (int i = 0; i < 4; i++) {
		std::cout << player[i].displayName() << std::endl;		//display player name
		player[i].display();	// display players full hand
		std::cout << "Score: " << player[i].displayScore() << std::endl; // display players score
	}
	printf("Press Enter Key to Continue\n");	// pause game
	system("pause>nul");
	
	srand((unsigned)time(0));				// random number generator based off of system time <ctime>
	int random_integer;
	for (int i = 0; i < 12; i++) {		// iterate 13 times through players linked list hand
		
				
			random_integer = (rand() % 4);	// random number between 0-3
			switch (random_integer)			// switch to change order of discard based on random_integer
			{
			case 0:	
				for (int j = 0; j < 4; j++) {
					std::cout << player[j].displayName() << " the ";		// display players name
					player[j].delete_first();								// remove first card from list and display it
					std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
				}
				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 1:
				for (int j = 1; j < 4; j++) {
					std::cout << player[j].displayName() << " the ";		// display players name
					player[j].delete_first();								// remove first card from list and display it
					std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
				}
				std::cout << player[0].displayName() << " the ";		// display players name
				player[0].delete_first();								// remove first card from list and display it
				std::cout << " " << player[0].displayScore() << std::endl;	// display players updated score
				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 2:
				for (int j = 2; j < 4; j++) {
					std::cout << player[j].displayName() << " the ";		// display players name
					player[j].delete_first();								// remove first card from list and display it
					std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
				}
				for (int j = 0; j < 2; j++) {
					std::cout << player[j].displayName() << " the ";		// display players name
					player[j].delete_first();								// remove first card from list and display it
					std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
				}
				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;
			case 3:
				std::cout << player[3].displayName() << " the ";		// display players name
				player[3].delete_first();								// remove first card from list and display it
				std::cout << " " << player[3].displayScore() << std::endl;	// display players updated score

				for (int j = 0; j < 3; j++) {
					std::cout << player[j].displayName() << " the ";		// display players name
					player[j].delete_first();								// remove first card from list and display it
					std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
				}
				printf("Press Enter Key to Continue\n");			// pause game
				system("pause>nul");
				break;

			}
	}
			

		

		for (int j = 0; j < 4; j++) {
			std::cout << player[j].displayName() << " the ";		// display players name
			player[j].delete_first();								// remove first card from list and display it
			std::cout << " " << player[j].displayScore() << std::endl;	// display players updated score
		}
		printf("Press Enter Key to Continue\n");			// pause game
		system("pause>nul");
		return EXIT_SUCCESS;*/
}


void play() {
	
}
/*void startGame() {
	//Game game;
	Deck deck;
	deck.Shuffle();
	string name;
	for (int i = 0; i < 4; i++) {
		Player *tempP = new Player;
		player *tempp = new player;
		std::cout << "Please enter Player " << i + 1 << "'s name: ";
		cin >> name;
		tempP->setName(name);
		cout << name << endl;
		for (int j = 0 + (i * 13); j < 13 + (i * 13); j++) {	// iterate 13 times
			//Player *temp = new Player;
			Card x = (deck.getCard(j));

			//game.current->data = *tempP;
			tempP->insert_start(x);		// deal the player a card
			tempp->data = *tempP;
			cout << x << endl;
		}
		std::cout << this.current->name;
	}
}*/

/*void startGame() {
	Game game;
	Player Player1;
	player player1;
	Player Player2;
	player player2;
	Player Player3;
	player player3;
	Player Player4;
	player player4;
	Deck deck;
	deck.Shuffle();
	string name;
	std::cout << "Please enter Player 1's name: ";
	std::cin >> name;
	Player1.setName(name);
	for (int j = 0; j < 13; j++){
		Card x = (deck.getCard(j));
		Player1.insert_start(x);
	}
	player1.data = Player1;
	game.addAtEnd(&player1);
	cout << Player1.displayName() << endl;
	Player1.display();
	cout << Player1.displayScore() << endl;

	std::cout << "Please enter Player 2's name: ";
	std::cin >> name;
	Player2.setName(name);
	for (int j = 14; j < 26; j++) {
		Card x = (deck.getCard(j));
		Player2.insert_start(x);
	}
	player2.data = Player2;
	game.addAtEnd(&player2);
	cout << Player2.displayName() << endl;
	Player2.display();
	cout << Player2.displayScore() << endl;

	std::cout << "Please enter Player 3's name: ";
	std::cin >> name;
	Player3.setName(name);
	for (int j = 26; j < 39; j++) {
		Card x = (deck.getCard(j));
		Player3.insert_start(x);
	}
	player3.data = Player3;
	game.addAtEnd(&player3);
	cout << Player3.displayName() << endl;
	Player3.display();
	cout << Player3.displayScore() << endl;


	std::cout << "Please enter Player 4's name: ";
	std::cin >> name;
	Player4.setName(name);
	for (int j = 39; j < 52; j++){
		Card x = (deck.getCard(j));
		Player4.insert_start(x);
	}
	player4.data = Player4;
	game.addAtEnd(&player4);
	cout << Player4.displayName() << endl;
	Player4.display();
	cout << Player4.displayScore() << endl;

	
}



/*void displayHand() {
	player tempp;
	tempp* =  Game::current;

}*/

/*void displayHand() {
	for (int i = 0; i < 4; i++) {
		string name;
		name = 
		player *tempp = new player;
		Player *tempP = new Player;
		tempp->data =  Game::getHead;
		*tempP = tempp->data;
		//tempP->;
		//Player tempP = new Player;
		//tempp->next = getHead();
		//Card c = tempp->data;	// set player's name
		//tempp->data = tempP*;
		//Player addAtEnd(tempp->next);
}*/

/*void deal() {
	Deck deck;
	deck.Shuffle();			// randomizes the order of the deck 
	for (int i = 0; i < 4; i++) {
		string name;
		Player *tempP = new Player;
		//player *tempp = new player;
		std::cout << "Please enter Player " << i + 1 << "'s name: ";
		cin >> name;
		tempP->setName(name);	// set player's name
		//tempp->data = tempP*;
		Player addAtEnd(Player& tempP);
		
		for (int j = 0 + (i * 13); j < 13 + (i * 13); j++) {	// iterate 13 times
			//Player *temp = new Player;
			Card x = (deck.getCard(j));
			tempP->insert_start( x);		// deal the player a card
			//tempP->display();
		/*	Card tempC;
			tempC = deck.getCard(j);
		cout << tempC << endl;		// tester
			//delete temp;	
			//Card *test = new Card;
			//test = &tempP->d;
			cout << x << endl;
		}
		Player addAtEnd(Player& tempP);
		delete tempP;
		
	}
}
*/

/*void getPlayers() {
	cout << "-------2--------" << endl;
	
	string name;
	Player *tempP = new Player;
	//player *tempp = new player;
	std::cout << "Please enter Player " << i + 1 << "'s name: ";
	tempP->setName(name);	// set player's name
	//tempp->data = tempP*;
	Player addAtEnd(Player& tempP);
	delete tempP;
	//delete tempp;
	
}*/

/*
Please enter Player 1's name: Greg
Please enter Player 2's name: Jacob
Please enter Player 3's name: Bridget
Please enter Player 4's name: Marie
Greg
King of Spades
Ten of Spades
Queen of Spades
Two of Clubs
Ace of Spades
Nine of Spades
Three of Hearts
Ace of Clubs
Seven of Hearts
Eight of Spades
Seven of Diamonds
Nine of Diamonds
Two of Hearts
Score: 84
Jacob
Eight of Hearts
Six of Hearts
Nine of Hearts
Four of Clubs
Ace of Hearts
Queen of Hearts
Five of Spades
Jack of Diamonds
Jack of Hearts
Five of Hearts
Six of Spades
Ten of Diamonds
Two of Diamonds
Score: 90
Bridget
Queen of Diamonds
Two of Spades
Four of Hearts
Ten of Clubs
Ace of Diamonds
Four of Spades
Jack of Spades
Seven of Clubs
Eight of Diamonds
Eight of Clubs
King of Hearts
Five of Clubs
Nine of Clubs
Score: 94
Marie
Six of Clubs
Three of Diamonds
King of Diamonds
Three of Clubs
King of Clubs
Three of Spades
Five of Diamonds
Ten of Hearts
Seven of Spades
Queen of Clubs
Jack of Clubs
Four of Diamonds
Six of Diamonds
Score: 96
Press Enter Key to Continue
Bridget the Queen of Diamonds was removed, your score is now:  82
Marie the Six of Clubs was removed, your score is now:  90
Greg the King of Spades was removed, your score is now:  71
Jacob the Eight of Hearts was removed, your score is now:  82
Press Enter Key to Continue
Greg the Ten of Spades was removed, your score is now:  61
Jacob the Six of Hearts was removed, your score is now:  76
Bridget the Two of Spades was removed, your score is now:  80
Marie the Three of Diamonds was removed, your score is now:  87
Press Enter Key to Continue
Bridget the Four of Hearts was removed, your score is now:  76
Marie the King of Diamonds was removed, your score is now:  74
Greg the Queen of Spades was removed, your score is now:  49
Jacob the Nine of Hearts was removed, your score is now:  67
Press Enter Key to Continue
Greg the Two of Clubs was removed, your score is now:  47
Jacob the Four of Clubs was removed, your score is now:  63
Bridget the Ten of Clubs was removed, your score is now:  66
Marie the Three of Clubs was removed, your score is now:  71
Press Enter Key to Continue
Bridget the Ace of Diamonds was removed, your score is now:  65
Marie the King of Clubs was removed, your score is now:  58
Greg the Ace of Spades was removed, your score is now:  46
Jacob the Ace of Hearts was removed, your score is now:  62
Press Enter Key to Continue
Jacob the Queen of Hearts was removed, your score is now:  50
Bridget the Four of Spades was removed, your score is now:  61
Marie the Three of Spades was removed, your score is now:  55
Greg the Nine of Spades was removed, your score is now:  37
Press Enter Key to Continue
Greg the Three of Hearts was removed, your score is now:  34
Jacob the Five of Spades was removed, your score is now:  45
Bridget the Jack of Spades was removed, your score is now:  50
Marie the Five of Diamonds was removed, your score is now:  50
Press Enter Key to Continue
Marie the Ten of Hearts was removed, your score is now:  40
Greg the Ace of Clubs was removed, your score is now:  33
Jacob the Jack of Diamonds was removed, your score is now:  34
Bridget the Seven of Clubs was removed, your score is now:  43
Press Enter Key to Continue
Marie the Seven of Spades was removed, your score is now:  33
Greg the Seven of Hearts was removed, your score is now:  26
Jacob the Jack of Hearts was removed, your score is now:  23
Bridget the Eight of Diamonds was removed, your score is now:  35
Press Enter Key to Continue
Jacob the Five of Hearts was removed, your score is now:  18
Bridget the Eight of Clubs was removed, your score is now:  27
Marie the Queen of Clubs was removed, your score is now:  21
Greg the Eight of Spades was removed, your score is now:  18
Press Enter Key to Continue
Bridget the King of Hearts was removed, your score is now:  14
Marie the Jack of Clubs was removed, your score is now:  10
Greg the Seven of Diamonds was removed, your score is now:  11
Jacob the Six of Spades was removed, your score is now:  12
Press Enter Key to Continue
Jacob the Ten of Diamonds was removed, your score is now:  2
Bridget the Five of Clubs was removed, your score is now:  9
Marie the Four of Diamonds was removed, your score is now:  6
Greg the Nine of Diamonds was removed, your score is now:  2
Press Enter Key to Continue
Greg the Two of Hearts was removed, your score is now:  0
Jacob the Two of Diamonds was removed, your score is now:  0
Bridget the Nine of Clubs was removed, your score is now:  0
Marie the Six of Diamonds was removed, your score is now:  0
Press Enter Key to Continue

C:\Users\Gregory Prawdzik\source\repos\Project2\Debug\Project2.exe (process 936) exited with code 0.
Press any key to close this window . . .

*/