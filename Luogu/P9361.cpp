#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;
constexpr int maxm = 5;

int n, m;
int p[maxm][maxn];
int pos[maxm][maxn];

int f[21][maxm][maxn][maxm];
inline bool chkmin(int &x, int y) {
	return x > y ? (x = y, 1) : 0;
}

inline void init() {
	std::memset(f, 0x3f, sizeof f);

	rep (c, 0, m - 1) {
		rep (d, 0, m - 1) {
			int to = 0x3f3f3f3f;
			per (i, n, 1) {
				int cur = p[c][i];
				chkmin(to, pos[d][cur]);
				f[0][c][i][d] = to;
			}
		}
	}

	rep (k, 1, 20) {
		rep (c, 0, m - 1) {
			rep (d, 0, m - 1) {
				rep (i, 1, n) {
					rep (t, 0, m - 1) {
						// c -> t -> d
						int mid = f[k - 1][c][i][t];
						chkmin(f[k][c][i][d], f[k - 1][t][mid][d]);
					}
				}
			}
		}
	}
}

bool chk(std::array<int, maxm> cur, int y) {
	rep (c, 0, m - 1) if (cur[c] <= pos[c][y]) return true;
	return false;
} 

inline int qry(int x, int y) {
	std::array<int, maxm> cur;
	rep (c, 0, m - 1) cur[c] = pos[c][x];

	if (chk(cur, y)) return 1;

	int res = 0;
	per (k, 20, 0) {
		std::array<int, maxm> nxt; nxt.fill(0x3f3f3f3f);
		rep (c, 0, m - 1) {
			rep (d, 0, m - 1) {
				chkmin(nxt[d], f[k][c][cur[c]][d]);
			}
		}

		if (not chk(nxt, y)) {
			cur = nxt;
			res += (1 << k);
		}
	}

	if (res > 1e6) return -1;
	return res + 2; // 最后 nxt 可到 y，1 步从 cur 到 nxt，一步是 nxt 到 y
}

void solve() {
	std::cin >> n >> m;
	rep (c, 0, m - 1) rep (i, 1, n) {
		std::cin >> p[c][i];
	}

	rep (c, 0, m - 1) rep (i, 1, n) {
		pos[c][p[c][i]] = i;
	}

	init();

	int q; std::cin >> q;
	while (q--) {
		int x, y; std::cin >> x >> y;
		std::cout << qry(x, y) << "\n";
	}
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
