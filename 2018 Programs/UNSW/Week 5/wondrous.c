#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

int printWondrous(int num);
void tests(void);

int main(void) {
    tests();
    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);
    printWondrous(num);
    return EXIT_SUCCESS;
}

int printWondrous(int num) {
    int count = 1;
    while (num != 1) {
        printf("%d ",num);
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        count ++;
    }
    printf("1\n");
    return count;
}

void tests(void) {
    assert(printWondrous(3) == 8);
}
