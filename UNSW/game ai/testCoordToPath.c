#include <stdio.h>
#include <stdlib.h>

typedef char path[150];
typedef struct coordinate {
	int row;
	int col;
} coordinate;

void getPathFromCoordinate(coordinate targetCoordinate,path currentPath);

int main(void) {
	coordinate currentCoordinate = {5,0};
	path currentPath;
	getPathFromCoordinate(currentCoordinate,currentPath);
	int counter = 0;
	while (counter < 20) {
		printf("%c\n",currentPath[counter]);
		counter ++;
	}
	return 1;
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