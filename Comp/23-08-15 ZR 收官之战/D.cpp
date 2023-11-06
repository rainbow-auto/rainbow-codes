#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 3005;

int to[maxn * maxn * 2], pre[maxn * maxn * 2], last[maxn];
int cnt = 1;
bool exist[maxn * maxn * 2];

inline void addEdge (int u, int v, bool status) {
    cnt ++;
    exist[cnt] = status;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

inline void rotate (int id) {
    exist[id] = not exist[id];
    exist[id ^ 1] = not exist[id ^ 1];
}

int n, q;

stack<int> stk;
bool ins[maxn];
int low[maxn], dfn[maxn], dpos;
int scc[maxn], scc_cnt;

void  (int now) {
    low[now] = dfn[now] = ++dpos;
    stk.push(now);
    ins[now] = true;

    for (int i = last[now]; i; i = pre[i]) {
        if (not exist[i]) { continue; }

        int t = to[i];
        if (not dfn[t]) {
            (t);
            low[now] = min(low[now], low[t]);
        } else if (ins[t]) {
            low[now] = min(low[now], dfn[t]);
        }
    }

    if (low[now] == dfn[now]) {
        scc_cnt ++;
        do {
            now = stk.top();
            ins[now] = false;
            scc[scc_cnt]++;
            stk.pop();
        } while (low[now] != dfn[now]);
    }
}

int main () {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < j) {
                addEdge (j, i, true);
                addEdge (i, j, false);
            }
        }
    }

    cin >> q;

    while (q--) {
        int u, v; cin >> u >> v;
        int t = -1;
        for (int i = last[u]; i; i = pre[i]) { if (to[i] == v) { t = i; } }

        rotate(t);

        memset (dfn, 0, sizeof(dfn)); dpos = 1;
        memset (scc, 0, sizeof(scc)); scc_cnt = 0;  
        while (not stk.empty()) { stk.pop(); }

        for (int i = 1; i <= n; i++) {
            if (not dfn[i]) { (i); }
        }

        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++) { ans += scc[i] * (scc[i] - 1) / 2; }

        cout << ans << endl;
    }

    return 0;
}