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

const int maxn = 100005;

int n;
i64 a[maxn];

inline int get(i64 x, int cnt) {
	i64 cur = 1;
	rep (i, 1, 1e9) {
		cur *= x;
		if (cur > cnt) return i;
	}
	return 0;
}


void solve() {
	std::freopen("coin.in", "r", stdin);
	std::freopen("coin.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	std::map<i64, int> up;
	rep (i, 1, n - 1) up[a[i + 1] / a[i]] ++;

	int ans = 1;
	int cnt = 0;
	for (auto _ : up) {
		i64 x; int c; std::tie(x, c) = _;
		cnt += c;
		ans = std::max(ans, get(x, cnt));
	}	
	std::cout << ans << "\n";
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