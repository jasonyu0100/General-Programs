/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by JASON YU
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

// Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Days of Week as NUM
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6
// Months in Year as NUM
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12
// Month Lengths
#define SHORTM 30
#define LONGM 31
#define FEBM 28
// Cummulative Days by the start of Month (Non-Leap-Year)
#define CJAN 0
#define CFEB LONGM+CJAN
#define CMAR FEBM+CFEB
#define CAPR LONGM+CMAR
#define CMAY SHORTM+CAPR
#define CJUN LONGM+CMAY
#define CJUL SHORTM+CJUN
#define CAUG LONGM+CJUL
#define CSEP LONGM+CAUG
#define COCT SHORTM+CSEP
#define CNOV LONGM+COCT
#define CDEC SHORTM+CNOV
// Booleans
#define TRUE 1
#define FALSE 0
// Days in a Week
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);
int getCummulativeDays(int month, int day);
void tests(void);

int main (int argc, char *argv[]) {
    //Unit tests
    tests();
    return EXIT_SUCCESS;
}

void tests(void) {
    /*Testing method is against all unit tests with my own unit test at bottom
      All tests have passed with no errors
     */
    
    // Simple Tests
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  8, 31) == FRIDAY);
    
    // 2017 cohort:
    assert (dayOfWeek (TUESDAY  ,  TRUE,  8, 18) == FRIDAY);   // Stanley Su
    assert (dayOfWeek (MONDAY   ,  TRUE,  1,  1) == FRIDAY);   // Alex Huang
    assert (dayOfWeek (TUESDAY  ,  TRUE,  2, 28) == MONDAY);   // Felicia Ee
    assert (dayOfWeek (SATURDAY , FALSE,  1,  2) == FRIDAY);   // Maksim Lisau
    assert (dayOfWeek (SATURDAY , FALSE,  3, 15) == SUNDAY);   // Angeni Bai
    assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Alex Tan
    assert (dayOfWeek (MONDAY   ,  TRUE,  1,  9) == SATURDAY); // Luke Fisk-Lennon
    assert (dayOfWeek (THURSDAY ,  TRUE,  2, 29) == THURSDAY); // Jarrod Li
    assert (dayOfWeek (FRIDAY   ,  TRUE,  1,  3) == THURSDAY); // Mirela Tomicic
    assert (dayOfWeek (TUESDAY  , FALSE,  3, 16) == THURSDAY); // Andrew Yu
    assert (dayOfWeek (SUNDAY   , FALSE,  7, 11) == SUNDAY);   // Samuel Hagan
    assert (dayOfWeek (TUESDAY  , FALSE,  4,  6) == THURSDAY); // Tracey Chiu
    assert (dayOfWeek (MONDAY   ,  TRUE, 12, 31) == SATURDAY); // Andrew Timkov
    assert (dayOfWeek (TUESDAY  , FALSE, 12, 25) == MONDAY);   // Matthew Darley
    assert (dayOfWeek (TUESDAY  , FALSE, 12,  5) == TUESDAY);  // Nicholas Austen
    assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Christina Shi
    assert (dayOfWeek (MONDAY   , FALSE,  8, 10) == WEDNESDAY);// Noa Challis
    assert (dayOfWeek (FRIDAY   ,  TRUE, 11, 24) == MONDAY);   // Evan Lee
    assert (dayOfWeek (WEDNESDAY,  TRUE,  2, 29) == WEDNESDAY);// Callum Predavec
    assert (dayOfWeek (TUESDAY  , FALSE, 11, 11) == SATURDAY); // Joel Perry
    assert (dayOfWeek (SATURDAY , FALSE,  3,  1) == SUNDAY);   // Phoebe Zuo
    assert (dayOfWeek (MONDAY   , FALSE,  2, 25) == FRIDAY);   // Sebastien Higgs
    assert (dayOfWeek (TUESDAY  , FALSE,  3, 25) == SATURDAY); // Nicholas Patrikeos
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) == TUESDAY);  // Rahul Kumar
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != MONDAY);   // Roman Ozerski
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != THURSDAY); // Dylan Stephens
    assert (dayOfWeek (TUESDAY  , FALSE, 12,  4) == MONDAY);   // Lucas Barbosa :)
    assert (dayOfWeek (WEDNESDAY,  TRUE,  1,  4) == WEDNESDAY);// Eddie Qi
    assert (dayOfWeek (TUESDAY  , FALSE,  7, 12) == WEDNESDAY);// Jason Hidajat
    assert (dayOfWeek (TUESDAY , TRUE, 4, 4) == TUESDAY);      // Charlotte Low
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  1) == MONDAY);   // Tim Lee
    assert (dayOfWeek (MONDAY   ,  TRUE, 12, 25) == SUNDAY);   // George Flabouris
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // 28/02/1972 (Jack Jiang)
    assert (dayOfWeek (TUESDAY  , FALSE,  7,  1) == SATURDAY); // Kevin Yan
    assert (dayOfWeek (THURSDAY, FALSE, 4, 5) == FRIDAY);      // Archie Croston
    assert (dayOfWeek (SUNDAY  , FALSE, 7, 12) != FRIDAY);     // Chris Law
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 19) ==
            dayOfWeek (WEDNESDAY, TRUE, 12, 19) );             // Marcus Handley
    assert (dayOfWeek (THURSDAY, FALSE, 4, 2) == TUESDAY);     // Callum Koh (2017)
    
    // 2018 cohort:
    assert (dayOfWeek (THURSDAY, FALSE, 1, 2) == WEDNESDAY);   // Paul Lapinski
    assert (dayOfWeek (TUESDAY, TRUE, 2, 27) == SUNDAY);       // Paul Lapinski
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Paul Lapinski
    assert (dayOfWeek (THURSDAY, TRUE, 2, 2) ==
            dayOfWeek (WEDNESDAY, FALSE, 2, 2));               // Tom Harrison-Brown
    assert (dayOfWeek (MONDAY, TRUE, 8, 1) == MONDAY);         // Tom Harrison-Brown
    assert (dayOfWeek (SATURDAY, FALSE, 1, 21) == WEDNESDAY);  // Jennivine Chen
    assert (dayOfWeek (SUNDAY   , TRUE, 1, 4) == SUNDAY);      // Kai Mashimo
    assert (dayOfWeek (WEDNESDAY, FALSE, 8, 23) == THURSDAY);  // Lily Yang
    assert (dayOfWeek (MONDAY, TRUE, 2, 27) != MONDAY);        // Joshua Quail :P
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 8) == MONDAY);    // Luke Cantor
    assert (dayOfWeek (SUNDAY, TRUE, 12, 14) == TUESDAY);      // Dillon de Silva XD
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 31) == MONDAY);   // Izaac Coffey
    assert (dayOfWeek (MONDAY, TRUE, 1, 1) == FRIDAY);         // James Wilkie
    assert (dayOfWeek (WEDNESDAY, FALSE, 11, 9) == FRIDAY);    // Darby Thompson
    assert (dayOfWeek (WEDNESDAY, FALSE, 1, 29) == MONDAY);    // Reilly Fox
    assert (dayOfWeek (FRIDAY, FALSE, 8, 12) == TUESDAY);      // Lucca Harvey
    assert (dayOfWeek (TUESDAY, TRUE, 4, 20) == THURSDAY);     // Callum Koh (2018) ;)
    assert (dayOfWeek (THURSDAY, FALSE, 1, 1) == TUESDAY);     // Harold Chin
    assert (dayOfWeek (WEDNESDAY, TRUE, 3, 14) == WEDNESDAY);  // Luke Cantor (pi day)
    assert (dayOfWeek (FRIDAY, TRUE, 3, 0) == FRIDAY);         // Josh Harcombe
    assert (dayOfWeek (THURSDAY, TRUE, 6, 6) == THURSDAY);     // Sophie Ogilvy
    assert (dayOfWeek (FRIDAY, FALSE, 12, 12) == FRIDAY);      // James Balajan
    assert (dayOfWeek (WEDNESDAY, FALSE, 8, 26) == SUNDAY);    // Tay your bae
    assert (dayOfWeek (TUESDAY, TRUE, 5, 27) == SATURDAY);     // Allan Goodman
    assert (dayOfWeek (FRIDAY, FALSE, 3, 26) == WEDNESDAY);    // Eric R Chang
    assert (dayOfWeek (MONDAY, FALSE, 6, 27) == MONDAY);       // Patrick Fennell
    assert (dayOfWeek (TUESDAY, TRUE, 8, 23) == WEDNESDAY);    // Harris Borman (You forgot a parenthesis!)
    assert (dayOfWeek (SATURDAY, TRUE, 5, 13) == WEDNESDAY);   // Luka Lafaye de Micheaux
    assert (dayOfWeek (SATURDAY, TRUE, 10, 9) == FRIDAY);      // Luka Lafaye de Micheaux
    assert (dayOfWeek (TUESDAY, FALSE,  3, 4) == SATURDAY);    // Zachary Cheng
    assert (dayOfWeek (THURSDAY, FALSE, 7, 2) == TUESDAY);     // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 2) == TUESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (THURSDAY, FALSE, 11, 0) == THURSDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 4) == TUESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (THURSDAY, FALSE, 5, 1) == WEDNESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (MONDAY, FALSE, 3, 10) == THURSDAY);     // Sam McKay
    assert (dayOfWeek (FRIDAY, TRUE, 1, 20) == SUNDAY);        // Sam McKay
    assert (dayOfWeek (FRIDAY, TRUE, 4, 4) == FRIDAY);         // Josh Green: Ensuring LeapYear Doesn't throw off
    assert (dayOfWeek (MONDAY, TRUE, 12, 12) == MONDAY);       // Josh Green: same as above
    assert (dayOfWeek (SUNDAY, FALSE, 4, 5) == MONDAY);        // Josh Green above
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 11) == TUESDAY);  // Josh Green below
    assert (dayOfWeek (THURSDAY, FALSE, 6, 14) == FRIDAY);     // Jessica Luo
    assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);    // Laeeque Jamdar
    assert (dayOfWeek (SATURDAY, TRUE, 12, 30) == WEDNESDAY);  // Jason Yu
    // Personal Test Case above
    printf ("All tests passed - You are awesome!\n");
}


