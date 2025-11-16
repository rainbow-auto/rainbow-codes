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

int n, k;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int dep[maxn], mndep;

int g[maxn];
void dfs(int now) {
	g[dep[now]]++;
	int tot = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dep[t] = dep[now] + 1;
		dfs(t);
		tot++;
	}
	if (not tot) mndep = std::min(mndep, dep[now]);
}

void clr() {
	cnt = 0;
	rep (i, 1, n) last[i] = 0;
	rep (i, 1, n) g[i] = 0;
	rep (i, 1, n) dep[i] = 0;
}

void solve() {
	std::cin >> n >> k;
	rep (i, 2, n) {
		int p; std::cin >> p;
		addEdge(p, i);
	}
	
	mndep = 0x3f3f3f3f;
	dep[1] = 1; dfs(1);
	
	std::bitset<maxn> f;
	f.set(0);
	int sum = 0;
	int ans = 0;

	std::bitset<maxn> msk;
	rep (i, 0, k) msk.set(i);

	int L = (k - n);
	rep (i, 1, mndep) {
		f |= (f << g[i]);
		// sum += g[i];
		rep (j, L, L + g[i] - 1) if (j >= 0) msk[j] = 0;
		L += g[i];
		if ((f & msk).any()) ans = i;
		// rep (j, sum + (k - n), k) if (j >= 0 and f[j]) ans = i;
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
