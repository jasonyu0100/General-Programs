#include <iostream>
using namespace std;
int main(void) {
	int value = 5;
	switch(value) {
		case 5:
			cout << "true" << endl;
			break;
		default:
			cout << "false";

	}

	int a = 5;
	int b =  a%2==0 ? 10 : 11;
	cout << a << "afds" << b << endl;
	return 0;
}