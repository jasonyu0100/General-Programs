#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Game.h"

#define ROW_COUNT 11
#define MAX_COLUMNS 6
#define REGION_VERTICIES 6

// STRUCTS
typedef struct _player {
	// Campuses
	path campuses[PATH_LIMIT];
	// Arc Grants
	path arcs[PATH_LIMIT];
	// GO8 Campuses
	path upgradedCampuses[PATH_LIMIT];
	int ThD;
	int BPS;
	int BHW;
	int MJ;
	int MTV;
	int MM;
	// Achievements, used in the final calculation of KPI points
	int numCampuses;
	int numGO8Campuses;
	int numARCGrants;
	int numIPs;
	int numPublications;
	// Records whether player's most ARC and most Publications achievement is first time
	int firstTimeMostARCGrants;
	int firstTimeMostPublications;
	// First player to 150 KPI wins
	int numKPI;
} newPlayer;

typedef struct _game {
	// Number of players
	newPlayer players[NUM_UNIS];
	// Number of turns passed
	int numTurn;
	// Discipline in each sector
	int disciplines[NUM_REGIONS];
	// Dice Value in each sector
	int diceValues[NUM_REGIONS];
	// Global Achievements
	int playerWithMostARCGrants;
	int playerWithMostPublications;
	int playerWinner;
	int regionCoordinates[NUM_REGIONS][2];
} game;

typedef struct _coordinate {
	int row;
	int col;
} coordinate;

newPlayer makePlayer(newPlayer currentPlayer) {
	memset(currentPlayer.campuses, '0', sizeof(char));
	memset(currentPlayer.arcs, '0', sizeof(char));
	memset(currentPlayer.upgradedCampuses, '0', sizeof(char));

	// What does this do?
	int firstTimeMostARCGrants = TRUE;
	int firstTimeMostPublications = TRUE;
	currentPlayer.BPS = 3;
	currentPlayer.BHW = 3;
	currentPlayer.MTV = 1;
	currentPlayer.MJ = 1;
	currentPlayer.MM = 1;
	currentPlayer.ThD = 0;
	currentPlayer.numPublications = 0;
	currentPlayer.numIPs = 0;
	currentPlayer.numKPI = 0;
	return currentPlayer;
}

Game newGame(int disciplinesValues[], int diceValues[]) {
	Game g = malloc(sizeof(game));
	int count = 0;
	while (count < NUM_REGIONS) {
		g->disciplines[count] = disciplinesValues[count];
		count++;
	}
	count = 0;
	while (count < NUM_REGIONS) {
		g->diceValues[count] = diceValues[count];
		count++;
	}
	g->numTurn = -1;
	newPlayer playerOne = makePlayer(playerOne);
	newPlayer playerTwo = makePlayer(playerTwo);
	newPlayer playerThree = makePlayer(playerThree);
	g->players[0] = playerOne;
	g->players[1] = playerTwo;
	g->players[1] = playerThree;
	g->playerWithMostARCGrants = NO_ONE;
	g->playerWithMostPublications = NO_ONE;
	g->playerWinner = NO_ONE;
	setRegionCoordinates(g);
	return g;
}

static void setRegionCoordinates(Game g) {
	int count = 0;
	int regionCoordinates[NUM_REGIONS][2] = {
		{1,4},
		{2,2},
		{2,5},
		{3,1},
		{3,4},
		{3,7},
		{4,2},
		{4,5},
		{5,1},
		{5,4},
		{5,7},
		{6,2},
		{6,5},
		{7,1},
		{7,4},
		{7,7},
		{8,2},
		{8,5},
		{9,4}
	};
	while (count < NUM_REGIONS) {
		int insideIndex = 0;
		while (insideIndex < 2) {
			g->regionCoordinates[count][insideIndex] = regionCoordinates[count][insideIndex];
			insideIndex ++;
		}
		count ++;
	}
}

