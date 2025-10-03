#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;
using u64 = unsigned long long;

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

constexpr int maxn = 300005;

int n, m, k;

int d[maxn];
i64 vup[maxn], vdn[maxn];
i64 vupsum[maxn], vdnsum[maxn];

std::vector<std::pair<int, int>> es[maxn];

std::map<std::pair<int, int>, i64> dis;
std::map<std::pair<int, int>, bool> vis;

struct Node {
	std::pair<int, int> id;
	i64 dis;
	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};

i64 ans[maxn];

inline void dij() {
	std::priority_queue<Node> q;
	q.push(Node{{1, 1}, 0});
	dis[{1, 1}] = 0;
	
	auto upd = [&](std::pair<int, int> now, std::pair<int, int> t, i64 w) -> void {
		if (not dis.count(t) or dis[now] + w < dis[t]) {
			dis[t] = dis[now] + w;
			q.push({t, dis[t]});
		}
	};

	while (not q.empty()) {
		auto [now, vnow] = q.top().id; q.pop();

		if (vis[{now, vnow}]) continue;
		vis[{now, vnow}] = true;
		
		if (vnow < d[now]) upd({now, vnow}, {now, vnow + 1}, vup[vnow]);
		if (vnow > 1) upd({now, vnow}, {now, vnow - 1}, vdn[vnow]);
		
		if (d[now] == 0) continue;
		int t = es[now][vnow].first;

		ans[t] = std::min(ans[t], dis[{now, vnow}] + es[now][vnow].second);
		
		if (vnow <= d[t]) upd({now, vnow}, {t, vnow}, es[now][vnow].second);
		else upd({now, vnow}, {t, d[t]}, es[now][vnow].second + (vdnsum[vnow] - vdnsum[d[t]])); // [d[t] + 1, vnow]
	}
}

void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, k - 1) std::cin >> vup[i];
	rep (i, 2, k) std::cin >> vdn[i];

	rep (i, 1, k - 1) vupsum[i] = vupsum[i - 1] + vup[i];
	rep (i, 2, k) vdnsum[i] = vdnsum[i - 1] + vdn[i];

	rep (i, 1, n) {
		std::cin >> d[i];

		es[i].push_back({0, 0});
		rep (j, 1, d[i]) {
			int x, y; std::cin >> x >> y;
			es[i].push_back({x, y});
		}
	}

	std::memset(ans, 0x3f, sizeof ans);
	ans[1] = 0;
	dij();

	rep (i, 1, n) {
		if (ans[i] == ans[0]) std::cout << "-1 ";
		else std::cout << ans[i] << " ";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	

	int c; std::cin >> c;

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
