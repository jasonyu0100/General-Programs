#include <stdlib.h>
#include <stdio.h>

void showDanish(void);

int main(void) {
    showDanish();
    return EXIT_SUCCESS;
}

void showDanish(void) {
    int count = 0;
    while (count < 5) {
        if (count == 2) {
            printf("\n");
        } else {
            int num = 0;
            while (num < 12) {
                if (num == 2) {
                    printf(" ");
                } else {
                    printf("*");
                }
                num ++;
            }
            printf("\n");
        }
        count ++;
    }
}