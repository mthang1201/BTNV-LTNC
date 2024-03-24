#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void solve(int n)
{
    int tmp = 1;
    while (tmp <= n)
    {
        tmp *= 2;
    }
    tmp /= 2;
    
    string s;
    while (tmp > 0)
    {
        if (n >= tmp)
        {
            s += "1";
            n -= tmp;
            tmp /= 2;
        }
        else
        {
            s += "0";
            tmp /= 2;
        }
    }
    
    int maxCnt = 0;
    int cnt = 0;
    int foo;
    for (char c : s)
    {
        foo = c - '0';
        if (foo == 1)
        {
            cnt++;
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
            }
        }
        else
        {
            cnt = 0;
        }
        // cout << foo << " ";
    }
    cout << maxCnt;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    solve(n);
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
