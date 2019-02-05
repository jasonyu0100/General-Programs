// #include "pixelColor.h"
#define STEPS 36

typedef struct color {
	int red;
	int green;
	int blue;
} color;

color getColor (int steps){
	if (steps < STEPS) {
        color currentColor = {148,0,211};
        return currentColor;
    } else if (steps < STEPS * 2) {
        color currentColor = {75,0,130};
        return currentColor;
    } else if (steps < STEPS * 3) {
        color currentColor = {0,0,255};
        return currentColor;
    } else if (steps < STEPS * 4) {
        color currentColor = {0,255,0};
        return currentColor;
    } else if (steps < STEPS * 5) {
        color currentColor = {255,255,0};
        return currentColor;
    } else if (steps < STEPS * 6) {
        color currentColor = {255,127,0};
        return currentColor;
    } else {
        color currentColor = {255,0,0};
        return currentColor;
    }
}

unsigned char stepsToRed (int steps) {
	color colorGradient = getColor(steps);
	return colorGradient.red;
}

unsigned char stepsToBlue (int steps) {
	color colorGradient = getColor(steps);
	return colorGradient.blue;
}

unsigned char stepsToGreen (int steps) {
	color colorGradient = getColor(steps);
	return colorGradient.green;
}