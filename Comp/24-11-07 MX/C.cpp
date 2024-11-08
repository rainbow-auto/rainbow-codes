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

const int maxn = 205;
const int maxv = 2000005;

int n, k, w;
i64 f[maxn][maxn];

int c[maxn], m[maxn];
i64 p[maxv];

inline i64 calc(i64 m) {
	if (m >= k) return p[m];
	return p[k] - (k - m) * w;
}

void solve() {
	std::freopen("basketball.in", "r", stdin);
	std::freopen("basketball.out", "w", stdout);

	std::cin >> n >> k >> w;
	rep (i, 1, n) std::cin >> c[i];
	rep (i, 1, n) std::cin >> m[i];

	rep (i, k, (k << 1) - 2) std::cin >> p[i];

	rep (i, 1, n) {
		f[i][i] = calc(m[i]);
	}

	rep (len, 2, n) {
		rep (l, 1, n) {
			int r = l + len - 1;
			if (c[l] == c[r]) {
				f[l][r] = calc(m[l] + m[r]) + f[l + 1][r - 1];
			}

			rep (i, l, r - 1) {
				f[l][r] = std::max(f[l][r], f[l][i] + f[i + 1][r]);
			}
		}
	}

	std::cout << f[1][n] << "\n";
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
