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

#define RED		BACKGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define GREEN	BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define BLUE	BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define YELLOW	BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define CYAN	BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define MAGENTA BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define DRED	BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define DGREEN	BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define DBLUE	BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
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
	int nNumber = 0;
	int nTemp;
	int j;

	for (j = 0; j < 4; j++) {
		nTemp = rand() % 10;
		while (nTemp == 0) {
			nTemp = rand() % 10;
		}
		nNumber += nTemp * pow(10, j);
	}

	return nNumber;
}

int hasZeros(int nNum) {
	while (nNum != 0) {
		if (nNum % 10 == 0) {
			return 1;
		} else {
			nNum /= 10;
		}
	}

	return 0;
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

// sets up console colors and random seed
void constructor() {
	srand(time(0));
	system("color 8f");
	clrscr();
}

// reverts console back to normal
void destructor() {
	system("color 07");
	clrscr();
}

int checkExactMatches(int nCode, int nGuess) {
	int nMatches = 0;

	while (nCode != 0 && nGuess != 0) {
		if (nCode % 10 == nGuess % 10) {
			nMatches++;
		}
		nCode	/= 10;
		nGuess	/= 10;
	}

	return nMatches;
}

int checkCorrectDigits(int nCode, int nGuess) {
	int nMatches	= 0;
	int nTemp		= nGuess;
	int nTempCode	= nCode;
	int j			= 1;
	int k			= 1;
	int nMatched	= 0;

	while (nCode != 0) {
		while (nGuess / j != 0 && !nMatched) {
			if (j != k) {
				if (nCode % 10 == nTemp / j % 10 && nTempCode / j % 10 != nGuess / j % 10) {
					nMatches++;
					nMatched = 1;
					nTemp	-= nTemp / j % 10 * j;
				}
			}

			j *= 10;
		}

		k		*= 10;
		j		 = 1;
		nCode	/= 10;
		nMatched = 0;
	}

	return nMatches;
}

// assigns color to a digit
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
	int nColor1,
	int nColor2,
	int nColor3,
	int nColor4,
	int nColor5,
	int nColor6,
	int nColor7,
	int nColor8,
	int nColor9
) {
	switch (num) {
		case 1:
			return nColor1;
		case 2:
			return nColor2;
		case 3:
			return nColor3;
		case 4:
			return nColor4;
		case 5:
			return nColor5;
		case 6:
			return nColor6;
		case 7:
			return nColor7;
		case 8:
			return nColor8;
		case 9:
			return nColor9;
	}
}

// shows all the assigned colors
void showColors(
	HANDLE hConsole,
	WORD saved_attributes,
	int nColor1,
	int nColor2,
	int nColor3,
	int nColor4,
	int nColor5,
	int nColor6,
	int nColor7,
	int nColor8,
	int nColor9
) {
	int j;

	for (j = 1; j <= 9; j++) {
		SetConsoleTextAttribute(hConsole, getColor(
			j,
			nColor1,
			nColor2,
			nColor3,
			nColor4,
			nColor5,
			nColor6,
			nColor7,
			nColor8,
			nColor9
		));
		printf("%d", j);
		SetConsoleTextAttribute(hConsole, saved_attributes);
		printf(" ");
	}

	printf("\n");
}

// converts numbers to the defined colors
void convertToColors(
	int nNum,
	HANDLE hConsole,
	WORD saved_attributes,
	int nColor1,
	int nColor2,
	int nColor3,
	int nColor4,
	int nColor5,
	int nColor6,
	int nColor7,
	int nColor8,
	int nColor9
) {
	int nLength = 0;
	int nTemp = nNum;
	while (nTemp != 0) {
		nTemp /= 10;
		nLength++;
	}

	nLength--;

	while (nLength >= 0) {
		SetConsoleTextAttribute(hConsole, getColor(
			nNum / (int)pow(10, nLength) % 10,
			nColor1,
			nColor2,
			nColor3,
			nColor4,
			nColor5,
			nColor6,
			nColor7,
			nColor8,
			nColor9
		));
		printf(" ");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		printf(" ");
		nLength--;
	}
	printf("\n");
}

int main() {
	int nChoice;
	int nCode;
	int nGuesses	= 10;
	int nPlayers	= 2;
	int nMenu		= 0;
	int nMatch		= 0;
	int nCorrect	= 0;
	long int nAmount= 0;
	int j, k, l;

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

	// used to control console colors
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
				printf("\nInput Invalid. Try Again: ");
			}

			clrscr();
			nMenu = nChoice;
		}

		// game
		else if (nMenu == GAME) {
			nCode = generateRandomCode();

			printf("Enter 0 in order to reveal the sequence\n");
			printf("Black - Exact color and position, White - Exact color wrong position\n\n");

			for (j = 0; j < nGuesses; j++) {
				for (k = 1; k <= nPlayers; k++) {
					printf("Choices: ");
					showColors(
						hConsole,
						saved_attributes,
						nColor1,
						nColor2,
						nColor3,
						nColor4,
						nColor5,
						nColor6,
						nColor7,
						nColor8,
						nColor9
					);
					printf("It's player %d's turn:\n", k);
					printf("Enter your guess: ");
					while (!getInputInRange(&nChoice, 1000, 9999) || hasZeros(nChoice)) {
						if (nChoice == 0) {
							printf("\nThe secret has been revealed to you\n");
							convertToColors(
								nCode,
								hConsole,
								saved_attributes,
								nColor1,
								nColor2,
								nColor3,
								nColor4,
								nColor5,
								nColor6,
								nColor7,
								nColor8,
								nColor9
							);
							printf("Enter your guess: ");
						} else {
							printf("\nInvalid Input. Try Again: ");
						}
					}

					printf("Guess: ");

					convertToColors(
						nChoice,
						hConsole,
						saved_attributes,
						nColor1,
						nColor2,
						nColor3,
						nColor4,
						nColor5,
						nColor6,
						nColor7,
						nColor8,
						nColor9
					);

					printf("\n");

					nMatch	= checkExactMatches(nCode, nChoice);
					nCorrect= checkCorrectDigits(nCode, nChoice);
					for (l = 0; l < nMatch; l++) {
						SetConsoleTextAttribute(hConsole, 0);
						printf(" ");
						SetConsoleTextAttribute(hConsole, saved_attributes);
						printf(" ");
					}

					for (l = 0; l < nCorrect; l++) {
						SetConsoleTextAttribute(hConsole, WHITE);
						printf(" ");
						SetConsoleTextAttribute(hConsole, saved_attributes);
						printf(" ");
					}

					printf("\n\n");

					if (nMatch == 4) {
						j = nGuesses + 1;

						printf("Player %d won!!\n", k);
						k = nPlayers;
					}
				}
			}

			if (j == nGuesses) {
				printf("Game Over\n");
			}

			printf("Would you like to try again?\n");
			printf("1 - Back to Menu\n");
			printf("2 - Try Again\n");
			printf("Enter number: ");
			while (!getInputInRange(&nChoice, 1, 2)) {
				printf("\nInvalid Input. Try Again: ");
			}

			clrscr();
			nMenu = nChoice - 1;
		}

		// settings
		else if (nMenu == SETTINGS) {
			displaySettings(hConsole, saved_attributes);
			while (!getInputInRange(&nChoice, 1, 4)) {
				clrscr();
				displaySettings(hConsole, saved_attributes);
				printf("\nInput Invalid. Try Again: ");
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
