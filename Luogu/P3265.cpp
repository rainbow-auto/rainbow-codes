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

constexpr int maxn = 505;
constexpr int mod = 998244353;

int n, m;

using Vector = std::array<i64, maxn>;
std::pair<i64, Vector> a[maxn];
Vector b[maxn];

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) {
	return ksm(x, mod - 2);
}

inline bool ins(Vector a) {
	rep (i, 1, m) {
		if (not a[i]) continue;
		if (not b[i][i]) return b[i] = a, true;

		i64 c = a[i] * inv(b[i][i]) % mod;
		rep (j, i, m) (((a[j] -= c * b[i][j] % mod) %= mod) += mod) %= mod;
	}

	return false;
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) std::cin >> a[i].second[j];
	}

	rep (i, 1, n) std::cin >> a[i].first;

	std::sort(a + 1, a + n + 1);

	i64 ans = 0;
	int tot = 0;

	rep (i, 1, n) {
		// db << "ins: ";
		// rep (j, 1, m) db << a[i].second[j] << " "; dbendl;
		if (ins(a[i].second)) {
			tot++;
			ans += a[i].first;
		}

		// rep (j, 1, m) rep (k, 1, m) db << b[j][k] << " \n"[k == m];
		// dbendl;
	}
	
	std::cout << tot << " " << ans << "\n";
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
