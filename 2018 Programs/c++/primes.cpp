#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	set<int> primeSet;
	primeSet.insert(2);
	vector<int> primes;
	primes.push_back(2);
	for (int num=3;num<1000000000;num++) {
		vector<int>::iterator p = primes.begin();
		int cap = sqrt(num) + 1;
		bool primeNumber = true; 
		while(p != primes.end()) {
			if (*p >= cap) break;
			if (num % *p == 0) {
				primeNumber = false;
				break;
			}
			p++;
		}
		if (primeNumber) {
			primes.push_back(num);
			primeSet.insert(num);
		}
	}


	int values,l,r;
	cin >> values;
	while (values--) {
		cin >> l >> r;
		vector<int>::iterator p = primes.begin();
		while(p != primes.end()) {
			if (*p > r) break;
			if (*p >= l) {
				if(primeSet.count(*p) > 0) {
					cout << *p << endl;
				}
			}
			p++;
		}
	}
}