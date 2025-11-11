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

constexpr int maxn = 2000005;
constexpr int mod = 998244353;

int n, m;
int V;
int a[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int bel[maxn], tot;
std::vector<int> edcc[maxn];
int dfn[maxn], low[maxn], dpos;
std::stack<int> stk;

void tarjan(int now, int fa) {
	dfn[now] = low[now] = ++dpos;
	stk.push(now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (not dfn[t]) {
			tarjan(t, now);
			low[now] = std::min(low[now], low[t]);
		} else if (t != fa) {
			low[now] = std::min(low[now], dfn[t]);
		}
	}
	if (low[now] == dfn[now]) {
		++tot;
		int t = 0;
		do {
			t = stk.top(); stk.pop();
			bel[t] = tot;
			edcc[tot].push_back(t);
		} while (t != now);
	}
}

int col[maxn]; // -1
bool odd(int now) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (bel[t] != bel[now]) continue;
		if (not ~col[t]) {
			col[t] = col[now] ^ 1;
			if (odd(t)) return true;
		} else if (col[t] == col[now]) {
			return true;
		}
	}
	return false;
}

inline void clr() {
	rep (i, 1, n) low[i] = dfn[i] = 0;
	std::exchange(stk, {});
	rep (i, 1, n) std::exchange(edcc[i], {});
	tot = 0;

	cnt = 0;
	rep (i, 1, n) last[i] = 0;
	rep (i, 1, n) col[i] = -1;
}

void solve() {
	std::cin >> n >> m >> V;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	rep (i, 1, n) if (not dfn[i]) tarjan(i, 0);

	rep (i, 1, n) col[i] = -1;

	i64 ans = 1;
	rep (i, 1, tot) {
		// for (auto x : edcc[i]) db << x << " "; dbendl;

		int v = -1;
		for (auto x : edcc[i]) {
			if (not ~a[x]) continue;
			if (not ~v) v = a[x];
			if (~v and a[x] != v) {
				ans *= 0;
			}
		}

		if (not ans) break;

		col[edcc[i].front()] = 1; 
		if (odd(edcc[i].front())) {
			if (~v and v) ans *= 0;
			continue; 
		}
		if (not ~v) (ans *= V) %= mod;

		if (not ans) break;
	}

	std::cout << ans << "\n";

	clr();
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
