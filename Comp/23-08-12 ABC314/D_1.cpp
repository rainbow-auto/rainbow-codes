#include <iostream>
#include <cctype>

using namespace std;

const int maxn = 500005;

int tag;
int val[maxn];

int n, q; string s;

int main () {

    cin >> n;
    cin >> s; s = " " + s;
    cin >> q;

    int last;
    while (q--) {
        int op, x; char c;
        cin >> op >> x >> c;
        switch (op) {
            case 1:
                s[x] = c;
                val[x] = -tag;
                break;
            case 2:
                last = 2;
                tag ++;
                break;
            case 3:
                last = 3;
                tag ++;
                break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (val[i] + tag == 0) {
            cout << s[i];
        } else {
            if (last == 2) {
                if (isupper(s[i])) { cout << char(s[i] + 32); }
                else { cout << s[i]; }
            } else if (last == 3) {
                if (isupper(s[i])) { cout << s[i]; }
                else { cout << char(s[i] - 32); }
            }
        }
    }

    return 0;
}