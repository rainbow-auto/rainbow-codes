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

int n;

struct DSU {
	int fa[maxn];
	int L[maxn], R[maxn];

	inline void init() {
		rep (i, 0, n - 1) L[i] = R[i] = fa[i] = i;
	}
	
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}

	inline void mrg(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		fa[v] = u;
		L[u] = std::min(L[u], L[v]);
		R[u] = std::max(R[u], R[v]);
	}
} dsu;

void solve() {
	std::string s; std::cin >> s;
	n = s.size();
	
	dsu.init();
	rep (i, 0, n - 1) if (i - 1 >= 0 and s[i] == s[i - 1]) dsu.mrg(i, i - 1);
	
	int ans = 0;
	rep (i, 0, n - 1) {
		int r1 = i;
		int l1 = dsu.L[dsu.find(r1)];
		
		int r0 = l1 - 1;
		if (r0 < 0) continue;
		if (s[r0] + 1 != s[r1]) continue;
		int l0 = dsu.L[dsu.find(r0)];
		
		if (r0 - l0 + 1 >= r1 - l1 + 1) {
			ans++;
		}
	}

	std::cout << ans << "\n";
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
