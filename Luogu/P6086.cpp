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

constexpr int maxn = 5000005;

int n, m;

namespace Decoder {
	int pi[maxn];
	int deg[maxn];
	int fa[maxn];

	inline void solve() {
		rep (i, 1, n - 2) std::cin >> pi[i];
		
		rep (i, 1, n) deg[i] = 1;
		rep (i, 1, n - 2) deg[pi[i]]++;
		pi[n - 1] = n;

		int p = 1;
		rep (i, 1, n - 1) {
			while (deg[p] > 1) p++;
			fa[p] = pi[i];
			while (i < n and (--deg[pi[i]]) == 1 and pi[i] < p) {
				fa[pi[i]] = pi[i + 1]; i++;
			}
			p++;
		}

		i64 res = 0;
		rep (i, 1, n - 1) res ^= 1ll * i * fa[i];
		std::cout << res << "\n";
	}
}

namespace Encoder {
	int fa[maxn];
	int pi[maxn];
	int deg[maxn];

	inline void solve() {
		rep (i, 1, n - 1) std::cin >> fa[i];
		rep (i, 1, n - 1) deg[i] = 1;
		rep (i, 1, n) deg[fa[i]]++;
		
		int p = 1;
		rep (i, 1, n - 2) {
			while (deg[p] > 1) p++;
			pi[i] = fa[p]; 
			while (i < n - 1 and (--deg[pi[i]]) == 1 and pi[i] < p) {
				pi[i + 1] = fa[pi[i]]; i++;
			}
			p++;
		}
		
		i64 res = 0;
		rep (i, 1, n - 2) res ^= (1ll * i * pi[i]);
		std::cout << res << "\n";
	}
}

void solve() {
	std::cin >> n;
	int op; std::cin >> op;
	if (op == 1) Encoder::solve();
	if (op == 2) Decoder::solve();
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
