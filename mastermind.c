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

void getInputAndCheck(int *nChoice, int nStart, int nEnd) {
	int nValid = 0;

	while (!nValid) {
		scanf("%d", nChoice);

		if (*nChoice >= nStart && *nChoice <= nEnd) {
			nValid = 1;
		} else {
			printf("Try Again: ");
		}
	}
}

void displayMain() {

}

void displaySettings() {

}

int checkGuess(int nCode, int nGuess, int* nMatch, int* nCorrect) {

}

int initialize() {
	srand(time(0));
}

int main() {
	int nChoice;
	int nGuesses	= 10;
	int nPlayers	= 2;
	int nMenu		= 0;
	int nColor		= 0;

	while (nMenu != EXIT) {
		if (nMenu == MAIN) {
			displayMain();
			getInputandCheck(&nChoice, 1, 3);

			nMenu = nChoice;
		}

		else if (nMenu == GAME) {

		}

		else if (nMenu == SETTINGS) {
			displaySettings();
			getInputandCheck(&nChoice, 1, 5);

			nMenu = (nChoice + 3) % 8;
		}

		else if (nMenu == 4) {
			printf("Change number of guesses to: ");
			scanf("%d", &nGuesses);
			nMenu = SETTINGS;
		}

		else if (nMenu == 5) {
			printf("Change number of players to: ");
			scanf("%d", &nPlayers);
			nMenu = SETTINGS;
		}

		else if (nMenu == 6) {
			nColor = !nColor;
			nMenu = SETTINGS;
		}

		else if (nMenu == 7) {
			if (nColor) {

			} else {
				printf("Please turn on color mode first");
			}
			nMenu = SETTINGS;
		}
	}

	return 0;
}
