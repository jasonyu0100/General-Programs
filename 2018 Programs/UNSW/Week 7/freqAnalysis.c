#include <stdio.h>
#include <stdlib.h>

#define ASCII_LOWER_START 97
#define ASCII_UPPER_START 65
#define ALPHABET_COUNT 26
#define VOWELS {'A','E','I','O','U'}

void readData(void);
void displayStatistics(int alphabetCount[]);
int getAlphabetValue(int letter);
int letterCount = 0;
int upperCounter = 0;
int lowerCounter = 0;
int newLineCounter = 0;
int vowelCount = 0;
int kCount = 0;
int spaceCounter = 0;

int main(void) {
	readData();

	printf("Upper Case:%d\n",upperCounter);
	printf("Lower Case:%d\n",lowerCounter);
	printf("Letter Count:%d\n",letterCount);
	printf("newLineCounter:%d\n",newLineCounter);
	printf("vowelCount:%d\n",vowelCount);
	printf("kCount:%d\n",kCount);
	printf("spaceCounter:%d\n",spaceCounter);
	return EXIT_SUCCESS;
}

void readData(void) {
	int alphabetCount[ALPHABET_COUNT] = {0};
	int c = getchar();
	while (c != -1) {
		//
		// char temp = c;
		// printf("char:%c\n",temp);
		//
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
		upperCounter += 1;
		letterCount += 1;
	} else if (ASCII_LOWER_START<=letter && letter<=ASCII_LOWER_START+ALPHABET_COUNT-1) {
		letter -= ASCII_LOWER_START;
		lowerCounter += 1;
		letterCount += 1;
	} else {
		if (letter == 13) {
			newLineCounter += 1;
		} else if (letter == 32) {
			spaceCounter += 1;
		}
		letter = -1;
	}

	return letter;
}

int checkVowel(char letter) {
	char vowels[] = VOWELS;
	int count = 0;
	int flag = 0;
	while (flag == 0 && count < 5) {
		if (letter == vowels[count]) {
			flag = 1;
		}
		count += 1;
	}
	return flag;
}

void displayStatistics(int alphabetCount[]) {
	int count = 0;
	while (count < ALPHABET_COUNT) {
		char asciiChar = (count + ASCII_UPPER_START);
		int letterCount = alphabetCount[count];
		if (checkVowel(asciiChar) == 1) {
			vowelCount += letterCount;
		} else if (asciiChar == 'K') {
			kCount += letterCount;
		}
		printf("%c has %d\n",asciiChar,letterCount);
		count ++;
	} 
}

