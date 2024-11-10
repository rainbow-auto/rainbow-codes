#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = unsigned long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 400005;
const i64 mod = 1e9 + 7;

i64 n, q;
i64 m;
bool a[maxn];

namespace Solution {
	inline int get(i64 pos) {
		return (pos - 1) % n + 1;
	}

	std::pair<int, i64> nxt[maxn];
	inline void get_nxt() {
		std::vector<int> ps;
		rep (i, 1, n) a[n + i] = a[i];
		rep (i, 1, n << 1) if (a[i]) ps.push_back(i);

		if (m <= n) {
			rep (i, 1, n) {
				auto it = std::upper_bound(ps.begin(), ps.end(), i + m);
				if (it == ps.begin() or *std::prev(it) <= i) nxt[i] = std::make_pair(get(i + 1), 1ll);
				else nxt[i] = std::make_pair(get(*std::prev(it)), (*std::prev(it) - i) % mod);
			}
		} else {
			rep (i, 1, n) {
				int R = get(i + m);
				i64 t = 1ll * (m - (n - i) - R) / n;

				auto it1 = std::upper_bound(ps.begin(), ps.end(), R);
				if (it1 != ps.begin()) {
					nxt[i] = std::make_pair(get(*std::prev(it1)), ((n - i) + (1ll * n * t % mod + get(*std::prev(it1))) % mod) % mod);
					continue;
				}

				// auto it2 = std::upper_bound(ps.begin(), ps.end(), n);
				if (t > 0 and not ps.empty()) {
					int p = ps.back();
					nxt[i] = std::make_pair(get(p), ((n - i) + (1ll * n * (t - 1) % mod + get(p)) % mod) % mod);
					continue;
				}        

				nxt[i] = std::make_pair(get(i + 1), 1ll);
			}	
		}

		// rep (i, 1, n) db << "(" << i << " -> " << nxt[i].first << " | " << nxt[i].second << ")\n";
	}

	std::pair<int, i64> f[maxn][62];

	std::pair<int, i64> operator + (std::pair<int, i64> a, std::pair<int, i64> b) {
		i64 sum = (a.second  % mod + b.second % mod) % mod;
		return std::make_pair(b.first, sum);
	}

	const int Lg2 = 60;

	inline void get_f() {
		rep (i, 1, n) f[i][0] = nxt[i];

		rep (w, 1, Lg2) {
			rep (i, 1, n) {
				f[i][w] = f[i][w - 1] + f[f[i][w - 1].first][w - 1];
			}
		}
	}

	inline i64 go(int now, i64 k) {
		i64 res = 0;
		per (i, Lg2, 0) {
			if (k & (1ll << i)) {
				(res += f[now][i].second % mod) %= mod;
				now = f[now][i].first;
			}
		}
		return res;
	}

	inline void solve() {
		get_nxt();
		get_f();

		while (q--) {
			i64 s, k; std::cin >> s >> k;
			// db << get(s) << "\n";
			(s = s % mod + go(get(s), k)) %= mod;
			std::cout << s << "\n";
		}
	}
}

void solve() {
	std::cin >> n >> m >> q;
	rep (i, 1, n) {
		char ch; std::cin >> ch;
		a[i] = ch - '0';
	}

	Solution::solve();	
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