/*
 given the doomsday for a year, and whether or not it is a
 leap year, this function return the day of the week for any
 given month and day in the year.
 
 Summary:
 Program first finds the cummulative amount of days that has past since New Year's Day.
 Cummulative days is found by adding up all the months up to the current month and then adding days.
 Further checks are made for leap year special cases.
 Difference is found that and last day of February which is a Doomsday
 From difference, difference in days is extrapolated
 From difference in days, day of week is found
 */

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int originDay = CMAR; 
    // Doomsday is on the last day of February 28 or 29 (Leap Year)
    int counter = getCummulativeDays(month,day);
    // Number of days past from start of year
    if (leapYear == TRUE) {
        if (month > 2) {
            counter += 1;
            // After February on Leap; add one
        }
        // Doomsday is last day of February
        originDay += 1;
    }
    int totalDifference = counter - originDay;
    // Total amount difference
    int dayDifference;
    // Total difference in days (Between 0-6)
    int dayOfWeek;
    if (totalDifference < 1) {
        // If difference < 1, date is before last day of February
        totalDifference *= -1;
        dayDifference = (DAYS_PER_WEEK) - (totalDifference % 7);
    } else {
        dayDifference = totalDifference % 7;
    }
    
    dayOfWeek = ((doomsday + dayDifference) % 7);
    return (dayOfWeek);
}

int getCummulativeDays(int month, int day) {
    // Get the cummulative days past since the start of the year
    int counter = 0;
    if (month == JAN) {
        counter += (CJAN + day);
    } else if (month == FEB) {
        counter += (CFEB + day);
    } else if (month == MAR) {
        counter += (CMAR + day);
    } else if (month == APR) {
        counter += (CAPR + day);
    } else if (month == MAY) {
        counter += (CMAY + day);
    } else if (month == JUN) {
        counter += (CJUN + day);
    } else if (month == JUL) {
        counter += (CJUL + day);
    } else if (month == AUG) {
        counter += (CAUG + day);
    } else if (month == SEP) {
        counter += (CSEP + day);
    } else if (month == OCT) {
        counter += (COCT + day);
    } else if (month == NOV) {
        counter += (CNOV + day);
    } else if (month == DEC) {
        counter += (CDEC + day);
    }
    return counter;
}
        



