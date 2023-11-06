#include <iostream>
#include <cstring>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

const int maxn = 200005;

// 去重!

int T;

int n;
int a[maxn];
int t[maxn];

int main () {

    cin >> T;

    while (T--) {
        cin >> n;

        memset (t, 0, sizeof (t));

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            for (int x = 1; x * a[i] <= n; x++) {
                t[x * a[i]] ++;
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max (res, t[i]);
        }

        cout << res << endl;
    }

    return 0;
}