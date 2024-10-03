#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 5005;

int n;
int x, y;

int a[maxn], b[maxn], c[maxn], d[maxn];

// namespace Task1 {
// 	const int maxn = 505;

// 	bool f[maxn][maxn][maxn];

// 	bool in(int x, int l, int r) {
// 		return l <= x and x <= r;
// 	}

// 	void solve() {
// 		f[0][0][0] = true;

// 		rep (i, 1, n) {
// 			rep (j, 0, i - 1) {
// 				db << i << " " << j << ": ";
// 				int l = 0x3f3f3f3f, r = 0;
// 				rep (dx, 0, j) {
// 					f[i][j][dx] |= f[i - 1][j][dx];
// 					if (in(dx, a[i], b[i]) and in(j - dx, c[i], d[i])) {
// 						l = std::min(l, (int) dx);
// 						r = std::max(r, (int) dx);
// 						f[i][j + 1][dx] |= f[i - 1][j][dx];
// 						f[i][j + 1][dx + 1] |= f[i - 1][j][dx];
// 					}
// 				}
// 				db << l << " " << r << "\n";
// 			}
// 		}

// 		per (j, n, 0) {
// 			rep (dx, 0, j) {
// 				if (f[n][j][dx]) {
// 					std::cout << j << "\n";
// 					return;
// 				}
// 			}
// 		}
// 	}
// }

// namespace Task2 {
	std::bitset<maxn> f[maxn], pre[maxn];

	std::pair<int, int> mrg(int l1, int r1, int l2, int r2) {
		if (l1 <= r1 and l2 <= r2) {
			return std::make_pair(std::max(l1, l2), std::min(r1, r2));
		} else {
			return std::make_pair(0x3f3f3f3f, 0);
		}
	}

	std::bitset<maxn> s1[maxn], s0[maxn];
	void init() {
		s1[0].set(0);
		rep (i, 1, n) {
			s1[i] = s1[i - 1];
			s1[i].set(i);
		}

		s0[0] = s1[n];
		s0[0].flip(0);
		rep (i, 1, n) {
			s0[i] = s0[i - 1];
			s0[i].flip(i);
		}
	}

	void cut(std::bitset<maxn>& x, int l, int r) {
		if (l == 0) {
			x &= s1[r];	
		} else {
			x &= s1[r];
			x &= s0[l - 1];
		}
	}

	void solve() {
		f[0][0] = true;

		init();

		rep (i, 1, n) {
			rep (j, 0, i - 1) pre[j] = f[j];

			rep (j, 0, i - 1) {
				auto rg = mrg(a[i], b[i], j - d[i], j - c[i]);
				rg.second = std::min(rg.second, (int) j);

				if (rg.first > rg.second) continue;
				if (rg.first < 0 and rg.second < 0) continue;

				rg.first = std::max(rg.first, 0); 
				rg.second = std::max(rg.second, 0);

				db << rg.first << " " << rg.second << "\n"; 

				auto p = pre[j];
				cut(p, rg.first, rg.second);

				f[j + 1] |= p;
				f[j + 1] |= (p << 1);
			}
		}

		per (j, n, 0) {
			if (f[j].any()) {
				std::cout << j << "\n";
				return;
			}
		}
	}
// }

void MisakaMikoto() {
	std::freopen("A.in", "r", stdin);
	
	std::cin >> n;
	std::cin >> x >> y;

	rep (i, 1, n) std::cin >> a[i] >> b[i] >> c[i] >> d[i];
	rep (i, 1, n) {
		a[i] -= x; b[i] -= x;
		c[i] -= y; d[i] -= y;
	}

	// Task1::solve();
	solve();

	lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		MisakaMikoto();
	}

	return 0;
}
