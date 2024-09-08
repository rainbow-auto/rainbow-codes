#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 105;

int n;
int a[maxn];

namespace Task1 {
	const int maxn = 25;

	int ans = 0;

	int f[maxn];
	int b[maxn];

	std::vector <int> choice;
	inline void calc () {
		rep (i, 1, n) { b[i] = a[i]; }
		for (auto x : choice) { b[x] ^= b[x - 1]; }

		rep (i, 1, n) { std::cerr << b[i] << " "; } std::cerr << "\n";

		rep (i, 1, n) {
			f[i] = 0;
			rep (j, 1, i - 1) {
				if (b[i] > b[j]) { f[i] = std::max (f[i], f[j] + 1); }
			}
			
			ans = std::max (ans, f[i]);
		}
	}

	std::bitset <maxn> vis;

	void dfs (int now) {
		calc ();

		if ((double) (clock () - TimeST) / CLOCKS_PER_SEC > 0.8) { return; }

		rep (i, 1, n) {
			// if (vis[i]) { continue; }

			if (a[i] == (a[i] xor a[i - 1])) { continue; }

			choice.push_back (i);
			// vis.set (i);

			dfs (now + 1);

			choice.pop_back ();
			// vis.reset (i);
		}
	}
	
	inline void solve () {
		dfs (1);

		std::cout << ans << "\n";	
	}
}

namespace Task2 {
	const int maxn = 25;
	std::vector <int> b[maxn];

	int f[maxn][(1 << 20) + 5];

	inline void solve () {
		rep (i, 1, n) {
			rep (S, 0, (1 << (i - 1)) - 1) {
				int val = 0;
				rep (j, 1, i - 1) {
					if (S & (1 << (j - 1))) { val ^= a[j]; }
				}
				b[i].push_back (val);
			}	
			std::sort (b[i].begin (), b[i].end ());
			b[i].erase (std::unique (b[i].begin (), b[i].end ()), b[i].end ());
		}

		int ans = 0;

		rep (i, 1, n) {
			rep (iS, 0, b[i].size () - 1) {
				f[i][iS] = 1;
				rep (j, 1, i - 1) {
					rep (jS, 0, b[j].size () - 1) {
						if (b[i][iS] <= b[j][jS]) { break; }

						f[i][iS] = std::max (f[i][iS], f[j][jS] + 1);
					}
				}
				ans = std::max (ans, f[i][iS]);
			}
		}

		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("c.in", "r", stdin);
	freopen ("c.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	// Task1::solve ();

	Task2::solve ();

	return 0;
}
