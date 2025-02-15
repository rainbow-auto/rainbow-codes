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

const int maxn = 4005;

int n;
std::pair<int, int> a[maxn];

i64 f[maxn][maxn];

inline bool chkmx(i64 &x, i64 y) {
	return y > x ? (x = y, 1) : 0;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i].first >> a[i].second;
	
	std::sort(a + 1, a + n + 1, [](auto x, auto y) -> bool { return x > y; });

	std::memset(f, -0x3f, sizeof f);
	f[0][1] = 0;

	rep (i, 1, n) {
		rep (j, 0, n) {
			chkmx(f[i][j], f[i - 1][j]);
			if (j >= 1) chkmx(f[i][std::min(j - 1 + a[i].first, (i64) n)], f[i - 1][j] + a[i].second);
		}
	}

	i64 ans = 0;
	rep (i, 0, n) chkmx(ans, f[n][i]);

	std::cout << ans << "\n";
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
