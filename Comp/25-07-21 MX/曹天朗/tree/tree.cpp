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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

struct Edge {
    int u, v; 
    int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

int n;
i64 a[maxn];

i64 ans = 0;
i64 f[maxn];
void dfs(int now, int fa) {
    f[now] = a[now];
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) continue;
        dfs(t, now);
        f[now] += std::max(f[t], 0ll);
    }
    ans = std::max(ans, f[now]);
}

void solve() {
	std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    dfs(1, 0);

    std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("tree")

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
