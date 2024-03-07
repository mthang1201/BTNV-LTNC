#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b; cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    string c = a + b;
    string a2 = a, b2 = b;
    a2[0] = b[0]; b2[0] = a[0];
    cout << c << endl << a2 << " " << b2;
    return 0;
}
