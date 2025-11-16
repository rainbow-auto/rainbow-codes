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

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

int dis[maxn];
int fa[maxn];
void dfs(int now) {
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa[now]) continue;
        fa[t] = now;
        dis[t] = dis[now] + 1;
        dfs(t);
    }
}

bool in_chain[maxn];
bool find_chain(int now, int v) {
    in_chain[now] = false;
    if (now == v) in_chain[now] = true;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa[now]) continue;
        in_chain[now] |= find_chain(t, v);
    }
    return in_chain[now];
}

inline void clr() {
    cnt = 0;
    rep (i, 1, n) last[i] = 0;
}

void solve() {
	std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }


    auto get = [&](int x) -> int {
        fa[x] = -1;
        dis[x] = 0;
        dfs(x);
        return std::max_element(dis + 1, dis + n + 1) - dis;
    };

    int x = get(1);
    int y = get(x);

    find_chain(x, y);

    if (dis[y] == n - 1) return std::cout << "-1\n", void(0);

    rep (i, 1, cnt) {
        int u = es[i].u;
        int v = es[i].v;
        if (in_chain[u] and not in_chain[v]) return std::cout << fa[u] << " " << u << " " << v << "\n", void(0);
    }
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
        clr();
	}

	return 0;
}
