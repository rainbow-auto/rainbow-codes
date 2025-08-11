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
int f[maxn];

int gcd[maxn][maxn];
inline void init() {
	rep (i, 0, 5000) gcd[i][0] = gcd[0][i] = i;
	rep (i, 1, 5000) rep (j, 1, i) gcd[j][i] = gcd[i][j] = gcd[j][i % j];
}

inline bool chkmax(int& x, int y) { return x < y ? x = y, 1 : 0; }
inline bool chkmin(int& x, int y) { return x > y ? x = y, 1 : 0; }

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	int g = 0;
	rep (i, 1, n) g = gcd[g][a[i]];
	rep (i, 1, n) a[i] /= g;

	int ans = 0;
	rep (i, 1, n) ans += bool (a[i] > 1);

	int m = 0;
	rep (i, 1, n) chkmax(m, a[i]);

	rep (i, 0, m) f[i] = 0x3f3f3f3f; 
	rep (i, 1, n) f[a[i]] = 0;

	per (x, m, 1) rep (i, 1, n) chkmin(f[gcd[a[i]][x]], f[x] + 1);
	
	ans += std::max(f[1] - 1, 0);
	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	init();

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
