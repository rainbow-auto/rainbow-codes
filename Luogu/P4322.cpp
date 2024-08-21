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
#include <iomanip>

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

const int maxn = 2505;
const double eps = 1e-6;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int n, k;
double p[maxn], s[maxn];
double val[maxn];

double dp[maxn][maxn];
double pre[maxn];

int siz[maxn];
void dfs (int now, int fa) {
	dp[now][1] = val[now];
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dfs (t, now);

		rep (a, 1, std::min (siz[now], k)) { pre[a] = dp[now][a]; dp[now][a] = -1e9; }

		rep (a, 1, std::min (siz[now], k)) {
			rep (b, 0, std::min (siz[t], k)) {
				if (a + b > std::min (siz[now] + siz[t], k)) { break; }

				dp[now][a + b] = std::max (dp[now][a + b], pre[a] + dp[t][b]);
			}
		}
		siz[now] += siz[t];
	}
}

inline bool chk (double lim) {
	val[0] = 0;
	rep (i, 1, n) { val[i] = p[i] - s[i] * lim; }
	rep (i, 0, n) { rep (j, 1, k) { dp[i][j] = -1e9; } }

	dfs (0, -1);

	return dp[0][k] >= eps;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> k >> n; k ++; // 0 号点必须选
	rep (i, 1, n) {
		std::cin >> s[i] >> p[i];
		int r; std::cin >> r;
		addEdge (r, i);
	}

	double l = 0, r = 1e5; 
	double res = 0;

	while (r - l > eps) {
		double mid = (l + r) / 2.0;
		if (chk (mid)) { res = mid; l = mid; }
		else { r = mid; }
	}

	std::cout << std::fixed << std::setprecision (3) << res << "\n";

	return 0;
}
