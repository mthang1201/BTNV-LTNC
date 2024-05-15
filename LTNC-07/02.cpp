#include <bits/stdc++.h>
using namespace std;

vector<char> mySet = {'a', 'b', 'c', 'd'};

void generateChars(string s1, int length) {
    string str;
    
    if (length == (int)mySet.size()) {
        cout << s1 << endl;
        return;
    }
    
    for (int i = 0; i < (int)mySet.size(); i++) {
        str = s1 + mySet[i];
        if (length < (int)mySet.size()) {
            generateChars(str, length + 1);
        }
    }
    
}

int main() {
    string s1;
    generateChars(s1, 1);
    
    return 0;
}
