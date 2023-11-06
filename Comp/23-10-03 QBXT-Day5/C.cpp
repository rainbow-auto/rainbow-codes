#include <iostream>

using namespace std;

const int maxn = 205;

int n, m, k;
int a[maxn];

namespace Task1 {

    int res;
    void dfs (int now, int sum) {
        if (now >= n) { res += sum == m; return; }
        if (sum > m) { return; }

        for (int i = 1; i <= k; i++) {
            dfs (now + 1, sum + a[i]);
        }
    }

    inline void solve () {
        int id = 0; while (a[id + 1] <= m and id + 1 <= n) { id ++; } k = id;
        dfs (0, 0);
        cout << (res % 2) << endl;
    }

}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) { cin >> a[i]; }
    
        Task1::solve ();
    }


    return 0;
}