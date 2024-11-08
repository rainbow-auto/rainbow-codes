#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 25;
const i64 mod = 1e9 + 9;

int n, m;
int k, city[maxn];
i64 d;

struct Matrix {
	i64 mat[maxn][maxn];

	Matrix () {
		memset (mat, 0, sizeof (mat));
	}

	inline void identity () {
		rep (i, 1, n) { mat[i][i] = 1; }
	}

	i64* operator [] (int i) { return mat[i]; }

	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix (res);
		rep (i, 1, n) {
			rep (k, 1, n) {
				rep (j, 1, n) {
					res[i][j] += a[i][k] * b[k][j];			
					res[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

inline Matrix ksm (const Matrix& a, i64 b) {
	Matrix res; res.identity ();
	Matrix base = a;
	while (b) {
		if (b & 1) { res = res * base; }
		base = base * base; b >>= 1;
	}
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	// freopen ("loong.in", "r", stdin);
	// freopen ("loong.out", "w", stdout);

	std::cin >> n >> m >> k >> d;

	rep (i, 1, k) { std::cin >> city[i]; }

	Matrix org;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		org[u][v] = org[v][u] = 1;
	}

	i64 ans = 0;

	rep (S, 0, (1 << k) - 1) {
		Matrix curr = org;
		
		int popcnt = 0;
		rep (i, 1, k) {
			if (not (S & (1 << (i - 1)))) { continue; }
			popcnt ++;
			
			rep (j, 1, n) { curr[city[i]][j] = curr[j][city[i]] = 0; }
		}

		curr = ksm (curr, d - 1);

		i64 sum = 0;
		rep (i, 1, n) {
			rep (j, 1, n) {
				sum += curr[i][j]; sum %= mod;
			}
		}

		ans += ((popcnt & 1) ? -1ll : 1ll) * sum % mod;
		ans %= mod; ans += mod; ans %= mod;
	} 

	std::cout << ans << "\n";

	return 0;
}
