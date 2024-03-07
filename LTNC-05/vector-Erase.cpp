#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n; vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int x; cin >> x;
    A.erase(A.begin() + (x - 1));
    int a, b; cin >> a >> b;
    A.erase(A.begin() + (a - 1), A.begin() + b - 1);
    cout << A.size() << endl;
    for (int num : A) {
        cout << num << " ";
    }
    
    return 0;
}
