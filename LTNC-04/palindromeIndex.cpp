#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
bool check(string s)
{
    int len = s.size();
    for (int i = 0; i < len/2; i++)
    {
        if (s[i] != s[len-i-1]) return false;
    }
    return true;
}

bool check2(string s, int k)
{
    int len = s.size();
    int left = 0, right = len-1;
    while (left != right)
    {
        if (left == k) left++;
        if (right == k) right--;
        if (s[left] != s[right]) return false;
        if (right - left == 1) return true;
        left++;
        right--;
        // if (right == -1) return true;
    }
    return true;
}

// string remove(string s, int k)
// {
//     string res;
//     for (int i = 0; i < (int)s.size(); i++)
//     {
//         if (i == k) continue;
//         res += s[i];
//     }
//     return res;
// }

int palindromeIndex(string s) {
    if (check(s)) return -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (check2(s, i)) return i;
    }
    return -2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

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
