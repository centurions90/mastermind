/*
	Name	: Cheng, Chris Aaron L.
	Terminal: 24
	Section	: S11B
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define MAIN 		0
#define GAME 		1
#define SETTINGS	2
#define EXIT		3

#define RED		BACKGROUND_RED | BACKGROUND_INTENSITY
#define GREEN	BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define BLUE	BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define YELLOW	BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define CYAN	BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define MAGENTA BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define DRED	BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define DGREEN	BACKGROUND_GREEN
#define DBLUE	BACKGROUND_BLUE
#define WHITE	BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE

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

int generateRandomCode() {
	int number = rand() % 10000;
	int j;

	for (j = 0; j < 4; j++) {

	}
}

// displays graphical interface of main menu
void displayMain(HANDLE hConsole, WORD saved_attributes) {
	SetConsoleTextAttribute(hConsole, DRED);
	printf("XX XX  XX   XXX XXXX XXXX XXX  XX XX XXXX X  X XXX \n");
	printf("XX XX X  X X     XX  Xxx  X  X XX XX  XX  XX X X  X\n");
	printf("X X X XXXX   XX  XX  X    XXX  X X X  XX  X XX X  X\n");
	printf("X   X X  X XXXX  XX  XXXX X  X X   X XXXX X  X XXX \n\n");

	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("\t\t1 - Play\n");
	printf("\t\t2 - Settings\n");
	printf("\t\t3 - Exit\n\n");
	printf("Enter number here: ");
}

// displays graphical interface of settings
void displaySettings(HANDLE hConsole, WORD saved_attributes) {
	SetConsoleTextAttribute(hConsole, DRED);
	printf("Settings\n\n");

	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("\t1 - Change number of guesses\n");
	printf("\t2 - Change number of players\n");
	printf("\t3 - Change assigned colors\n");
	printf("\t4 - Back\n\n");
	printf("Enter number here: ");
}

void displayGame() {

}

void constructor() {
	srand(time(0));
	system("color 8f");
	clrscr();
}

void destructor() {
	system("color 07");
	clrscr();
}

int checkExactMatches(int nCode, int nGuess) {

}

int checkCorrectDigits(int nCode, int nGuess) {

}

void assignColor(
	int num,
	int nColor,
	int* nColor1,
	int* nColor2,
	int* nColor3,
	int* nColor4,
	int* nColor5,
	int* nColor6,
	int* nColor7,
	int* nColor8,
	int* nColor9
) {
	switch (num) {
		case 1:
			*nColor1 = nColor;
			break;
		case 2:
			*nColor2 = nColor;
			break;
		case 3:
			*nColor3 = nColor;
			break;
		case 4:
			*nColor4 = nColor;
			break;
		case 5:
			*nColor5 = nColor;
			break;
		case 6:
			*nColor6 = nColor;
			break;
		case 7:
			*nColor7 = nColor;
			break;
		case 8:
			*nColor8 = nColor;
			break;
		case 9:
			*nColor9 = nColor;
	}
}

int getColor(
	int num,
	int* nColor1,
	int* nColor2,
	int* nColor3,
	int* nColor4,
	int* nColor5,
	int* nColor6,
	int* nColor7,
	int* nColor8,
	int* nColor9
) {
	switch (num) {
		case 1:
			return *nColor1;
		case 2:
			return *nColor2;
		case 3:
			return *nColor3;
		case 4:
			return *nColor4;
		case 5:
			return *nColor5;
		case 6:
			return *nColor6;
		case 7:
			return *nColor7;
		case 8:
			return *nColor8;
		case 9:
			return *nColor9;
	}
}

int main() {
	int nChoice;
	int nGuesses	= 10;
	int nPlayers	= 2;
	int nMenu		= 0;
	int nMatch		= 0;
	int nCorrect	= 0;
	long int nAmount= 0;

	int nColor1 = RED;
	int nColor2 = GREEN;
	int nColor3 = BLUE;
	int nColor4 = YELLOW;
	int nColor5 = CYAN;
	int nColor6 = MAGENTA;
	int nColor7 = DRED;
	int nColor8 = DGREEN;
	int nColor9 = DBLUE;

	constructor();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	while (nMenu != EXIT) {
		// main menu
		if (nMenu == MAIN) {
			displayMain(hConsole, saved_attributes);
			while (!getInputInRange(&nChoice, 1, 3)) {
				clrscr();
				displayMain(hConsole, saved_attributes);
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
			displaySettings(hConsole, saved_attributes);
			while (!getInputInRange(&nChoice, 1, 4)) {
				clrscr();
				displaySettings(hConsole, saved_attributes);
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
			// red
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, RED);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, RED, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// green
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, GREEN);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, GREEN, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// blue
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, BLUE);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, BLUE, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// yellow
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, YELLOW);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, YELLOW, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// cyan
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, CYAN);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, CYAN, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// magenta
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, MAGENTA);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, MAGENTA, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// bright red
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, DRED);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, DRED, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// bright green
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, DGREEN);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, DGREEN, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			// bright blue
			printf("Assign number for ");
			SetConsoleTextAttribute(hConsole, DBLUE);
			printf(" ");
			SetConsoleTextAttribute(hConsole, saved_attributes);
			printf(": ");
			while (
				!getInputInRange(&nChoice, 1, 9) ||
				nAmount / (int)pow(10, nChoice - 1) % 10 != 0
			) {
				printf("Invalid Input. Try Again: ");
			}
			nAmount += pow(10, nChoice - 1);
			assignColor(nChoice, DBLUE, &nColor1, &nColor2, &nColor3, &nColor4, &nColor5, &nColor6, &nColor7, &nColor8, &nColor9);

			nMenu	= SETTINGS;
			nAmount = 0;
			clrscr();
		}
	}

	destructor();
	return 0;
}
