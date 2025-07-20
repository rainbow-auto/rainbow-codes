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

constexpr int maxn = 200005;

int n, m;
std::vector<i64> a[maxn];

i64 p[maxn];

std::vector<i64> f[maxn];
bool chk(i64 x) {
	rep (i, 0, n) {
		f[i].resize(m + 1);
		rep (j, 0, m) f[i][j] = -0x3f3f3f3f3f3f3f3f;
	}

	if (a[1][1] + x >= p[1]) {
		f[1][1] = (a[1][1] + x - p[1]);
	} else {
		return false;
	}
	
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (i == 1 and j == 1) continue;
			i64 u = f[i - 1][j];
			i64 l = f[i][j - 1];

			if (u + a[i][j] >= p[i + j - 1]) f[i][j] = std::max(f[i][j], u + a[i][j] - p[i + j - 1]);
			if (l + a[i][j] >= p[i + j - 1]) f[i][j] = std::max(f[i][j], l + a[i][j] - p[i + j - 1]);
		}
	}

	if (f[n][m] == -0x3f3f3f3f3f3f3f3f) return false;
	return true;
}

void solve() {
	std::cin >> n >> m;
	
	rep (i, 0, n) a[i].resize(m + 1);
	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];	
		}
	}

	rep (i, 1, n + m - 1) std::cin >> p[i];

	i64 l = 0, r = 1e18;
	i64 ans = 0;

	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (chk(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

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
