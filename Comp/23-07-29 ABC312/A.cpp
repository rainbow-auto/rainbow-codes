#include <iostream>
#include <cstring>

using namespace std;

int main () {
    string s;

    cin >> s;

    if (s == "ACE" or s == "BDF" or s == "CEG" or s == "DFA" or s == "EGB" or s == "FAC" or s == "GBD") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}