#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

#define endl "\n"

int n;
int c0, c1;

int main () {

    cin >> n;

    char pre; cin >> pre;

    for (int i = 2; i <= n; i++) {
        char now; cin >> now;

        if (now == '0' and pre == '0') {
            c0 ++;
        } else if (now == '1' and pre == '1') {
            c1 ++;
        }

        pre = now;
    }

    int ans = c0 + c1 + 1 - std::min (c0, c1);
    cout << ans << endl;

    return 0;
}