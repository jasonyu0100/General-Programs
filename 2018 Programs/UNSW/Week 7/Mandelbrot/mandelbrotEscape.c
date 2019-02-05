#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mandelbrot.h"
#define MAX_VALUE 2
#define MAX_STEPS 256

typedef struct imaginaryPoint {
    double real;
    double imaginary;
} imaginaryPoint;

double calculateDistance(imaginaryPoint point);
imaginaryPoint iteratePoint(imaginaryPoint previous, imaginaryPoint current);
imaginaryPoint addPoints(imaginaryPoint pointOne, imaginaryPoint pointTwo);
imaginaryPoint squarePoint(imaginaryPoint point);

int escapeSteps(double x, double y) {
    int steps = 0;
    // Previous point 
    imaginaryPoint previous = {0,0};
    // Current Point
    imaginaryPoint current = {x,y};
    double distance = 0;
    while (distance < MAX_VALUE && steps < MAX_STEPS) {
        previous = iteratePoint(previous,current);
        distance = calculateDistance(previous);
        steps += 1;
    }
    return steps;
}

imaginaryPoint iteratePoint(imaginaryPoint previous, imaginaryPoint current) {
    // z = z^2 + c
    imaginaryPoint squaredPrevious =  squarePoint(previous);
    imaginaryPoint sum = addPoints(squaredPrevious,current);
    return sum;
}

imaginaryPoint addPoints(imaginaryPoint pointOne, imaginaryPoint pointTwo) {
    double newReal = pointOne.real + pointTwo.real;
    double newImaginary = pointOne.imaginary + pointTwo.imaginary;
    imaginaryPointnewPoint = {newReal,newImaginary};
    return newPoint;
} 

imaginaryPoint squarePoint(imaginaryPoint point) {
    double real = point.real;
    double imaginary = point.imaginary;
    // (a + ib)(c + id) = ac + iad + ibc + (i*i)(bd)
    //                  = ac - bd + i(ad + bc)
    double newReal = pow(real,2) - pow(imaginary,2);
    double newImaginary = 2 * (real * imaginary);
    imaginaryPoint newPoint = {newReal,newImaginary};
    return newPoint;
}

double calculateDistance(imaginaryPoint point) {
    double x = point.real;
    double y = point.imaginary;
    double distance = sqrt(x * x + y * y);
    return distance;
}

