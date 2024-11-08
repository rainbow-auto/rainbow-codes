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

const int maxn = 5005;
const i64 mod = 998244353;

int n, k;
bool col[maxn]; // 颜色 | 0 : a | 1 : b

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

i64 dp[maxn][maxn]; // dp[u][i] : subtree (u) 中组成 i 对颜色不同的祖孙关系的方案数
i64 pre[maxn];

int siz[maxn];
i64 count[maxn][2]; // count[u][0 / 1] : subtree (u) 中颜色为 0 / 1 的节点的数量  
void dfs (int now, int fa) {
	siz[now] = 1;
	dp[now][0] = 1; 
	count[now][col[now]] = 1;
 
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dfs (t, now);

		rep (x, 0, std::min (k, siz[now])) { pre[x] = dp[now][x]; dp[now][x] = 0; }

		rep (x, 0, std::min (k, siz[now])) {
			rep (y, 0, std::min (k, siz[t])) {
				if (x + y > std::min (k, siz[now] + siz[t])) { break; }
				dp[now][x + y] += pre[x] * dp[t][y] % mod;
				dp[now][x + y] %= mod;
			}
		}

		siz[now] += siz[t];
		count[now][0] += count[t][0];
		count[now][1] += count[t][1];
	}

	per (i, count[now][col[now] ^ 1], 0) { 
		dp[now][i + 1] += dp[now][i] * (count[now][col[now] ^ 1] - i) % mod; // 显然有 i 个颜色为 col[now] ^ 1 的点已经被选过了
		dp[now][i + 1] %= mod;
	}
}

i64 ksm (i64 a, i64 b) {
	i64 res = 1; a %= mod;
	while (b) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod; b >>= 1;
	}
	return res;
}

i64 fac[maxn];
i64 ifac[maxn];
inline void init () {
	fac[0] = 1;
	rep (i, 1, n) { fac[i] = fac[i - 1] * i % mod; }
	ifac[n] = ksm (fac[n], mod - 2);
	per (i, n - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

inline i64 C (i64 n, i64 m) { // = n \choose m
	if (n - m < 0) { return 0; }
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

i64 f[maxn];
i64 g[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n; 
	k = (n >> 1);

	rep (i, 1, n) { char c; std::cin >> c; col[i] = (c == '0'); }

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v); addEdge (v, u);
	}

	dfs (1, 0);

	init ();
	rep (i, 0, k) { g[i] = dp[1][i] * fac[k - i] % mod; } // 固定其中 \frac {n - 2k} {2} 个点

	rep (i, 0, k) {
		rep (j, i, k) {
			f[i] += ((((j - i) & 1) ? -1 : 1) * C (j, i) * g[j] % mod + mod) % mod;
			f[i] += mod; f[i] %= mod;
		}
		std::cout << f[i] << "\n";
	}

	return 0;
}
