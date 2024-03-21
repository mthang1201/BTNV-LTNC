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
    
    int sumA = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sumA += a[i];
    }

    int sumB = 0;
    vector<int> b(n+1);
    for (int i = 0; i < n+1; i++)
    {
        cin >> b[i];
        sumB += b[i];
    }
    cout << (sumB-sumA);
    return 0;
}
