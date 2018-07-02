//
//  leapyear.c
//  
//
//  Created by Jason Yu on 7/3/18.
//  Checks whether or not a value is a leap year or not

/*
 Leap year program
 */
#define START_OF_GREGORIAN 1582
#include <stdio.h>
#include <assert.h>

int main(void) {
    int year;
    int flag;
    printf("Enter a year: ");
    scanf("%d",&year);
    assert(year>=START_OF_GREGORIAN);
    if (year%4 == 0) {
        if (year % 400 == 0) {
            flag = 1;
        } else if (year % 100 == 0) {
            flag = 0;
        } else {
            flag = 1;
        }
    } else {
        flag = 0;
    }
    if (flag) {
        printf("%d is a leap year!\n",year);
    } else {
        printf("%d is not a leap year!\n",year);
    }
    return 0;
}
