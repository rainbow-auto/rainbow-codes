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

constexpr int maxn = 30005;

int n;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

int fa[maxn];
int L[maxn], R[maxn];

inline void init() {
	rep (i, 1, (n << 1)) fa[i] = L[i] = R[i] = i;
}

std::set<int> s;

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void mrg(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	fa[v] = u;
	L[u] = std::min(L[u], L[v]);
	R[u] = std::max(R[u], R[v]);
}

std::bitset<maxn> vis;

std::stack<int> stk;

void dfs(int now, int S, int T, bool &flg) {
	vis.set(now);

	if (now == T) {
		while (not stk.empty()) {
			s.insert(stk.top().second);
			stk.pop();
		}
		flg = true;
		return;
	}

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (vis[t]) continue;
		if (not flg) stk.push(es[i].w);
		dfs(t, S, T, flg);
		if (not flg) stk.pop();
	}
}

void solve() {
	std::cin >> n;
	
	init();
	
	rep (i, 1, n) {
		int a, b; std::cin >> a >> b;
		addEdge(a, b, i); addEdge(b, a, i);
		mrg(a, b);
	}

	rep (i, 1, (n << 1)) {
		if (fa[i] == i) {
			bool flg = false;
			dfs(L[i], L[i], R[i], flg);
            assert(flg);
		}
	}

	std::cout << s.size() << "\n";
	for (auto x : s) std::cout << x << " "; std::cout << "\n";

	s.clear();
	std::memset(last, 0, sizeof last);
	cnt = 0;
    vis.reset();
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