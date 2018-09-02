#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    string name;
    int indexLetterCount;
    in >> name;
    vector <set<char> > allowedIndexLetters;
    in >> indexLetterCount;
    int index;
    string allowedLetterString;
    for (int i=0;i<indexLetterCount;i++){
        allowedIndexLetters.push_back(set <char> ());
    }

    for (int i=0;i<indexLetterCount;i++){
        in >> index >> allowedLetterString;
        index -= 1;
        set<char> allowedLetters;
        for (char letter : allowedLetterString) {
            allowedLetters.insert(letter);
        }
        allowedIndexLetters.push_back(allowedLetters);
    }
    char currentNameArray[name.length()];
    for (int i=0;i<name.length();i++) {
        currentNameArray[i] = name[i];
    }
    int arrayLength = name.length();
    for (int i=0;i<arrayLength;i++) {
        set<char> letters = allowedIndexLetters[i];
    }
    in.close();
    out.close();
    return 1;
}