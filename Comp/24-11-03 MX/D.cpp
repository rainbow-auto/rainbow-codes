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

const int maxn = 500005;

int n, m;

i64 a[maxn], b[maxn];
int x[maxn], y[maxn];

namespace Task1 {
	inline void solve() {
		i64 ans = 0;

		rep (l, 1, n) {
			i64 sum = 0;
			std::bitset<(maxn << 1)> mark;
			rep (r, l, n) {
				sum += x[r];
				mark.set(a[r]);

				i64 cur = 0;
				rep (i, 1, m) {
					if (mark[b[i]]) {
						ans = std::max(ans, sum + cur);
						cur = 0;
					} else {
						cur += y[i];
					}
				}
				ans = std::max(ans, sum + cur);
			}
		}

		std::cout << ans << "\n";
	}
}

namespace Task2 {
	int pos[maxn << 1];
	i64 pre[maxn];

	inline void solve() {
		i64 ans = 0;

		rep (i, 1, m) pos[b[i]] = i;
		rep (i, 1, m) pre[i] = pre[i - 1] + y[i];

		auto qry = [&](int l, int r) -> i64 {
			if (l > r) return 0;
			return pre[r] - pre[l - 1];
		};

		rep (l, 1, n) {
			i64 sum = 0;

			std::set<int> divs; divs.insert(0); divs.insert(m + 1);
			std::set<i64> sums; sums.insert(qry(1, m));

			rep (r, l, n) {
				sum += x[r];
				int p = pos[a[r]];
				if (not p) continue;

				auto nxt = divs.upper_bound(p);
				auto pre = std::prev(nxt);

				sums.erase(qry((*pre) + 1, (*nxt) - 1));
				sums.insert(qry((*pre) + 1, p - 1));
				sums.insert(qry(p + 1, (*nxt) - 1));

				divs.insert(p);
				ans = std::max(ans, sum + (*sums.rbegin()));
			}
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> x[i];

	rep (i, 1, m) std::cin >> b[i];
	rep (i, 1, m) std::cin >> y[i];

	// Task1::solve();
	Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("leading.in", "r", stdin);
	std::freopen("leading.out", "w", stdout);

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
