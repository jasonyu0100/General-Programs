#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;



int main() {
	int left,right;
	cin >> left >> right;
	int maxVal = 1000001;
	bool notPrimes[maxVal];
	for (int a=0;a<maxVal;a++) {
		notPrimes[a] = false;
	}
	notPrimes[0] = true;
	notPrimes[1] = true;
	int prime = 2;
	int cap = sqrt(maxVal) + 1;
	while (prime <= cap) {
		if (notPrimes[prime] == false) {
			for (int i=2;(prime*i)<=maxVal;i+=1) {
				notPrimes[prime*i] = true;
			}
		}
		prime ++;
	}

	for (int i=left;i<=right;i++) {
		if (notPrimes[i] == false) {
			cout << i << endl;
		}
	}
}