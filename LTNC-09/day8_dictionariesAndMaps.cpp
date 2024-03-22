#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    map<string,string> a;
    string name;
    string phoneNum;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> phoneNum;
        
        a[name] = phoneNum;
    }
    
    while (cin >> name)
    {
        if (a.find(name) == a.end())
            cout << "Not found" << "\n";
        else
            cout << name << "=" << a[name] << "\n";
    }
    
    return 0;
}
