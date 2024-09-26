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

const int maxn = 500005;

struct Edge {
	int u, v, w;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = ++cnt;
}

namespace Task1 {
	const int maxn = 8005;

	std::vector<int> sons[maxn];
	int tot;
	void dfs(int now, int fa) {
		sons[tot].push_back(now);
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa) continue;
			dis[t] = dis[now] + es[i].w;
			dfs(t, now);
		}
	}

	void solve() {
		rep (now, 1, n) {
			memset(dis, 0, sizeof dis);

			dis[now] = 0;
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				dis[t] = dis[now] + es[i].w;
				dfs(t, now);
			}

			rep (i, 1, n) mxd = std::max(mxd, dis[i]);

			
		}
	}
}

void solve() {
	
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
