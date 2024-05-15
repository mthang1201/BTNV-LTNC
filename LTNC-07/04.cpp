#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

vector<string> crosswordPuzzle(vector<string> c, string ws)
{
    if (ws.empty()) return c;
    size_t k = ws.find_last_of(';');
    string w = (k != string::npos ? ws.substr(k+1) : ws);
    ws.resize(k != string::npos ? k : 0);
    for (int dx = 1, dy = 0; dy <= 1; dx--, dy++)
        for (int y = 0; y < 10; y++)
            for (int x = 0; x < 10; x++)
                if (x < dx || y < dy || c[y - dy][x - dx] == '+')
                    for (int i = 0, n = 10-x*dx-y*dy, t = 0; i < n
                    && ((t=c[y+i*dy][x+i*dx])=='-' || t == w[i]);)
                        if(++i==n || c[y+i*dy][x+i*dx] == '+') 
                            if (!w[i]) {
                                auto r = c;
                                for (int j = 0; w[j]; j++) 
                                    r[y+j*dy][x+j*dx] = w[j];
                                r = crosswordPuzzle(r, ws);
                                if(r.size()) return r;
                            }
    return vector<string>();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
