// program demonstrating the use if
// statements in c
// unsw computing 1, week 2
// comp19117.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPermutations();
int danishFlag();

int main() {
    char string[] = "";
    char finalString[];
    strcat(string,"4");
    printf("%s",string);
    //findPermutations();
    findPermutations();
    return EXIT_SUCCESS;
}

int danishFlag (int first, int second) {
    //char string[] = "";
    if (first > 7) {
        printf ("Danish\n");
        if (second < 3) {
            
            printf ("happy");
        }
    } else {
        if (second > 8) {
            
            printf ("Dan");
        } else if (second > 4) {
            printf ("Sally");
        } else {
            // print nothing
        }
    }
    
    if (second < 10) {
        printf ("ish\n");
    }
    
    if (first > second) {
        printf ("\nFlag\n");
    } else {
        printf ("Flag\n");
    }
    
    return EXIT_SUCCESS;
}

int findPermutations() {
    for (int i = 0; i < 12; i ++) {
        for (int j =0; j < 12; j ++) {
            danishFlag(i,j);
        }
    }
    return 0;
}
