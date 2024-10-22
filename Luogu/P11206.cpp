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
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n;

namespace Task1 {
	std::vector<std::pair<int, int>> es;

	int p[maxn];

	inline void solve() {
		std::cin >> n;
		rep (i, 1, n - 1) {
			int u, v; std::cin >> u >> v;
			es.push_back(std::make_pair(u, v));
		}

		rep (i, 1, n) p[i] = i;
		do {
			bool flg = true;
			for (auto _ : es) {
				int u, v; std::tie(u, v) = _;
				flg &= (p[u] + p[v] <= n + 1);
			}
			if (flg) {
				rep (i, 1, n) std::cout << p[i] << " \n"[i == n];
			}
		} while (std::next_permutation(p + 1, p + n + 1));
	}
}

namespace Solution {
	struct Edge {
		int u, v;
		int pre;
	} es[maxn << 1];

	int last[maxn], cnt;

	inline void addEdge(int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}

	int fa[maxn], son[maxn];

	void dfs(int now) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa[now]) continue;
			fa[t] = now;
			dfs(t);
			son[now] ++;
		}
	}

	int ans[maxn];

	inline void clr() {
		std::memset(ans, 0, sizeof ans);
		std::memset(last, 0, sizeof last);
		cnt = 0;
		std::memset(fa, 0, sizeof fa);
		std::memset(son, 0, sizeof son);
	}

	inline void solve() {
		clr();

		std::cin >> n;
		rep (i, 1, n - 1) {
			int u, v; std::cin >> u >> v;
			addEdge(u, v); addEdge(v, u);
		}

		dfs(1);

		std::deque<int> rst;
		rep (i, 1, n) rst.push_back(i);

		std::queue<int> q;
		rep (i, 1, n) if (son[i] == 0) q.push(i);

		while (not q.empty()) {
			int now = q.front(); q.pop();

			if (not ans[now]) { 
				ans[now] = rst.back(); rst.pop_back(); 
				if (fa[now] and not ans[fa[now]]) { ans[fa[now]] = rst.front(); rst.pop_front(); }
			}

			if (fa[now]) {
				son[fa[now]]--;
				if (not son[fa[now]]) q.push(fa[now]);
			}
		}		

		rep (i, 1, n) std::cout << ans[i] << " \n"[i == n];
	}
}

void solve() {
	// Task1::solve();
	Solution::solve();
}

bool MemED;
int main() {
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
