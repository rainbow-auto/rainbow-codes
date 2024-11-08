#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;

int ans = 0;

inline void swapToPos (int x, int pos) {
    int now = x;
    while (now > pos) {
        swap (s[now], s[now - 1]);
        now --;
        ans ++;
    }
} 

int main () {

    cin >> n;
    cin >> s;

    for (int i = 0; i < s.size (); i++) {
        int lcnt = 0, rcnt = 0;
        for (int j = 0; j <= i; j++) { lcnt += s[j] == '('; rcnt += s[j] == ')'; }

        if (lcnt >= rcnt) { continue; }

        for (int j = i + 1; j < s.size (); j++) {
            if (s[j] == '(') { swapToPos (j, i); break; }
        }
    }

    cout << ans << endl;

    return 0;
}