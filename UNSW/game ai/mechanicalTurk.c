/*
 *  Mr Pass.  Brain the size of a planet!
 *
 *  Proundly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *
 */

/*
Getting Resources
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

typedef struct _resources {
	int ThD;
	int BPS;
	int BHW;
	int MJ;
	int MTV;
	int MM;
} resources;

action decideAction (Game g) {
    //Requirements MJ MTV M$
    coordinate regionCoordinates[19];
    setRegionCoordinates(regionCoordinates); // Sets the region centres of the value

    int currentPlayer = getWhoseTurn(g);
    resources currentResourceCount = getResources(currentPlayer);
    action nextAction;

    int campusBool = campusResourceCheck(currentResourceCount);
    int arcBool = arcResourceCheck(currentResourceCount);
    int spinOffBool = spinOffResourceCheck(currentResourceCount);
    int GO8Bool = GO8ResourceCheck(currentResourceCount);


    int flag = 0;
    if (campusBool == TRUE && flag == 0) {
    	nextAction.actionCode = BUILD_CAMPUS
    	path chosenPath; 
    	chooseCampusLocation(g,regionCoordinates,&flag,nextAction,chosenPath);
    	if (flag == 0) {
    		nextAction.destination = chosenPath;
    	}
    } if (GO8Bool == TRUE && flag == 0) {
    	nextAction.actionCode = BUILD_GO8
    	path chosenPath;
    	chooseGO8Location(g,regionCoordinates,currentPlayer,&flag,nextAction,chosenPath);
    	if (flag == 0) {
    		nextAction.destination = chosenPath;
    	}
    } if (arcBool == TRUE && flag == 0) {
    	nextAction.actionCode = OBTAIN_ARC;
    	path chosenPath;
    	chooseArcLocation(g,regionCoordinates,currentPlayer,&flag,nextAction,chosenPath);
    	if (flag == 0) {
    		nextAction.destination = chosenPath;
    	}
    } if (spinOffBool == TRUE && flag == 0) {
    	nextAction.actionCode = START_SPINOFF;
    	flag = 1;
    } if (flag == 0) {
    	nextAction.actionCode = PASS;
    }

    return nextAction;
}



// Coordinate Functions 
typedef struct _coordinate {
	int row;
	int col;
} coordinate;

static void setRegionCoordinates(coordinate regionCoordinates[]) {
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
		coordinate regionCoordinate = {regionCoordinates[count][0],regionCoordinates[count][1]};
		regionCoordinates[count] = regionCoordiante;
		count ++;
	}
}

static void getRegionCoordinates(coordinate regionCoordinate,coordinate surroundingCoordinates[]) {
	coordinate topleft = {regionCoordinate.row + 1,regionCoordinate.col - 1};
	coordinate topright = {regionCoordinate.row + 1,regionCoordinate.col};
	coordinate left = {regionCoordinate.row,regionCoordinate.col - 1};
	coordinate right = {regionCoordinate.row,regionCoordinate.col + 1};
	coordinate bottomleft = {regionCoordinate.row - 1,regionCoordinate.col - 1};
	coordinate bottomright = {regionCoordinate.row,regionCoordinate.col};
	surroundingCoordinates[0] = topleft;
	surroundingCoordinates[1] = topright;
	surroundingCoordinates[2] = left;
	surroundingCoordinates[3] = right;
	surroundingCoordinates[4] = bottomleft;
	surroundingCoordinates[5] = bottomright;
}

static int compareCoords(coordinate coordOne,coordinate coordTwo) {
	return coordOne.row == coordTwo.row && coordOne.col == coordTwo.col;
}

void getPathFromCoordinate(coordinate targetCoordinate, path currentPath) {
	coordinate coord = {0,3};
	int currentPathIndex = 0;
	while (coord.row < targetCoordinate.row) {
		// printf("%d\n",currentPathIndex);
		if (coord.row % 2 == 0) {
			coord.row += 1;
			currentPath[currentPathIndex] = 'L';
		} else {
			coord.row += 1;
			currentPath[currentPathIndex] = 'R';
		}
		currentPathIndex ++;
	}
	int flag = 0;
	while (flag == 0) {
		if (coord.col < targetCoordinate.col) {
			if (coord.col % 2 == 0) {
				currentPath[currentPathIndex] = 'R';
				currentPathIndex ++;
				coord.col += 1;
			}
			currentPath[currentPathIndex] = 'R';
			currentPathIndex ++;
			currentPath[currentPathIndex] = 'R';
			currentPathIndex ++;
			currentPath[currentPathIndex] = 'R';
			currentPathIndex ++;
			coord.col += 2;
		} else if (coord.col > targetCoordinate.col) {
			if (coord.col % 2 == 1) {
				currentPath[currentPathIndex] = 'L';
				currentPathIndex ++;
				coord.col -= 1;
			}
			currentPath[currentPathIndex] = 'L';
			currentPathIndex ++;
			currentPath[currentPathIndex] = 'L';
			currentPathIndex ++;
			currentPath[currentPathIndex] = 'L';
			currentPathIndex ++;
			coord.col -= 2;
		} else {
			flag = 1;
		}
	}
}

resources getResources(int currentPlayer) {
	resources currentResourceCount;
    playerResources.ThD = getStudents(g, currentPlayer, STUDENT_THD);
    playerResources.BPS = getStudents(g, currentPlayer, STUDENT_BPS);
    playerResources.BHW = getStudents(g, currentPlayer, STUDENT_BQN);
    playerResources.MJ = getStudents(g, currentPlayer, STUDENT_MJ);
    playerResources.MTV = getStudents(g, currentPlayer, STUDENT_MTV);
    playerResources.MM = getStudents(g, currentPlayer, STUDENT_MMONEY);
    return currentResourceCount
}

int spinOffResourceCheck(Game g) {
	if (currentResourceCount.MJ > 0 && currentResourceCount.MTV > 0 && currentResourceCount.MM > 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int campusResourceCheck(currentResourceCount) {
	if (currentResourceCount.BPS > 0 && currentResourceCount.BHW > 0 && currentResourceCount.MJ > 0 && currentResourceCount.MTV > 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int arcResourceCheck(Game g) {
	if (currentResourceCount.BHW > 0 && currentResourceCount.BPS > 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int GO8ResourceCheck(Game g) {
	if (currentResourceCount.MJ > 1 && currentResourceCount.MM > 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int bestRegion(Game g, int takenRegions[]) {
	int ratings[19] = {0};
	int regionIndex = 0;
	int currentMaxRating = 0;
	int currentBestRegion = 0;
	int discipline;
	int diceValue;
	int rating;
	while (regionIndex < 19) {
		discipline = getDiscipline(g,regionIndex);
		diceValue = getDiceValue(g,regionIndex);
		rating = rateRegion(discipline,diceValue);
		int checkRegionIndex = 0;
		int flag = 0;
		while (checkRegionIndex < 19 && flag == 1) {
			if (takenRegions[regionIndex] == 1) {
				flag = 1;
			}
			checkRegionIndex++;
		}

		if (rating > currentMaxRating && flag == 0) {
			currentMaxRating = rating;
			currentBestRegion = regionIndex;
		}
		regionIndex ++:
	}
	return currentBestRegion;
}

int rateRegion(int discipline, int diceValue) {
	int disciplineRating[6] = [1,2,3,6,4,5]; // Rating for each discipline
	int disciplineScore = disciplineRating[discipline];

	// Dice score absolute value
	int diceScore = 6 - (diceValue - 6);
	if (diceScore < 0) {
		diceScore *= -1;
	}
	
	int totalScore = diceScore + disciplineScore;
	return totalScore;
}

int getPathSize(path givenPath) {
	int index = 0;
	while (index < PATH_LIMIT) {
		char value = givenPath[index];
		if (value != 'R' || value != 'L') {
			return index;
		}
		index++;
	}
}

path chooseArcLocation(Game g,int regionCoordinates[][],int currentPlayer,int *flag,action currentAction,path chosenPath) {
	int regionID = 0;
	while (regionID < 19) {
		coordinate regionCoordinate = {regionCoordinates[regionID][0],regionCoordinates[regionID][1]};
		coordinate surroundingCoordinates[6];
		getRegionCoordinates(regionCoordinate,surroundingCoordinates);
		int surroundingCoordinateIndex = 0;
		// Checks coordinates around regions
		while (surroundingCoordinateIndex < 6) {
			coordinate currentCoord = surroundingCoordinates[surroundingCoordinateIndex];
			path currentCoordPath;
			getPathFromCoordinate(currentCoord,currentCoordPath);
			int value = getARC(g,currentCoordPath); // Gets arc
			int size = getPathSize(currentCoordPath);

			// Checks if paths around coordinate are valid
			if (value == currentPlayer) {
				currentCoordPath[size] = 'L';
				currentAction.destination = currentCoordPath;
				if (isLegalAction(g,currentAction) == 1) {
					return currentCoordPath
				}

				currentCoordPath[size] = 'R';
				currentAction.destination = currentCoordPath;
				if (isLegalAction(g,currentAction) == 1) {
					return currentCoordPath
				}
			}

			surroundingCoordinateIndex++;
		}
		regionID ++;
	}

	// No Campuses to upgrade
	path placeHolderPath = {0,0};
	return placeHolderPath;
}

path chooseCampusLocation(Game g,int regionCoordinates[][],int *flag,action currentAction,path chosenPath) {
	// Find a campus location to settle at
	int takenRegions[19] = {0};
	int attemptNumber = 0;
	while (attemptNumber < 19) {
		// Gets the best region based on taken regions so far
		int bestRegionID = bestRegion(g,takenRegions);
		coordinate regionCoordinate = {regionCoordinate[bestRegionID][1],regionCoordinate[bestRegionID][2]}
		coordinate surroundingCoordinates[6];
		// Updates surrounding region coordinates
		getRegionCoordinates(bestRegionID,surroundingCoordinates);
		int surroundingCoordinateIndex = 0;
		while(surroundingCoordinateIndex < 6) {
			coordinate currentCoord = surroundingCoordinates[surroundingCoordinateIndex];
			path coordToPath;
			getPathFromCoordinate(chosenCoordinate,coordToPath);
			int value = getCampus(g,coordToPath);
			currentAction.destination = coordToPath;
			if (value == 0 && isLegalAction(g,currentAction) == 1) { // Vacant Vertex
				*flag = 1;
				return coordToPath;
			}
			surroundingCoordinateIndex ++;
		}
		takenRegions[bestRegionID] = 1; // Show that the region is taken
		attemptNumber ++;
	}

	// Return if unsuccessful
	path placeHolderPath = {0,0};
	return placeHolderPath;
}

path chooseGO8Location(Game g,int regionCoordinates[][],int currentPlayer,int *flag,action currentAction,path chosenPath) {
	int regionID = 0;
	while (regionID < 19) {
		coordinate regionCoordinate = {regionCoordinates[regionID][0],regionCoordinates[regionID][1]};
		coordinate surroundingCoordinates[6];
		// Updates Surrounding Regions Coordinates
		getRegionCoordinates(regionCoordinate,surroundingCoordinates);

		// Checks all surrounding region coordinates for all regioons in order of importance
		int surroundingCoordinateIndex = 0;
		while (surroundingCoordinateIndex < 6) {
			// Checks each coordinate and sees if is valid
			coordinate currentCoord = surroundingCoordinates[surroundingCoordinateIndex];
			path currentCoordPath;
			getPathFromCoordinate(currentCoord,currentCoordPath);
			int value = getCampus(g,currentCoordPath); // Gets arc
			currentAction.destination = currentCoordPath;
			if (value == currentPlayer && isLegalAction(g,currentAction) == 1) {
				*flag = 1;
				return currentCoordPath;
			}
			surroundingCoordinateIndex++;
		}
		regionID ++;
	}

	// Return if unsuccessful
	path placeHolderPath = {0,0};
	return placeHolderPath;
}
