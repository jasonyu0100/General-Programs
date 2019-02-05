#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Test Game Variables
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}

#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

void test(Game g);
Game newGame(int disciplinesValues[],int diceValues[]);

int main() {
	int disciplinesValues[] = DEFAULT_DISCIPLINES;
    int diceValues[] = DEFAULT_DICE;
    Game g = newGame (disciplinesValues, diceValues);
    test(g);
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void test(Game g) {
	// Testing Turn Counter
	int player = getWhoseTurn(g);
	assert(player == NO_ONE);

	// Action Step
	int diceRandVal = 5;
	throwDice(g,diceRandVal);
	action turnAction;
	turnAction.actionCode = PASS;
	makeAction(g,turnAction);

	//Testing Discipline and Discipline Dice Value
	int discipline = getDiscipline(g,0);
	assert(discipline == STUDENT_BQN);
	int disciplineValue = getDiceValue(g,0);
	assert(disciplineValue == 9);

	//Test Turn Updater
	int turnNumber = getTurnNumber(g);
	assert(turnNumber == 0);
	player = getWhoseTurn (g);
	assert(player == UNI_A);

	// Dispose Game
	disposeGame(g);
	printf("All tests passed!\n");
}