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

// All tests
void tests(Game g);
void testGetDiscipline(Game g, int regionID);
// void testDisposeGame (Game g);
// void testMakeAction (Game g, action a);
// void testgetDiceValue (Game g, int regionID);
// void testThrowDice (Game g);
// void testGetTurnNumber(Game g);
// void testGetMostARCs (Game g);
// void testGetMostPublications (Game g);
// void testGetWhoseTurn (Game g);
// void testGetCampus(Game g, path pathToVertex);
// void testGetARC(Game g, path pathToEdge);
// void testIsLegalAction (Game g, action a);
// void testGetKPIpoints (Game g, int player);
// void testGetARCs (Game g, int player);
// void testGetGO8s (Game g, int player);
// void testGetCampuses (Game g, int player);
// void testGetIPs (Game g, int player);
// void testGetPublications (Game g, int player);
// void testGetStudents (Game g, int player, int discipline);
// void testgetExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo);

int main() {
	int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    tests(g);
    disposeGame(g);
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void tests(Game g) {
	// Tests all game functions
	testGetDiscipline(Game g, int regionID);
	// testDisposeGame (Game g);
	// testMakeAction (Game g, action a);
	// testgetDiceValue (Game g, int regionID);
	// testThrowDice (Game g);
	// testGetTurnNumber(Game g);
	// testGetMostARCs (Game g);
	// testGetMostPublications (Game g);
	// testGetWhoseTurn (Game g);
	// testGetCampus(Game g, path pathToVertex);
	// testGetARC(Game g, path pathToEdge);
	// testIsLegalAction (Game g, action a);
	// testGetKPIpoints (Game g, int player);
	// testGetARCs (Game g, int player);
	// testGetGO8s (Game g, int player);
	// testGetCampuses (Game g, int player);
	// testGetIPs (Game g, int player);
	// testGetPublications (Game g, int player);
	// testGetStudents (Game g, int player, int discipline);
	// testgetExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo);
	printf("All tests passed!\n");
}

void testGetDiscipline(Game g) {
	int discipline = getDiscipline(g,0);
	assert(discipline == STUDENT_BQN);
}

void testDisposeGame (Game g) {

}

void testMakeAction (Game g, action a) {

}

void testgetDiceValue (Game g, int regionID){
	int diceValue = getDiceValue(g,0);
	assert(diceValue == 9);
}

void testThrowDice (Game g) {
	throwDice(g,)
}

void testGetTurnNumber(Game g) {

}

void testGetMostARCs (Game g) {

}

void testGetMostPublications (Game g) {

}

void testGetWhoseTurn (Game g) {

}

void testGetCampus(Game g, path pathToVertex) {

}

void testGetARC(Game g, path pathToEdge) {

}

void testIsLegalAction (Game g, action a) {

}

void testGetKPIpoints (Game g, int player) { // ???

}

void testGetARCs (Game g, int player) {

}

void testGetGO8s (Game g, int player) {

}

void testGetCampuses (Game g, int player) {

}

void testGetIPs (Game g, int player) {

}

void testGetPublications (Game g, int player) {
    
}

void testGetStudents (Game g, int player, int discipline) {

}

void testgetExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo) {

}
