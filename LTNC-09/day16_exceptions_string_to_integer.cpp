#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    try
    {
        int findNum = stoi(s);
        cout << findNum;
    }
    catch (invalid_argument& e)
    {
        cout << "Bad String";
    }
}

int main()
{
    string S;
    getline(cin, S);
    
    solve(S);
    
    return 0;
}
