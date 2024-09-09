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

const int maxn = 500005;
const i64 mod = 1e9 + 7;

int n, m;
int a[maxn];

namespace Task1 {
	int p[maxn], cnt;
	int b[maxn];

	std::bitset <maxn> vis;

	inline void solve () {
		rep (i, 1, m) { vis.set (a[i]); }

		rep (i, 1, n) { if (not vis[i]) { b[++cnt] = i; } }
		rep (i, 1, cnt) { p[i] = i; }		

		int ans = 0;

		do {
			rep (i, 1, cnt) { a[m + i] = b[p[i]]; }

			int L = 0;
			rep (i, 1, n) { L += std::max (0, (int) i - a[i]); }

			int R = 0;
			rep (i, 1, n) {
				rep (j, i + 1, n) {
					R += a[i] > a[j];
				}
			}

			ans += L == R;
		} while (std::next_permutation (p + 1, p + cnt + 1));
	
		std::cout << ans << "\n";
	}
}

namespace Task2 {
	inline void solve () {
		i64 cnt = 1;
		i64 sum = 1;

		i64 ans = 0;
		rep (i, 2, n) {
			std::cerr << "i = " << i << "\n";
			std::cerr << sum << "\n";
			std::cerr << cnt << "\n";

			ans += sum + cnt;
			i64 n_cnt = cnt + sum;
			i64 n_sum = 2 * sum + cnt;

			cnt = n_cnt; sum = n_sum;
		}

		std::cout << sum << "\n";
	}
}

namespace Solution {
	int p[maxn];

	inline void solve () {
		rep (i, 1, m) { p[a[i]] = i; }
		
	}	
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();
	
	std::cin >> n >> m;
	rep (i, 1, m) { std::cin >> a[i]; }

	// if (n <= 10) {
	// 	Task1::solve ();
	// } 

	// Task1::solve ();
	Task2::solve ();

	// Solution::solve ();

	return 0;
}
