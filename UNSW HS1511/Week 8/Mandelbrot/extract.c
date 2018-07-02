// Functions and types used to extract x,y,z values from a string
// containing a URL of the form:
// "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"
#include "math.h"

// GENERIC
#define TRUE 1
#define FALSE 0

// URL POS
#define  ZOOMPOS 5
#define  XPOS 6
#define  YPOS 7

// ASCII Values
#define ASCII_NUMBER_START 48
#define ASCII_NUMBER_END 57
#define ASCII_NEGATIVE 45
#define ASCII_PERIOD 46
#define ASCII_FSLASH 47

#define EPSILON 1e-10

char* getSubString(char *string, int start, int end);
int charToNum(char num);
int main (int argc, char *argv[]) {

    char *message = "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp";

    triordinate dat = extract (message);

    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);

    //dat.y == -0.141 may not work since we are working with doubles
    assert (fabs(dat.y+0.141) < EPSILON);
    //dat.x == 3.14 may not work since we are working with doubles
    assert (fabs(dat.x-3.14) < EPSILON);   
    assert (dat.z == 5);
 
    //Add extra tests for extract, myAtoD and myAtoL

    return EXIT_SUCCESS;
}

triordinate extract (char *message) {
    //"http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp"
    printf("%s\n",message);
    double x = 0;
    double y = 0;
    long z = 0;
    int count = 0;
    int backSlashCount = 0;
    int startPos = 0;
    int endPos = 0;
    int currentVal = FALSE;
    while (message[count] != '\0') {
        if (message[count] == ASCII_FSLASH) {
            if (currentVal == TRUE) {
                endPos = count - 1;
                if (backSlashCount == ZOOMPOS) {
                    z = myAtoL(getSubString(message,startPos,endPos));
                } else if (backSlashCount == XPOS) {
                    x = myAtoD(getSubString(message,startPos,endPos));
                } else if (backSlashCount == YPOS) {
                    y = myAtoD(getSubString(message,startPos,endPos));
                }
                currentVal = FALSE;
            }
            backSlashCount ++;
            if (backSlashCount == XPOS) {
                startPos = count + 1;
                currentVal = TRUE;
            } else if (backSlashCount == YPOS) {
                startPos = count + 1;
                currentVal = TRUE;
            } else if (backSlashCount == ZOOMPOS) {
                startPos = count + 1;
                currentVal = TRUE;
            }
        }
        count ++;
    }
    triordinate data = {x,y,z};
    return data;
}

char* getSubString(char *string, int start, int end) {
    int count = 0;
    int size = end - start + 1;
    char *pointer = malloc(sizeof(char) * size);
    while(count < size) {
        pointer[count] = string[start + count];
        count ++;
    }
    pointer[count] = '\0';
    return pointer;
}

double myAtoD (char *message) {
    int count = 0;
    double sum = 0;
    int negative = FALSE;
    int period = FALSE;
    int decimalPlaces = 0;
    if (message[0] == '-') {
        negative = TRUE;
        count ++;
    }
    while ((message[count] != '\0') || (period != TRUE)) {
        sum *= 10;
        sum += charToNum(message[count]);
        count ++;
        if (period == TRUE) {
            decimalPlaces ++;
        }
        if (message[count] == '.') {
            period = TRUE;
            count ++;
        }
    }
    if (negative == TRUE) {
        sum *= -1;
    }
    sum /= pow(10,decimalPlaces);
    return sum;
}
 
long myAtoL (char *message) {
    int count = 0;
    long sum = 0;
    int negative = FALSE;
    if (message[0] == '-') {
        negative = TRUE;
        count ++;
    }
    while (message[count] != '\0') {
        sum *= 10;
        sum += charToNum(message[count]);
        count ++;
    }
    if (negative == TRUE) {
        sum *= -1;
    }
    return sum;
}

int charToNum(char num) {
    return num - ASCII_NUMBER_START;
}