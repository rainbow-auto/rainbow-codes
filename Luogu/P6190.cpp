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

int n, m;
int k;

i64 g[maxn][maxn];
std::vector<std::tuple<int, int, i64>> es;

struct Matrix {
	std::array<std::array<i64, maxn>, maxn> a;
	
	inline void clr() {
		for (auto &x : a) x.fill(0x3f3f3f3f3f3f3f3f);
	}

	std::array<i64, maxn>& operator[](int i) { return a[i]; }
	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix c; c.clr();
		rep (i, 0, maxn - 1) rep (k, 0, maxn - 1) rep (j, 0, maxn - 1) {
			c[i][j] = std::min(c[i][j], a[i][k] + b[k][j]);
		}
		return c;
	}
};

Matrix ksm(Matrix a, i64 k) {
	Matrix res = a; k--;
	if (k > 0) for (; k; (a = a * a), k >>= 1) if (k & 1) res = res * a;
	return res;
}

void solve() {
	std::cin >> n >> m >> k;

	std::memset(g, 0x3f, sizeof g);
	rep (i, 1, n) g[i][i] = 0;

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		g[u][v] = std::min(g[u][v], w);
		es.push_back(std::tie(u, v, w));
	}
	
	rep (k, 1, n) {
		rep (i, 1, n) {
			rep (j, 1, n) {
				g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	Matrix a; a.clr();
	rep (i, 1, n) a[i][i] = 0;

	for (auto [u, v, w] : es) {
		rep (i, 1, n) {
			rep (j, 1, n) {
				a[i][j] = std::min(a[i][j], g[i][u] + g[v][j] - w);
			}
		}
	}

	if (k > 0) {
		a = ksm(a, k);
		std::cout << a[1][n] << "\n";
	} else {
		std::cout << g[1][n] << "\n";
	}
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
