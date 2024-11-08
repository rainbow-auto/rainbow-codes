#include <iostream>
#include <string>

using namespace std;

string s;
int a, b, p;

void solve () {
    for (int i = s.size() - 2; i >= 1; i--) {
        if (s[i] != s[i + 1]) {
            if (s[i + 1] == 'A') {
                if (p - a >= 0) { p -= a; }
                else { cout << i + 1 << endl; return; }
            } else {
                if (p - b >= 0) { p -= b; }
                else { cout << i + 1 << endl; return; }
            }
        }
    }

    cout << "aaa" << endl;
    return;
}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> a >> b >> p;

        cin >> s;
        s = " " + s;

        solve ();
    }


    return 0;
}