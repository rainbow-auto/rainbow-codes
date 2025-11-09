#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 200005;

int n;
int a[maxn];

int c[maxn];
i64 f[maxn][2];

void solve() {
	std::cin >> n;

	i64 ans = 1;
	rep (i, 1, n) {
		std::cin >> a[i];
		ans += a[i] - 1;
		
		c[i] = std::min(a[i] - 1,  i - 2) - 1;
	}

	rep (i, 2, n) {
		f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = f[i - 1][0] + c[i];
	}

	std::cout << ans - std::max(f[n][0], f[n][1]) << "\n";

	// clr
	rep (i, 1, n) f[i][0] = f[i][1] = 0;
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
