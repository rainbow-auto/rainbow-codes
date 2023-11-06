#include <iostream>

using namespace std;

const int maxn = 200005;

int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;
inline void addEdge (int u, int v, int ww) {
    cnt ++;
    to[cnt] = v;
    w[cnt] = ww;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int n;

int x, y[maxn];
bool in[maxn];

set<int> s;
int target;

bool vis[maxn];
bool dfs (int now, int min_now) {
    vis[now] = true;

    bool flag = false;
    for (int i = last[now]; i; i = pre[i]) {
        int t = to[i];
        if (vis[t]) { continue; }
        s.insert(w[i]);
        if (t == target or dfs(t)) { return true; }
    }
    return false;
}

int main () {
    cin >> n;

    cin >> x;

    int y_siz; cin >> y_siz;
    for (int i = 1; i <= y_siz; i++) { cin >> y[i]; in[y[i]] = true; }

    for (int i = 1; i <= n - 1; i++) { int u, v, ww; cin >> u >> v >> ww; addEdge (u, v, ww); addEdge (u, v, ww); }

    for (int i = 1; i <= y_siz; i++) {
        target = y[i];
        memset (vis, 0, sizeof(vis));
        dfs (i);
    }
    return 0;
}