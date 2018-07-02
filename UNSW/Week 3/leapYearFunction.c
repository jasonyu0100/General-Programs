//
//  isLeapYear.c
//  
//
//  Created by Jason Yu on 7/3/18.
//  Function that checks whether a year is a leapyear or not
/* Test cases
 isLeapYear(2000) = 1
 isLeapYear(2012) = 1
 isLeapYear(2013) = 0
 isLeapYear(1800) = 0
 isLeapYear(230000) = 0
 isLeapYear(100004) = 1
*/
#define START_OF_GREGORIAN 1582
#include <assert.h>
#include <stdio.h>

int isLeapYear();

int main(void) {
    int input;
    printf("Enter a year:\n");
    scanf("%d", &input);
    printf("%d",isLeapYear(input));
    return 0;
}

int isLeapYear (int year) {
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            return 1;
        } else if (year % 100 == 0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}


