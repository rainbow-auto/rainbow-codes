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

constexpr int maxn = 1000005;
int n, q;

int col[maxn];

int fa[maxn];
int siz[maxn];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

inline void mrg(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	fa[v] = u;
	siz[u] += siz[v];
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) fa[i] = i;

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int u, v; std::cin >> u >> v;
			mrg(u, v);
		} else if (op == 2) {
			int x; std::cin >> x;
			if (not col[x]) siz[find(x)]++;
			else siz[find(x)]--;
			col[x] ^= 1;
		} else {
			int x; std::cin >> x;
			if (siz[find(x)]) std::cout << "Yes\n";
			else std::cout << "No\n";
		}
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
	}

	return 0;
}
