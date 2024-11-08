#include <iostream>

using namespace std;

const int maxn = 1000005;

int n;
int a[maxn];
int col[maxn];

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt; 
}

namespace Task1 {

    inline void buildChain () {
        int now = 1, pre = 0;
        int nxt = 1;
        
        int tot = 0;
        while (nxt) {
            nxt = 0;
            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                if (t == pre) { continue; }
                else { nxt = t; }
            }

            a[++tot] = col[now];
            pre = now;
            now = nxt;
        }
    }

    inline void solve () {
        buildChain ();
        
        int cnt0 = 0, cnt1 = 0;

        int ans = 0;
        for (int i = 1; i <= n - 1; i++) { // i 到 i + 1 的边
            cnt0 += a[i] == 0;
            cnt1 += a[i] == 1;

            ans += max (cnt0 - cnt1, 0);
        }

        cout << ans << endl;
    }

}

int main () {

    freopen ("wbtree.in", "r", stdin);
    freopen ("wbtree.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i ++) { cin >> col[i]; }

    for (int i = 1; i <= n - 1; i ++) {
        int u, v; cin >> u >> v;

        addEdge (u, v);
        addEdge (v, u);
    }

    Task1::solve ();

    return 0;
}