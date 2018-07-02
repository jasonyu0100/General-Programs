#include <iostream>
#include <cstdlib>

using namespace std;

class Box
{
public:
	double length;
	double height;
	double width;
};

void setBoxValues(Box *box,double length,double height,double width);
void displayBox(Box box);

int main() {
	Box Box1;
	Box Box2;
	setBoxValues(&Box1,1,2,3);
	displayBox(Box1);

}

void setBoxValues(Box *box,double length,double height,double width) {
	box->length =length;
	box->width = width;
	box->height = height;
}

void displayBox(Box box) {
	cout << box.length << box.width << box.height << endl;
}