static void getRegionCoordinates(coordinate regionCoordinate,coordinate *surroundingCoordinates[]) {
	coordinate topleft = {regionCoordinate.row + 1,regionCoordinate.col - 1};
	coordinate topright = {regionCoordinate.row + 1,regionCoordinate.col};
	coordinate left = {regionCoordinate.row,regionCoordinate.col - 1};
	coordinate right = {regionCoordinate.row,regionCoordinate.col + 1};
	coordinate bottomleft = {regionCoordinate.row - 1,regionCoordinate.col - 1};
	coordinate bottomright = {regionCoordinate.row,regionCoordinate.col};
	*surroundingCoordinates[0] = topleft;
	*surroundingCoordinates[1] = topright;
	*surroundingCoordinates[2] = left;
	*surroundingCoordinates[3] = right;
	*surroundingCoordinates[4] = bottomleft;
	*surroundingCoordinates[5] = bottomright;
}

static void addStudent(newPlayer *player, int discipline) {
	if (discipline == 0) {
		player->ThD += 1;
	} else if (discipline == 1) {
		player->BPS += 1;
	} else if (discipline == 2) {
		player->BHW += 1;
	} else if (discipline == 3) {
		player->MJ += 1;
	} else if (discipline == 4){
		player->MTV += 1;
	} else if (discipline == 5) {
		player->MM += 1;
	} else {
		
	}
}

static void updateSurroundingRegionCoordinates(int row,int col,coordinate *surroundCoordinates[]) {
	coordinate regionCoordinate = {row,col};
	getRegionCoordinates(regionCoordinate,&surroundCoordinates);
}

static void updateValues(Game g, int diceValue) {
	int regionID = 0;
	int regionDiceValue;
	while (regionID<NUM_REGIONS) {
		regionDiceValue = getDiceValue(g,diceValue);
		if (regionDiceValue == diceValue) {
			int tempRegionCoordinate[2] = g->regionCoordinates[regionID];
			coordinate surroundCoordinates[REGION_VERTICIES];
			updateSurroundingRegionCoordinates(tempRegionCoordinate[0],tempRegionCoordinate[1],&surroundCoordinates);
			int playerIndex = 0;
			while (playerIndex < NUM_UNIS) {
				newPlayer player = (*g).players[playerIndex];
				path campuses[PATH_LIMIT] = player.campuses;
				int buildingIndex = 0;
				while (buildingIndex < player.numCampuses) {
					coordinate campusCoord = getCoordinate(campuses[buildingIndex]);
					int surroundVertexIndex = 0;
					while (surroundVertexIndex < REGION_VERTICIES) {
						int comparison = compareCoords(surroundCoordinates[surroundVertexIndex],campusCoord);
						if (comparison == TRUE) {
							addStudent(&player,regionDiceValue);
						}
						surroundVertexIndex ++;
					}
					buildingIndex ++;
				}
				playerIndex ++;
			}
		}
		regionID ++;
	}
}

static int checkPathsMemberShip(coordinate pathCoord,path paths[]) {
	int pathIndex = 0;
	int check = 0;
	while(pathIndex < PATH_LIMIT && check == 0) {
		path currentPath[PATH_LIMIT] = paths[pathIndex];
		coordinate checkingCoord = getCoordinate(currentPath);
		if (compareCoords(pathCoord,checkingCoord) == TRUE) {
			check = 1;
		}
		pathIndex ++;
	}
	return check;
}

static int compareCoords(coordinate coordOne,coordinate coordTwo) {
	return coordOne.row == coordTwo.row && coordOne.col == coordTwo.col;
}

static coordinate getCoordinate(path pathOne) {
	int pathIndex = 0;
	int flag = 0;
	coordinate coord = {0,3}; // row 0,col 3
	coordinate history[PATH_LIMIT];
	history[0] = coord;
	int currentIndex = 0;
	while (pathIndex < PATH_LIMIT && flag == 0) {
		char command = pathOne[pathIndex];
		coord = updateCoord(coord,command,&history,&currentIndex);
		pathIndex ++;
		if (command == '\0') {
			flag = 1;
		}
	}
	return coord;
}

