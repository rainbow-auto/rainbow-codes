#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 100005;

int n;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v) {
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

inline void clear () {
    cnt = 0;
    memset (last, 0, sizeof(last));
}

namespace Baoli {
    int dep[maxn];

    int bfs (int S) {
        queue<int> q; q.push (S);
        fill (dep + 1, dep + n + 1, 1e9);

        dep[S] = 0;
        while (not q.empty()) {
            int now = q.front(); q.pop();

            for (int i = last[now]; i; i = pre[i]) {
                int t = to[i];
                if (dep[t] == 1e9) {
                    dep[t] = dep[now] + 1;
                    q.push(t);
                }
            }
        }

        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max (mx, dep[i]);
        }
        return mx;
    }
    
    int solve () {
        int res = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            res = min (res, bfs(i));
        }

        return res;
    }
}

int main () {
    ios::sync_with_stdio();

    int T; cin >> T;
    while (T--) {
        clear();

        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s; s = " " + s;
            for (int j = 1; j <= n; j++) {
                if (s[j] == '1') { addEdge (i, j); }
            }
        }

        cout << Baoli::solve() << endl;
    }

    return 0;
}