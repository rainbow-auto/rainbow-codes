#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 200005;

int n;
int a[maxn];

namespace Task1 {

    int maxAns = 0, minAns = 0x3f3f3f3f;

    vector<int> chosen;

    inline int getCnt () {
        set<int> curr;
        for (auto now : chosen) { curr.insert (now); }

        return curr.size ();
    }

    inline void dfs (int now) {
        if (now > n) { int cnt = getCnt (); minAns = min (minAns, cnt); maxAns = max (maxAns, cnt); return; }

        for (int i = -1; i <= 1; i++) {
            chosen.push_back (a[now] + i);

            dfs (now + 1);

            chosen.pop_back ();
        }
    }

    inline void solve () {
        dfs (1);

        cout << minAns << " " << maxAns << endl;
    }
}

int main () {

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Task1::solve ();

    return 0;
}