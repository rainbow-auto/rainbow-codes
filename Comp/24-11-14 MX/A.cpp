#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

i64 n;
i64 x, y;
namespace Task1 {
	const int maxn = 1000005;
	i64 f[maxn];
	inline void solve() {
		i64 ans; std::memset(&ans, 0x3f, sizeof ans);
		i64 inf; std::memset(&inf, 0x3f, sizeof inf);

		std::memset(f, 0x3f, sizeof f);
		f[1] = 0;

		std::bitset<maxn> go;
		rep (i, 1, n) {
			if (f[i] == inf) continue;
			rep (j, 1, n) {
				i64 cur = f[i] + x + j * y;
				if (i * (j + 1) > n) {
					ans = std::min(ans, cur);
					break;
				} else {
					f[i * (j + 1)] = std::min(f[i * (j + 1)], cur);
					go.set(i * (j + 1));
				}
			}
			int nxt = go._Find_next(i);
			if (nxt > n) break;
			i = nxt - 1; // than i++
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::freopen("dice.in", "r", stdin);
	std::freopen("dice.out", "w", stdout);

	std::cin >> n >> x >> y;
	Task1::solve();
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
