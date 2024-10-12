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
// #define MultiTask lovely_fairytale

const int maxn = 100005;

int n, rt;
i64 a[maxn];

int fa[maxn];
std::bitset<maxn> vis;
i64 sum[maxn], cnt[maxn];

int lst[maxn], nxt[maxn];
// lst[u]: u 最后处理的节点

struct Node {
	int id;
	double f;

	friend bool operator < (Node a, Node b) {
		return a.f < b.f;
	}
};

void rainbow() {
	std::memset(fa, 0, sizeof fa);
	std::priority_queue<Node> q;
	
	rep (i, 1, n) {
		std::cin >> a[i];
		sum[i] = a[i]; cnt[i] = 1;
		if (i != rt) q.push(Node { i, 1.0 * sum[i] / cnt[i] });
	}

	rep (i, 1, n - 1) {
		int f, x; std::cin >> f >> x;
		fa[x] = f;
	}

	rep (i, 1, n) lst[i] = nxt[i] = i;

	vis.reset();
	rep (i, 1, n - 1) {
		int now; do {
		 	now = q.top().id; q.pop();
		} while (now == rt or vis[now]);

		int f = fa[now];
		while (vis[f]) fa[now] = f = fa[f]; // 路径压缩

		vis.set(now);
		nxt[lst[f]] = now;
		lst[f] = lst[now];

		cnt[f] += cnt[now]; sum[f] += sum[now];
		q.push(Node { f, 1.0 * sum[f] / cnt[f] });
	}

	i64 ans = 0;
	int now = rt;
	rep (i, 1, n) {
		ans += i * a[now];
		now = nxt[now];
	}

	std::cout << ans << "\n";
}

void solve() {
	while (true) {
		std::cin >> n >> rt;
		if (not (n | rt)) return;
		rainbow();
	}
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