static coordinate updateCoord(coordinate coord, char command,coordinate *history[],int *currentIndex) {
	if (coord.row % 2 == 0) {
		if (command == 'L') {
			*currentIndex += 1;
			coord.row += 1;
			*history[*currentIndex] = coord;
		} else if (command == 'R') {
			*currentIndex += 1;
			coord.col += 1;
			*history[*currentIndex] = coord;
		} else if (command == 'B') {
			*currentIndex -= 1;
		} else {
			// Invalid
		}
	} else {
		if (command == 'L') {
			*currentIndex += 1;
			coord.col -= 1;
			*history[*currentIndex] = coord;
		} else if (command == 'R') {
			*currentIndex += 1;
			coord.row += 1;
			*history[*currentIndex] = coord;
		} else if (command == 'B') {
			*currentIndex -= 1;
		} else {
			// Invalid
		}
	}
	coordinate currentCoord = *history[*currentIndex];
	return currentCoord;
}

void disposeGame(Game g) {
	free(g);
}

void makeAction(Game g, action a) {
	if (a.actionCode == PASS) {

	} else if (a.actionCode == BUILD_CAMPUS) {

	} else if (a.actionCode == BUILD_GO8) {

	} else if (a.actionCode == OBTAIN_ARC) {

	} else if (a.actionCode == START_SPINOFF) {

	} else if (a.actionCode == OBTAIN_PUBLICATION) {

	} else if (a.actionCode == OBTAIN_IP_PATENT) {

	} else if (a.actionCode == RETRAIN_STUDENTS) {

	} else {
		// Error
	}
}


void throwDice(Game g, int diceScore) {
	// Update player turns
	g->numTurn += 1;
	updateValues(g,diceScore);
}

int getDiscipline(Game g, int regionID) {
	int discipline = (*g).disciplines[regionID];
	return discipline;
}

int getDiceValue(Game g, int regionID) {
	int diceValue = (*g).diceValues[regionID];
	return diceValue;
}

int getMostARCs(Game g) {
	newPlayer player0 = g->players[0];
	newPlayer player1 = g->players[1];
	newPlayer player2 = g->players[2];

	int player0ARCs = player0.numARCGrants;
	int player1ARCs = player1.numARCGrants;
	int player2ARCs = player2.numARCGrants;

	int grants[NUM_UNIS] = {player0ARCs,player1ARCs,player2ARCs};
	int currentMax = player0ARCs;
	int maxPlayer = 0;
	int playerIndex = 0;

	while(playerIndex < NUM_UNIS) {
		if (grants[playerIndex] > currentMax) {
			maxPlayer = playerIndex;
			currentMax = grants[playerIndex];
		}
		playerIndex ++;
	}
	g->playerWithMostARCGrants = currentMax;
	return (maxPlayer + 1);
}

int getMostPublications(Game g) {
	newPlayer player0 = g->players[0];
	newPlayer player1 = g->players[1];
	newPlayer player2 = g->players[2];

	int player0Publications = player0.numPublications;
	int player1Publications = player1.numPublications;
	int player2Publications = player2.numPublications;

	int grants[NUM_UNIS] = {player0Publications,player1Publications,player2Publications};
	int currentMax = player0Publications;
	int maxPlayer = 0;
	int playerIndex = 0;

	while (playerIndex < NUM_UNIS) {
		if (grants[playerIndex] > currentMax) {
			maxPlayer = playerIndex;
			currentMax = grants[playerIndex];
		}
		playerIndex++;
	}
	g->playerWithMostPublications = currentMax;
	return (maxPlayer + 1);
}


int getTurnNumber(Game g) {
	return (*g).numTurn;
}

int getWhoseTurn(Game g) {
	int turnNumber = getTurnNumber(g);
	int player;
	if (turnNumber % 3 == 0) {
		player = UNI_A;
	} else if ((turnNumber + 1) % 3 == 0) {
		player = UNI_B;
	} else if ((turnNumber + 2) % 3 == 0) {
		player = UNI_C;
	} else {
		player = NO_ONE;
	}
	return player;
}

