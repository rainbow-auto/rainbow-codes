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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 1000005;
const int maxB = 63;

int n;
int to[maxn];

int f[maxn][maxB];
inline void init() {
	rep (i, 1, n) f[i][0] = to[i];

	rep (b, 1, maxB - 1) {
		rep (i, 1, n) {
			f[i][b] = f[f[i][b - 1]][b - 1];
		}
	}
}

inline int qry(int now, i64 k) {
	per (b, maxB - 1, 0) {
		if (k & (1ll << b)) now = f[now][b];
	}
	return now;
}

int cnt[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> to[i];

	init();

	std::memset(cnt, 0, sizeof cnt);
	i64 ans = 0;
	rep (i, 1, n) {
		int t = qry(i, 1e9);
		ans += (i - 1) - cnt[t];
		cnt[t]++;
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	std::freopen("a.in", "r", stdin);
	std::freopen("a.out", "w", stdout);

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
