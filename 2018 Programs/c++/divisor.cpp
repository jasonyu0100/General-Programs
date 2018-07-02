#include <iostream>
using namespace std;

int main() {
	int numInputs;
	cin >> numInputs;
	int first;
	int second;
	while(numInputs--) {
		cin >> first >> second;
		while (first <= second) {
			int divisor = 2;
			while (divisor < first) {
				if (first % divisor == 0) {
					break;
				}
				divisor ++;
			}
			if (divisor == first) {
				cout << first << endl;
			}
			first ++;
		}
		cout << endl;
	}
	return 0;
}