int getCampus(Game g, path pathToVertex) {
	coordinate pathCoord = getCoordinate(pathToVertex);
	int playerIndex = 0;
	int flag = 0;
	while(playerIndex < NUM_UNIS && flag == 0) {
		newPlayer player = (*g).players[playerIndex];
		path campuses[PATH_LIMIT] = player.campuses;
		int campusCheck = checkPathsMemberShip(pathCoord,campuses);
		path upgradedCampuses[PATH_LIMIT] = player.upgradedCampuses;
		int upgradedCampusCheck = checkPathsMemberShip(pathCoord,upgradedCampuses);
		if (campusCheck == TRUE) {
			flag = 1;
		} else if (upgradedCampusCheck == TRUE) {
			flag = 2;
		}
		playerIndex ++;
	}
	if (flag == 1) {
		return playerIndex; // Player index is incremented at the end
	} else if (flag == 2) {
		return (playerIndex + 3);
	} else {
		return VACANT_ARC;
	}
	return 1;
}

int getARC(Game g, path pathToEdge) {
	coordinate pathCoord = getCoordinate(pathToEdge);
	int playerIndex = 0;
	int flag = 0;
	while(playerIndex < NUM_UNIS && flag == 0) {
		newPlayer player = (*g).players[playerIndex];
		path arcs[PATH_LIMIT] = player.arcs;
		flag = checkPathsMemberShip(pathCoord,arcs);
		playerIndex ++;
	}
	if (flag == 1) {
		return playerIndex; // Player index is incremented at the end
	} else {
		return VACANT_ARC;
	}
	return 1;
}

int isLegalAction(Game g, action a) {
	// TODO
	return 1;
}

int getKPIpoints(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numCampuses = currentPlayer.numCampuses;
	int numGO8Campuses = currentPlayer.numGO8Campuses;
	int numARCGrants = currentPlayer.numARCGrants;
	int numIPs = currentPlayer.numIPs;
	int numPublications = currentPlayer.numPublications;
	int totalKPI = (numCampuses * 10) + (numGO8Campuses * 20)
					+ (numARCGrants * 2) + (numIPs * 10);

	if (player == g->playerWithMostARCGrants || currentPlayer.firstTimeMostARCGrants == TRUE) {
		totalKPI += 10;
		currentPlayer.firstTimeMostARCGrants == FALSE;
	}
	if (player == g->playerWithMostPublications || currentPlayer.firstTimeMostPublications == TRUE) {
		totalKPI += 10;
		currentPlayer.firstTimeMostPublications == TRUE;
	}

	return totalKPI;
}

int getARCs(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numArcs = currentPlayer.numARCGrants;
	return numArcs;
}

int getGO8s(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numGO8Campuses = currentPlayer.numGO8Campuses;
	return numGO8Campuses;
}

int getPublications(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numPublications = currentPlayer.numPublications;
	return numPublications;
}

int getIPs(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numIPs = currentPlayer.numIPs;
	return numIPs;
}

int getPublications(Game g, int player) {
	newPlayer currentPlayer = (*g).players[player];
	int numPublications = currentPlayer.numPublications;
	return numPublications;
}

int getStudents(Game g, int player, int discipline) {
	newPlayer currentPlayer = (*g).players[player];
	int numOfDiscipline;
	if (discipline == 0) {
		currentPlayer.ThD = numOfDiscipline;
	} else if (discipline == 1) {
		currentPlayer.BPS = numOfDiscipline;
	} else if (discipline == 2) {
		currentPlayer.BHW = numOfDiscipline;
	} else if (discipline == 3) {
		currentPlayer.MJ = numOfDiscipline;
	} else if (discipline == 4){
		currentPlayer.MTV = numOfDiscipline;
	} else if (discipline == 5) {
		currentPlayer.MM = numOfDiscipline;
	} else {
		// Error
	}
	return numOfDiscipline;
}


int getExchangeRate(Game g, int player, int disciplineFrom, int disciplineTo) {
	// TODO
	return 1;
}