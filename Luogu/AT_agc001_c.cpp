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

const int maxn = 2005;

int n, k;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int dfs (int now, int fa, int currdis, int lim) {
	int tot = 0;
	if (currdis <= lim) { tot++; }
	else { return 0; }	

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		tot += dfs (t, now, currdis + 1, lim);
	}
	return tot;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> k;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v); addEdge (v, u);
	}

	if (k & 1) {
		int ans = 0;
		rep (i, 1, cnt) {
			if (i & 1) { continue; } // 正向边和反向边枚举一个即可

			int curr = 0;
			curr += dfs (es[i].u, es[i].v, 0, ((k - 1) >> 1));
			curr += dfs (es[i].v, es[i].u, 0, ((k - 1) >> 1));

			ans = std::max (ans, curr);
		}

		std::cout << n - ans << "\n";
	} else {
		int ans = 0;
		rep (i, 1, n) {
			int curr = dfs (i, 0, 0, (k >> 1));
			ans = std::max (ans, curr);
		}
		
		std::cout << n - ans << "\n";
	}

	return 0;
}
