#include <iostream>
using namespace std;

int main(void) {
	double array[4] = {1,2,3,4};
	int i = 0;
	do {
		cout << array[i] << endl;
		i ++;
	} while (i != 3);
}