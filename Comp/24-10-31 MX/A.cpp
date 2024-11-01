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

const int maxn = 3005;
const i64 mod = 1e9 + 7;

int n, k;
i64 pw2[maxn];

bool L[maxn], R[maxn];

bool ops[maxn];

bool a[maxn];
std::pair<i64, i64> mem[maxn][maxn][2][2];
std::pair<i64, i64> dfs(int now, int usd, bool rev, bool lim) {
	if (usd > k) return std::make_pair(0ll, 0ll);
	if (now > n - 1) return std::make_pair(i64{usd == k}, 0ll);

	auto &res = mem[now][usd][rev][lim];
	if (~res.second) return res;
	res = std::make_pair(0, 0);

	bool cur = (ops[now] ^ rev);

	bool mx = lim ? a[now] : 1;
	rep (i, 0, mx) {
		auto t = dfs(now + 1, usd + (i != cur), rev ^ (i != cur), (lim and (i == mx)));
		(res.first += t.first) %= mod;
		(res.second += (t.first * pw2[n - now - 1] * i + t.second) % mod) %= mod;
	}

	return res;
}	

inline i64 chkL(bool init) {
	int usd = 0;
	bool rev = init;
	rep (i, 1, n - 1) {
		if ((ops[i] ^ rev) != L[i]) {
			rev ^= 1;
			usd++;
		}
	}

	if (usd > k) return 0;

	i64 res = 0;
	rep (i, 0, n - 1) (res += 1ll * L[i] * (pw2[n - i - 1]) % mod) %= mod;

	return res;
}

inline i64 calc(bool rev) {
	rep (i, 0, n) rep (j, 0, k) rep (x, 0, 1) rep (y, 0, 1) mem[i][j][x][y] = std::make_pair(-1ll, -1ll);
	auto t = dfs(1, 0, rev, true);
	return (t.second + pw2[n - 1] * t.first) % mod;
}

// inline void subL() {
// 	int pos = n - 1;
// 	while (not L[pos]) L[pos--] = true;
// 	L[pos] = false;
// }

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n - 1) {
		char c; std::cin >> c;
		ops[i] = (c == 'R');
	}

	rep (i, 1, n) {
		char c; std::cin >> c;
		L[i - 1] = c - '0';
	}	

	// subL();
	
	rep (i, 1, n) {
		char c; std::cin >> c;
		R[i - 1] = c - '0';
	}

	pw2[0] = 1;
	rep (i, 1, n) pw2[i] = pw2[i - 1] * 2ll % mod;

	i64 ans = 0;
	///////////////////////// R //////////////////////////
	std::memcpy(a, R, sizeof R);
	(ans += calc(false)) %= mod;
	(ans += calc(true)) %= mod;

	///////////////////////// L //////////////////////////
	std::memcpy(a, L, sizeof L);
	(((ans -= calc(false)) %= mod) += mod) %= mod;
	(((ans -= calc(true)) %= mod) += mod) %= mod;

	i64 x = std::max(chkL(false), chkL(true));
	(ans += x) %= mod;

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	std::freopen("maze.in", "r", stdin);
	std::freopen("maze.out", "w", stdout);

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
