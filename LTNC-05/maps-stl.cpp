#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    map<string, int> mp;
    
    string name;
    int mark;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            cin >> name >> mark;
            if (mp[name] != 0)
                mp[name] += mark;
            else
                mp[name] = mark;
        }
        if (k == 2)
        {
            cin >> name;
            mp[name] = 0;
        }
        if (k == 3)
        {
            cin >> name;
            cout << mp[name] << "\n";
        }
    }
    
    return 0;
}
