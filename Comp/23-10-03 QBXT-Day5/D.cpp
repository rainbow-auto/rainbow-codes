#include <iostream>
#include <random>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

const int maxn = 205;
const int maxm = 605;

int n, m, A, B;

struct Edge {
    int u, v;
    int pre;
} es[maxm << 2];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

struct Node {
    int val;
    int id;

    friend bool operator < (Node a, Node b) {
        return a.val < b.val;
    }
} v[maxn];

namespace Task1 {
    int a[maxn];
    int vis[maxn];

    inline int _solve () {
        memset (vis, 0, sizeof (vis));

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int now = a[i];
            if (vis[now]) { continue; }
            vis[now] = true;

            res += v[a[i]].val;

            for (int j = last[now]; j; j = es[j].pre) {
                int t = es[j].v;
                vis[t] = true;    
            }
        }

        return res;
    }

    inline void solve () {
        sort (v + 1, v + n + 1);
        for (int i = 1; i <= n; i++) { a[i] = i; }   

        int res = _solve ();

        int startTime = clock ();
        while (clock () - startTime < (double) CLOCKS_PER_SEC * 0.85) {
            random_shuffle (a + 1, a + n + 1);
            res = max (res, _solve ());
        }

        cout << res << endl;
    }

}

int main () {

    cin >> n >> m >> A >> B;

    for (int i = 1; i <= n; i++) { cin >> v[i].val; v[i].id = i; }

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    Task1::solve ();

    return 0;
}