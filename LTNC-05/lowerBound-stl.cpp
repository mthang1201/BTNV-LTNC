#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int k;
    cin >> k;
    
    std::vector<int>::iterator low; 
    for (int i = 0; i < k; i++)
    {
        int y;
        cin >> y;
        
        low = std::lower_bound(a.begin(), a.end(), y);
        if (*low == y)
            std::cout << "Yes" << " " << (low - a.begin() + 1) << "\n";
        else
            std::cout << "No" << " " << (low - a.begin() + 1) << "\n";
    }
    return 0;
}
