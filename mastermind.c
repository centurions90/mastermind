/*
	Name	: Cheng, Chris Aaron L.
	Terminal: 24
	Section	: S11B
*/

#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

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

int main() {
	int nChoice;
	int nGuesses	= 10;
	int nPlayers	= 2;

	return 0;
}
