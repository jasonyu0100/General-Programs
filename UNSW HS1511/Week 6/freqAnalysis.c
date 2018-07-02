#include <stdio.h>
#include <stdlib.h>

#define ASCII_LOWER_START 97
#define ASCII_UPPER_START 65
#define ALPHABET_COUNT 26

void readData(void);
void displayStatistics(int alphabetCount[]);
int getAlphabetValue(int letter);

int main(void) {
	readData();
	return EXIT_SUCCESS;
}

void readData(void) {
	int alphabetCount[ALPHABET_COUNT] = {0};
	int c = getchar();
	while (c != -1) {
		int numberLetter = getAlphabetValue(c);
		if (numberLetter == -1) {

		} else {
			alphabetCount[numberLetter] += 1;
		}
		c = getchar();
	}
	displayStatistics(alphabetCount);
}

int getAlphabetValue(int letter) {
	if (ASCII_UPPER_START<=letter && letter<=ASCII_UPPER_START+ALPHABET_COUNT-1) {
		letter -= ASCII_UPPER_START;
	} else if (ASCII_LOWER_START<=letter && letter<=ASCII_LOWER_START+ALPHABET_COUNT-1) {
		letter -= ASCII_LOWER_START;
	} else {
		letter = -1;
	}
	return letter;
}

void displayStatistics(int alphabetCount[]) {
	int count = 0;
	while (count < ALPHABET_COUNT) {
		char asciiChar = (count + ASCII_UPPER_START);
		int letterCount = alphabetCount[count];
		printf("%c has %d\n",asciiChar,letterCount);
		count ++;
	} 
}

