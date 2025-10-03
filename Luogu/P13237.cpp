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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxm = 10;
constexpr int maxn = 105;

int n, m;
int a[maxn][maxm];

int p[maxm];

int T;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) rep (j, 1, m) std::cin >> a[i][j];

	rep (i, 1, m) p[i] = i;

	int ans = 0;
	do {
		int ansnow = 0;
		rep (i, 1, n) {
			int cur = 0;
			int mx = 0;
			rep (j, 1, m) {
				cur += a[i][p[j]];
				mx = std::max(mx, cur);
			}
			ansnow += mx;
		}
		ans = std::max(ans, ansnow);
	} while (std::next_permutation(p + 1, p + m + 1));

	std::cout << "Case #" << (++T) << ": " << ans << "\n";
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
