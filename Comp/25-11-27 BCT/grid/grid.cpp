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

constexpr int maxn = 400005;

int n, m, k;

struct DSU {
	int fa[maxn], siz[maxn];
	DSU (int n) {
		rep (i, 1, n) fa[i] = i;
		rep (i, 1, n) siz[i] = 1;
	}

	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}

	inline void mrg(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (siz[u] < siz[v]) std::swap(u, v);
		fa[v] = u;
		siz[u] += siz[v];
	}
};

void solve() {
	std::cin >> n >> m >> k;

	DSU dsu((n + m) << 1);

	while (k--) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		// x1 <= x2
		
		if (y2 == y1 + 1) {
			y1 += n;
			dsu.mrg(x1, y1);
			dsu.mrg(x1 + (n + m), y1 + (n + m));
		} else { 
			y2 += n;
			dsu.mrg(x1, y2 + (n + m));
			dsu.mrg(x1 + (n + m), y2);
		}
	}
	
	rep (i, 1, n + m) if (dsu.find(i) == dsu.find(i + (n + m))) return std::cout << "NO\n", void(0);
	std::cout << "YES\n";
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
