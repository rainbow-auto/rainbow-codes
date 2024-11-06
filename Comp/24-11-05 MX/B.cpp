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
#define MultiTask lovely_fairytale

const int maxn = 2000005;

int n, k; 

struct Node {
	int l, r;
	int b;
} a[maxn];

namespace Task1 {
	int b[maxn][2];
	int f[maxn][2];

	inline void solve() {
		std::memset(b, 0, sizeof b);
		std::memset(f, 0, sizeof f);

		int R = 0;
		rep (i, 1, n) {
			rep (j, a[i].l, a[i].r) b[j][a[i].b] = i;
			R = std::max(R, a[i].r);
		}

		f[0][0] = 0;
		f[0][1] = -0x3f3f3f3f;
		rep (i, 1, R) {
			rep (j, 0, 1) {
				f[i][j] = f[i - 1][j] + (b[i][j] and (b[i - 1][j] != b[i][j]));
				if (i >= k) f[i][j] = std::max(f[i][j], f[i - k][j ^ 1] + (b[i][j] != 0));
			}
		}

		int ans = std::max(f[R][0], f[R][1]);

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) {
		std::cin >> a[i].l >> a[i].r >> a[i].b;
		a[i].b--;
	}

	Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// std::freopen("move.in", "r", stdin);
	// std::freopen("move.out", "w", stdout);

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
