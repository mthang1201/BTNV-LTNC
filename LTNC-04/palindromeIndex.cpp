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

int palindromeIndex(string s) {
    int idx = -1;
    size_t changes = 0;
    bool isSecondTry = false;
    auto itRollBakc = s.begin();
    auto chrRollBack = *itRollBakc;
    for(auto bIt = s.begin(), eIt = --s.end(); bIt < eIt; ++bIt, --eIt){
        if(*bIt == *eIt){
            continue;
        }
        if(++changes == 2){
            if(isSecondTry){
                return -1;
            }
            isSecondTry = !isSecondTry;
            changes = 0;
            idx = -1;
            s.insert(itRollBakc, chrRollBack);
            bIt = --s.begin();
            eIt = s.end();
            continue;
        }
        if(*(bIt + 1) == *eIt && !isSecondTry){
            idx = std::distance(s.begin(), bIt);
            chrRollBack = *bIt;
            bIt = itRollBakc = s.erase(bIt);
            eIt = s.end() - idx - 1;
        }else if(*bIt == *(eIt - 1)){
            idx = std::distance(s.begin(), eIt);
            eIt = s.erase(eIt);
            bIt = s.begin() + idx;
        }
    }
    return idx;
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
