#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int array[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int counter = 0;
	while (counter < 15) {
		array[counter] *= array[counter];
		printf("number: %d\n",array[counter]);
		counter ++;
	}
	return EXIT_SUCCESS;
}