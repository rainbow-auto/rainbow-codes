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

constexpr int maxn = 105;

char c[maxn][maxn];

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::array<int, maxn> s; s.fill(0);

	rep (i, 1, n) {
		rep (j, 1, m) std::cin >> c[i][j];
	}

	rep (i, 1, m) {
		std::array<int, 2> cnt; cnt.fill(0);
		rep (j, 1, n) {
			cnt[c[j][i] - '0'] ++;
		}

		// dbg(cnt[0]);
		// dbg(cnt[1]);

		int flg = 0;
		if (cnt[0] > cnt[1]) flg = 1;
		else flg = 0;

		rep (j, 1, n) if (flg == (c[j][i] - '0')) s[j]++;
	}

	int mx = 0;
	rep (i, 1, n) mx = std::max(mx, s[i]);
	
	rep (i, 1, n) if (s[i] == mx) std::cout << i << " ";
	std::cout << "\n";
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
