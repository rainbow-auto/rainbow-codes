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

constexpr int maxn = 5005;

int n;
int a[maxn];
int cnt[maxn][maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) rep (j, i + 1, n) if (a[i] > a[j]) cnt[i][j]++;
	rep (i, 1, n) rep (j, 1, n) cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];

	auto qry = [&](int x1, int x2, int y1, int y2) -> int {
		if (x1 <= x2 and y1 <= y2) return cnt[x2][y2] - cnt[x1 - 1][y2] - cnt[x2][y1 - 1] + cnt[x1 - 1][y1 - 1];
		return 0;
	};

	i64 ans = 0;
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			if (a[i] < a[j]) {
				ans += qry(i + 1, j - 1, j + 1, n);
			}
		}
	}

	std::cout << ans << "\n";

	rep (i, 1, n) rep (j, 1, n) cnt[i][j] = 0;
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

	lookMem

	return 0;
}
