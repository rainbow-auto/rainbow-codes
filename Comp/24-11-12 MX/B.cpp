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
#define MultiTask lovely_fairytale

const int maxn = 3005;

i64 n, m;

namespace Task1 {
	std::bitset<maxn> vis;
	inline void solve() {
		int ansk = 0;
		i64 ansval = -0x3f3f3f3f;
		rep (k, 1, m) {
			vis.reset();
			i64 cur = 0;
			rep (i, 1, n) {
				// Alice
				vis.set(i);
				// Bob
				int x = (i * k - 1) % n + 1;
				if (not vis[x]) cur += x;
				vis.set(x);
			}
			if (ansval < cur) ansval = cur, ansk = k;
		}

		std::cout << ansk << "\n";
	}
}

namespace Task2 {
	inline __int128 sum(__int128 l, __int128 r) {
		if (l > r) return 0;
		return 1ll * (r - l + 1) * (l + r) / 2ll;
	}

	inline __int128 calc(__int128 k, __int128 p, __int128 l, __int128 r) {
		if (l > r) return 0;
		return k * sum(l, r) - p * (r - l + 1) * n;
	}

	inline void solve() {
		// db << "--------------------------------\n";
		// db << "n = " << n << " | m = " << m << "\n";

		__int128 ansval = 0, ansk = 1;
		rep (k, 2, m) {
			// dbg(k);
			__int128 cur = 0;

			rep (p, 0, k - 1) {
				// dbg(p);
				__int128 L = 1ll * (p * n) / (k - 1) + 1;
				__int128 R = 1ll * (p * n + n + 1) / k;

				// assert(k * L - 1 - p * n >= L);
				// assert(k * R - 1 - p * n >= R);
				// assert(k * L - 1 <= (p + 1) * n);
				// assert(k * R - 1 <= (p + 1) * n);

				// i * k - p * n

				// db << "k: " << k << "\n";

				cur += calc(k, p, L, R);
				// db << "[" << L << ", " << R << "] " << calc(k, p, L, R) << "\n";
				if (not (n % k)) break;
			}

			if (m == 1145 and k == 1143) {
				dbg((i64)cur);
			} 
			if (m == 1145 and k == 1145) {
				dbg((i64)cur);
			} 

			if (cur > ansval) ansval = cur, ansk = k;
			
			// dbendl;
		}

		std::cout << (i64) ansk << "\n";
	}	 
}

void solve() {
	std::cin >> n >> m;
	
	if (n <= 2000) Task1::solve();
	else Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

	std::freopen("b.in", "r", stdin);
	std::freopen("b.out", "w", stdout);

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
