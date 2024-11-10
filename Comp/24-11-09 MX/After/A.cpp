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

const int maxn = 2000005;

int n;
int a[maxn];

namespace Solution {
	std::pair<int, i64> nxt[maxn];
	inline void get_nxt() {
		rep (i, 1, n) a[n + i] = a[i];
		rep (i, 1, n << 1) if (a[i]) ps.push_back(i);

		if (m < n) {
			rep (i, 1, n) {
				auto it = std::upper_bound(ps.begin(), ps.end(), i + m);
				if (it == ps.begin() or *std::prev(it) <= i) nxt[i] = std::make_pair((int) i + 1, 1);
				else nxt[i] = std::make_pair(*std::prev(it), *std::prev(it) - i);
			}

			rep (i, 1, n) nxt[i].first = get(nxt[i].first);
		} else {
			rep (i, 1, n) {
				int R = get(i + m);
				i64 t = (m - R) / n;

				auto it1 = std::upper_bound(ps.begin(), ps.end(), R);
				if (it1 != ps.begin()) {
					nxt[i] = std::make_pair(*std::prev(it1), 1ll * n * t + *std::prev(it1));
					continue;
				}

				auto it2 = std::lower_bound(ps.begin(), ps.end(), n);
				if (it2 != ps.begin()) {
					nxt[i] = std::make_pair(*std::prev(it2), 1ll * n * (t - 1) + *std::prev(it2));
					continue;
				}

				nxt[i] = std::make_pair((int) i + 1, 1ll);
			}	

			rep (i, 1, n) nxt[i].first = get(nxt[i].first);
		}
	}

	std::pair<int, i64> f[maxn][62];

	std::pair<int, i64> operator + (std::pair<int, i64> a, std::pair<int, i64> b) {
		i64 sum = (a.second + b.second) % mod;
		return std::make_pair(sum, b.first);
	}

	inline void get_f() {
		rep (i, 1, n) f[i][0] = nxt[i];

		rep (w, 1, 60) {
			rep (i, 1, n) {
				f[i][w] = f[i][w - 1] + f[f[i][w - 1].first][w - 1];
			}
		}
	}

	inline i64 go(int now, i64 k) {
		i64 res = 0;
		per (i, 60, 0) {
			if (st & (1 << i)) {
				(res += f[now][i].second) %= mod;
				now = f[now][i].first;
			}
		}
	}

	inline void solve() {
		get_nxt();
		get_f();

		while (q--) {
			i64 s, k; std::cin >> s >> k;
			(s += go(get(s), k)) %= mod;
			std::cout << s << "\n";
		}
	}
}

void solve() {
	
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
