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

constexpr int maxn = 45;
constexpr int maxm = 205;

constexpr int mod = 998244353;

int n, m, K;

i64 v[maxm];
std::array<std::array<std::array<int, maxn>, maxn>, maxn> f[2];
// i64 f[maxm][maxn][maxn][maxn]; 

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) {
	return ksm(x, mod - 2);
}

i64 fac[maxn], ifac[maxn];
inline void init() {
	int N = 30;
	fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
	ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

i64 con[maxn];

void solve() {
	std::cin >> n >> m >> K;
	rep (i, 0, m) {
		std::cin >> v[i];
	}

	init();

	f[0][0][0][0] = 1;
	rep (i, 0, m + 5) {
		con[0] = 1; 
		rep (j, 1, n) con[j] = con[j - 1] * v[i] % mod;
		rep (j, 0, n) (con[j] *= ifac[j]) %= mod;

		rep (j, 0, n) { // used
			rep (k, 0, j) { // 1
				rep (l, 0, j) { // 进位
					rep (c, 0, n - j) {
						if ((l + c) & 1) {
							// db << "to " << j + c << " " << k + 1 << " " << ((c + l) >> 1) << "\n";
							(f[(i + 1) & 1][j + c][k + 1][(c + l) >> 1] += f[i & 1][j][k][l] * con[c] % mod) %= mod; 
						} else {
							// db << "to " << j + c << " " << k  << " " << ((c + l) >> 1) << "\n";
							(f[(i + 1) & 1][j + c][k][(c + l) >> 1] += f[i & 1][j][k][l] * con[c] % mod) %= mod;
						}
					}
				}
			}
		}

		for (auto &x : f[i & 1]) for (auto &y : x) y.fill(0);
	}
	
	i64 res = 0;
	rep (i, 0, K) (res += f[(m + 5 + 1) & 1][n][i][0]) %= mod;
	std::cout << res * fac[n] % mod << "\n";
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
