#define RANGE 64
#include <math.h>

typedef struct color {
	int red;
	int green;
	int blue;
} color;

color gradient (double mult,color colorone, color colortwo);

color getColor (int steps){
	color colorGradient;
	double mult = (steps % RANGE);
	mult /= RANGE;
	mult = pow(mult,3);
	color one    = {0, 0, 50};
	color two    = {0, 0, 200};
	color three  = {0, 255, 255};
	color four   = {0, 255, 160};
	color five   = {255, 255, 255};

	if(0 <= steps && steps <= 64) {
		colorGradient = gradient(mult, one, two);
	} else if(64 <= steps && steps <= 128) {
		colorGradient = gradient(mult, two, three);
	} else if(128 <= steps && steps <= 192) {
		colorGradient = gradient(mult, three, four);
	} else {
		colorGradient = gradient(mult, four, five);
	}
	return colorGradient;
}

unsigned char stepsToRed (int steps) {
	color colorGradient =  getColor(steps);
	return colorGradient.red;
}

unsigned char stepsToBlue (int steps) {
	color colorGradient =  getColor(steps);
	return colorGradient.blue;
}

unsigned char stepsToGreen (int steps) {
	color colorGradient =  getColor(steps);
	return colorGradient.green;
}


color gradient (double mult,color colorone, color colortwo){
	int differenceRed = (colortwo.red - colorone.red) * mult;
	int differenceGreen = (colortwo.green - colorone.green) * mult;
	int differenceBlue = (colortwo.blue - colorone.blue) * mult;

	int newred = colorone.red + differenceRed;
	int newgreen = colorone.green + differenceGreen;
	int newblue = colorone.blue + differenceBlue;

	color newcolor = {newred, newgreen, newblue}; 

	return newcolor;
}