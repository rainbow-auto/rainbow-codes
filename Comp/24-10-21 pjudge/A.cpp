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

const int maxn = 150005;

int n;
int a[maxn], b[maxn];


inline int f(i64 x) {
	int tot = 0;
	while (x) tot++, x /= 10ll;
	return tot;
}

namespace Task1 {

	int t[12];
	int cnt1[12];
	int cnt2[12];

	inline void solve() {
		int ans = 0;

		rep (i, 1, n) {
			rep (j, 1, n) {
				if (i == 1) {
					t[f(b[j])] += f(a[i] + b[j]);
					int d = std::max(f(a[i]), f(b[j]));

					cnt1[f(b[j])] += bool (f(a[i] + b[j]) == d);
					cnt2[f(b[j])] += bool (f(a[i] + b[j]) == d + 1);
				
				}
				ans += f(a[i] + b[j]);
			}

			// if (i == 1) {
			// 	rep (k, 1, 10) {
			// 		std::cout << t[k] << " " << cnt1[k] << " " << cnt2[k] << "\n";
			// 	}
			// 	std::cout << "\n";
			// }
		}

	}
}

namespace Solution {
	i64 pw10[13];
	std::vector<i64> t[13];

	inline void solve() {
		pw10[0] = 1;
		rep (i, 1, 12) pw10[i] = pw10[i - 1] * 10ll;
		
		rep (i, 1, n) t[f(b[i])].push_back(b[i]);
		rep (w, 1, 10) std::sort(t[w].begin(), t[w].end());

		i64 ans = 0;

		rep (i, 1, n) {
			i64 cur = f(a[i]);

			int dt = 0;

			rep (w, 1, 10) {
				if (not t[w].size()) continue;

				i64 d = std::max(w, cur);

				// a + b < 10 ^ d
				i64 cnt1 = std::lower_bound(t[w].begin(), t[w].end(), pw10[d] - a[i]) - t[w].begin();
				i64 cnt2 = (int) t[w].size() - cnt1;

				ans += cnt1 * d;
				ans += cnt2 * (d + 1);
			}
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> b[i];
	

	// Task1::solve();
	Solution::solve();
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
