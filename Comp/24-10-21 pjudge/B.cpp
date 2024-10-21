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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 3005;

int n, k;
int a[maxn];

namespace Task1 {
	const int maxn = 13;
	
	int p[maxn];
	inline void solve() {
		rep (i, 1, n) p[i] = i;

		int ans = 0;
		do {
			bool flg = true;
			rep (i, 1, n - 1) {
				if (std::abs(a[p[i]] - a[p[i + 1]]) == k) {
					flg = false; break;
				} 
			}
			
			ans += flg;
		} while (std::next_permutation(p + 1, p + n + 1));

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];

	Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
