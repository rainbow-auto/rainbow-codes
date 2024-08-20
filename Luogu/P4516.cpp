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

const int maxn = 100005;
const int maxk = 105;
const i64 mod = 1e9 + 7;

i64 n, k;

int dp[maxn][maxk][2][2];
int pre[maxk][2][2];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

i64 siz[maxn];
void dfs (int now, int fa) {
	dp[now][0][0][0] = 1;
	dp[now][1][0][1] = 1;
	siz[now] = 1;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dfs (t, now);

		rep (a, 0, std::min (siz[now], k)) {
			for (int now1 : { 0, 1 }) {
			for (int now2 : { 0, 1 }) {
				pre[a][now1][now2] = dp[now][a][now1][now2]; dp[now][a][now1][now2] = 0;
			} }
		}

		rep (a, 0, std::min (siz[now], k)) {
			rep (b, 0, std::min (siz[t], k)) {
				if (a + b > std::min (siz[now] + siz[t], k)) { break; }

				for (int pre1 : { 0, 1 }) { // 被监控
				for (int pre2 : { 0, 1 }) { // 监控
				for (int t1 : { 0, 1 }) { // 被监控
				for (int t2 : { 0, 1 }) { // 监控
					if (not (t1 | pre2)) { continue; } // t 没有被监控

					int cur1 = (pre1 | t2); // 当前有没有被监控
					int cur2 = pre2; 

					dp[now][a + b][cur1][cur2] += (i64) pre[a][pre1][pre2] * (i64) dp[t][b][t1][t2] % mod;
					dp[now][a + b][cur1][cur2] %= mod;
				} } } }
			}
		}

		siz[now] += siz[t];
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> k;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	dfs (1, 0);

	std::cout << (dp[1][k][1][0] + dp[1][k][1][1]) % mod << "\n";

	return 0;
}
