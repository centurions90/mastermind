/*
	Name	: Cheng, Chris Aaron L.
	Terminal: 24
	Section	: S11B
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAIN 		0
#define GAME 		1
#define SETTINGS	2
#define EXIT		3

// stores choice and returns true if choice is in range
int getInputInRange(int *nChoice, int nStart, int nEnd) {
	scanf("%d", nChoice);

	if (*nChoice >= nStart && *nChoice <= nEnd) {
		return 1;
	} else {
		return 0;
	}
}

// clears terminal screen
void clrscr() {
	system("cls || clear");
}

// displays graphical interface of main menu
void displayMain() {

}

// displays graphical interface of settings
void displaySettings() {

}

// initialize random number generator
void initialize() {
	srand(time(0));
}

int checkExactMatches(int nCode, int nGuess, int* nMatch, int* nCorrect) {

}

int checkCorrectDigits() {

}

int main() {
	int nChoice;
	int nGuesses	= 10;
	int nPlayers	= 2;
	int nMenu		= 0;

	while (nMenu != EXIT) {
		// main menu
		if (nMenu == MAIN) {
			displayMain();
			while (!getInputInRange(&nChoice, 1, 3)) {
				clrscr();
				displayMain();
				printf("Input Invalid. Try Again:\n");
			}

			clrscr();
			nMenu = nChoice;
		}

		// game
		else if (nMenu == GAME) {

		}

		// settings
		else if (nMenu == SETTINGS) {
			displaySettings();
			while (getInputInRange(&nChoice, 1, 4)) {
				clrscr();
				displaySettings();
				printf("Input Invalid. Try Again:\n");
			}

			clrscr();
			nMenu = (nChoice + 3) % 7;
		}

		else if (nMenu == 4) {
			do {
				printf("Change number of guesses to: ");
				scanf("%d", &nGuesses);
				printf("Invalid Input. Try Again.\n");
				nMenu = SETTINGS;
			} while (nGuesses <= 0);
			clrscr();
		}

		else if (nMenu == 5) {
			do {
				printf("Change number of players to: ");
				scanf("%d", &nPlayers);
				printf("Invalid Input. Try Again.\n");
				nMenu = SETTINGS;
			} while (nPlayers <= 0);
			clrscr();
		}

		else if (nMenu == 6) {
			nMenu = SETTINGS;
			clrscr();
		}
	}

	return 0;
}
