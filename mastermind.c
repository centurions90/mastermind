/*
	Name	: Cheng, Chris Aaron L.
	Terminal: 24
	Section	: S11B
*/

#include <stdio.h>
//#include <windows.h>
#include <stdlib.h>

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


	return 0;
}
