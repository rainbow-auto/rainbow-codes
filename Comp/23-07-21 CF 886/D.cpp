#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 200005;

int T;
int n, k;

int a[maxn];

int main () {
    cin >> T;

    while (T--) {
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort (a + 1, a + n + 1);

        a[0] = - k;

        int pos = 1;
        int ans = 0;

        int last = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] - a[i - 1] > k) {
                ans = max (ans, i - 1 - last + 1);
                last = i;
            }
        }

        ans = max (ans, n - last + 1);

        cout << n - ans << endl;
    }

    return 0;
}