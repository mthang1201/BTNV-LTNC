#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    istringstream iss(s);
    string hour;
    getline(iss, hour, ':');
    string minute;
    getline(iss, minute, ':');
    
    if (s[8] == 'A') {
        string second;
        getline(iss, second, 'A');
        if (hour == "12") hour = "00";
        return hour + ":" + minute + ":" + second;
    }
    else {
        string second;
        getline(iss, second, 'P');
        int tmp = stoi(hour);
        tmp += 12;
        hour = to_string(tmp);
        if (hour == "24") hour = "12";
        return hour + ":" + minute + ":" + second;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
