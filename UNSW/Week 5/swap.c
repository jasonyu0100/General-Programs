#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void swap(int *first,int *second);
void tests(void);

int main(void) {
	tests();
	// int first = 5;
	// int second = 6;
	// swap(&first,&second); //Gives the pointer of first and second
	// printf("%d %d\n",first,second);
	return EXIT_SUCCESS;
}

void swap(int *first,int *second) {
	int temp = *first; //Assigns the value of pointer first 
	*first = *second; // Dereferences first and Assigns the value of pointer second to first 
	*second = temp; // Dereferences second and assigns the value of temp
}

void tests(void) {
	int first = 5;
	int second = 6;
	swap(&first,&second);
	assert(first == 6 && second == 5);
	first = 7;
	second = 8;
	swap(&first,&second);
	assert(first == 8 && second == 7);
	first = 1;
	second = 600;
	swap(&first,&second);
	assert(first == 600 && second == 1);
	printf("All test passed!\n");
}