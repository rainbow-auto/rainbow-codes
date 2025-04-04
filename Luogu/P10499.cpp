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

const int maxn = 33;

int n, m;

bool a[maxn][maxn];
inline i64 gauss() {
	int cur = 0;
	rep (i, 1, n) {
		int t = cur + 1;
		rep (j, cur + 1, n) if (a[j][i]) t = j;
		if (not a[t][i]) continue;
		cur++;
		std::swap(a[t], a[cur]);
		rep (j, cur + 1, n) per (k, n + 1, i) a[j][k] ^= (a[cur][k] & a[j][i]);
	}

	if (cur < n) {
		int cnt = 0;
		rep (i, cur + 1, n) {
			if (a[i][n + 1]) return -1;
			cnt++;
		} 
		return (1ll << cnt);
	}
	return 1;
}

void solve() {
	std::memset(a, 0, sizeof a);

	std::cin >> n;

	rep (i, 1, n) {
		int x; std::cin >> x;
		a[i][n + 1] = x;
	}
	rep (i, 1, n) {
		int x; std::cin >> x;
		a[i][n + 1] ^= x;
	}

	rep (i, 1, n) a[i][i] = true;

	while (true) {
		int x, y; std::cin >> x >> y;
		if (not x and not y) break;
		a[y][x] = true;
	}

	i64 res = gauss();
	if (~res) std::cout << res << "\n";
	else std::cout << "Oh,it's impossible~!!\n";
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
