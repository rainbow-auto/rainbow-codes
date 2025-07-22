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

constexpr int maxn = 305;
constexpr i64 mod = 1e9 + 7;
constexpr int maxB = 100005;

int n, k;
i64 f[maxn][maxB];

int tot;
std::map<int, int> bel;
i64 v[maxB], len[maxB];

void solve() {
	std::cin >> n >> k;

	for (int l = 1, r; l <= n; l = r + 1) {
		r = std::min(n / (n / l), n);
		++tot;
		len[tot] = (r - l + 1);
		bel[r] = tot;
		v[tot] = r;
	}

	rep (i, 1, tot) f[0][i] = 1;
	rep (i, 1, k) {
		rep (j, 1, tot) {
			f[i][j] = (f[i][j - 1] + 1ll * len[j] * f[i - 1][bel[n / v[j]]] % mod) % mod;
		}
	}

	std::cout << f[k][tot] << "\n";
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
