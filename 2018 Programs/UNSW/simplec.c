#include <stdlib.h>
#include <stdio.h>

void swap(int *a,int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main(void) {
	int *array = malloc(sizeof(int) * 2);
	array[0] = 5;
	array[1] = 4;
	int i = 0;
	while (i < 2) {
		printf("%d\n",array[i]);
		i ++;
	}

	free(array);
	int value = 5;
	printf("%d\n",value);

	printf("Fibonnacci\n");
	int uptoValue;
	scanf("%d",&uptoValue);
	i = 0;
	int j = 1;
	while (i <= uptoValue) {
		printf("i is: %d\n",i);
		printf("fibonacci is: %d\n", i+j);
		i += j;
		j = i - j;
	}

	int a = 5;
	int b = 6;

	swap(&a,&b);
	printf("a: %d b: %d\n",a,b);
	int shapeSize;
	printf("Enter a shape:\n");
	scanf("%d",&shapeSize);
	printf("Shape size is %d\n",shapeSize);
	i = 0;
	j = 0;
	char symbol = '*';
	while (i < shapeSize) {
		if (i == 0 || i == (shapeSize-1)) {
			j = 0;
			while (j < shapeSize) {
				printf("%c",symbol);
				j ++;
			}
			printf("\n");
		} else {
			printf("*");
			j = 0;
			while (j < shapeSize-2) {
				printf(" ");
				j ++;
			}
			printf("*\n");
		}
		i ++;
	}
	return EXIT_SUCCESS;
}

