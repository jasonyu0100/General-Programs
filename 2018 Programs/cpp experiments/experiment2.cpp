#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;
// Compile g++ -std=c++11 -o experiment experiment2.cpp

int main() {
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(8);
    vector<int>::iterator itr = vec.begin();
    while(itr != vec.end()) {
        cout << *itr << endl;
        itr ++;
    }

    set<int> myset = {2,4,5,1,9};
    set<int>::iterator setItr = myset.find(2);
    if (setItr != myset.end()) {
        cout << *setItr << endl;
    } else {
        cout << "Not found!" << endl;
    }

    for_each(myset.begin(),myset.end(),[](int x) {cout << x;});

    
    return 1;
}

