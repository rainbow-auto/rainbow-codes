#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 200005;

struct Graph {
	struct Edge {
		int u, v;
		int pre;
		int w;
	} es[maxn << 1];

	int last[maxn], cnt;

	inline void addEdge (int u, int v, int w) {
		es[++cnt] = Edge { u, v, last[u], w };
		last[u] = cnt;
	} 

	inline void clear () {
		cnt = 0;
		memset (last, 0, sizeof (last));
	}
} G;

int C, T;
int n, m;

int val[maxn];
int Tval, Fval, Uval;

/*
	val:
	0 : U
	n + 1 : T
	-(n + 1) : F
	1 ~ n : = val
	-1 ~ -n : = !val
*/

bool isConstant (int x) { return x == Tval or x == Fval or x == Uval; }

int val_try[maxn]; // 尝试赋的值

int belong[maxn], tot; // 属于那个连通块 | 连通块数量
int siz[maxn]; // 连通块大小

bool erase[maxn]; // 连通块是否被消除

void dfs (int now) {
	belong[now] = tot;
	siz[belong[now]] ++;

	for (int i = G.last[now]; i; i = G.es[i].pre) {
		int t = G.es[i].v;
		if (belong[t]) { continue; }

		val_try[t] = val_try[now] * G.es[i].w;
		dfs (t);
	}
}

int eqcnt[maxn]; // 连通块中val_try == val的个数
int all[maxn];

inline void clear () {
	for (int i = 1; i <= n; i++) { val[i] = i; }
	G.clear ();

	memset (val_try, 0, sizeof (val_try));
	memset (belong, 0, sizeof (belong)); tot = 0;
	memset (siz, 0, sizeof (siz));
	memset (erase, 0, sizeof (erase));
	memset (eqcnt, 0, sizeof (eqcnt));
	memset (all, 0, sizeof (all));
}

int main () {
	fastread

	std::cin >> C >> T;

	while (T--) {
		std::cin >> n >> m;

		clear ();

		Tval = n + 1;
		Fval = -Tval;

		for (int i = 1; i <= m; i++) {
			char v; std::cin >> v;

			if (v == 'T') {
				int x; std::cin >> x;
				val[x] = Tval;
			} else if (v == 'F') {
				int x; std::cin >> x;
				val[x] = Fval;
			} else if (v == 'U') {
				int x; std::cin >> x;
				val[x] = Uval;
			} else if (v == '+') {
				int x, y; std::cin >> x >> y;
				val[x] = val[y]; // 路径压缩
			} else if (v == '-') {
				int x, y; std::cin >> x >> y;
				val[x] = -val[y]; // 路径压缩
			}
		}	

		for (int i = 1; i <= n; i++) {
			if (isConstant (val[i])) { continue; }

			if (val[i] > 0) {
				G.addEdge (i, val[i], 1);
				G.addEdge (val[i], i, 1);
			}

			if (val[i] < 0) {
				G.addEdge (i, -val[i], -1);
				G.addEdge (-val[i], i, -1);
			}
 		}

		// 1. 遍历, 找出连通块, 并且尝试进行赋值 (钦定每个连通块中第一个被遍历到的是T)
		for (int i = 1; i <= n; i++) {
			if (not belong[i]) {
				tot ++;
				val_try[i] = Tval;
				dfs (i);
			}
		}

		// 2. 把含有U的连通块先删掉
		for (int i = 1; i <= n; i++) {
			if (val[i] == Uval) { erase[belong[i]] = true; }
		}

		// 3. 通过赋值的结果 val_try[] 检测逻辑的正确性
		for (int now = 1; now <= n; now++) {
			if (isConstant (val[now])) { continue; }

			for (int i = G.last[now]; i; i = G.es[i].pre) {
				int t = G.es[i].v;
				
				if (val_try[t] != val_try[now] * G.es[i].w) { erase[belong[now]] = true; break; }
			}
		}

		// 4. 看最后的值是定值的点, 我们给它赋的初值是否等于末值

		// 4.1. 统计每个连通块中有多少我们给它赋的初值等于末值的
		for (int i = 1; i <= n; i++) {
			if (not isConstant (val[i])) { continue; }
			if (val[i] == Uval) { continue; }

			if (val[i] == val_try[i]) { eqcnt[belong[i]] ++; }
			all[belong[i]] ++;
		}

		// 4.2 eqcnt[i]要么为0 (全都正好相反), 要么为all[i] (全都正好相等), 其他的删掉
		for (int i = 1; i <= tot; i++) {
			if (eqcnt[i] != all[i] and eqcnt[i] != 0) { erase[i] = true; }
		}

		int ans = 0;

		// 5. 统计答案 (删掉的连通块都是U)
		for (int i = 1; i <= tot; i++) {
			if (erase[i]) { ans += siz[i]; }
		}

		std::cout << ans << "\n";

	}

	return 0;
}
