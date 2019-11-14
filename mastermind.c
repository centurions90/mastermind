/*
	Name	: Cheng, Chris Aaron L.
	Terminal: 24
	Section	: S11B
*/

#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

#define MENU 		0
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

void displayMenu() {

}

void displaySettings() {

}

int main() {
	int nChoice;
	int nGuesses	= 10;
	int nPlayers	= 2;
	int nExit		= 0;
	int nLevel		= 0;

	while (!nExit) {
		if (nLevel == MENU) {
			displayMenu();
			getInputandCheck(&nChoice, 1, 3);

			nLevel = nChoice;
		} else if (nLevel == GAME) {

		} else if (nLevel == SETTINGS) {
			displaySettings();
			getInputandCheck(&nChoice, 1, 4);

			nLevel = (nChoice + 3) % 7;
		} else if (nLevel == EXIT) {
			nExit = 1;
		} else if (nLevel == 4) {
			printf("Change number of guesses to: ");
			scanf("%d", &nGuesses);
			nLevel == SETTINGS;
		} else if (nLevel == 5) {
			printf("Change number of players to: ");
			scanf("%d", &nPlayers);
			nLevel == SETTINGS;	
		} else if (nLevel == 6) {
			printf("todo");
			nLevel == SETTINGS;
		}
	}

	return 0;
}
