#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

int n, q;
int a[maxn];

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v, int w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

int fa[maxn];
i64 in[maxn], sum[maxn];
std::map<int, i64> c[maxn];

i64 ans;

void dfs(int now) {
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa[now]) continue;
        
        ans += (a[now] != a[t] ? es[i].w : 0);
        c[now][a[t]] += es[i].w;
        sum[now] += es[i].w;
        in[t] = es[i].w;

        fa[t] = now;
        dfs(t);
    }
}

void solve() {
	std::cin >> n >> q;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        i64 w; std::cin >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    ans = 0;
    dfs(1);

    while (q--) {
        int u, x; std::cin >> u >> x;
        if (fa[u] and a[u] != a[fa[u]]) ans -= in[u];
        ans -= sum[u] - c[u][a[u]];
        if (fa[u]) c[fa[u]][a[u]] -= in[u];

        a[u] = x;

        if (fa[u] and a[u] != a[fa[u]]) ans += in[u];
        ans += sum[u] - c[u][a[u]];
        if (fa[u]) c[fa[u]][a[u]] += in[u];

        std::cout << ans << "\n";
    }

    rep (i, 1, n) c[i].clear();
    rep (i, 1, n) sum[i] = 0;
    rep (i, 1, n) last[i] = 0;
    cnt = 0;
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
