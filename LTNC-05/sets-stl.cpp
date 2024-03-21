#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int y, x;
        cin >> y >> x;
        
        set<int>::iterator it = s.find(x);
        switch (y)
        {
            case 1:
                s.insert(x);
                break;
            case 2:
                if (it != s.end())
                    s.erase(x);
                break;
            case 3:
                if (it != s.end())
                    cout << "Yes " << "\n";
                else
                    cout << "No" << "\n";
                break;
            default:
                break;
        }
    }
    return 0;
}
