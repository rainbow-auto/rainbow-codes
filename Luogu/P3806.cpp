#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

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

constexpr int maxn = 1e4 + 5;

int n;
struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

struct Query {
	int k;
	int id;
};

std::vector<Query> qs;
bool ans[maxn];

constexpr int maxd = 1e8 + 5;
std::bitset<maxd> ex;

std::bitset<maxn> rmv;

int tot;
int siz[maxn], mx[maxn];
int rt;

void get_rt(int now, int fa) {
	siz[now] = 1;
	mx[now] = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		get_rt(t, now);
		siz[now] += siz[t];
		mx[now] = std::max(mx[now], siz[t]);
	}
	mx[now] = std::max(mx[now], tot - siz[now]);
	if (mx[now] < mx[rt]) rt = now;
}

int dis[maxn];
std::vector<int> dis_s;
void get_dis(int now, int fa) {
	dis_s.push_back(dis[now]);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;

		dis[t] = dis[now] + es[i].w;
		get_dis(t, now);
	}
}

std::vector<int> del;

void calc(int now) {
	ex[0] = true;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;
		dis[t] = es[i].w;
		get_dis(t, now);

		for (auto d : dis_s) {
			for (auto q : qs) {
				if (q.k - d >= 0) ans[q.id] |= ex[q.k - d];
			}
		}

		for (auto d : dis_s) {
			del.push_back(d);
			ex[d] = true;
		}
		dis_s.clear();
	}

	for (auto d : del) ex[d] = false;
	del.clear();
}

void divide(int now) {
	rmv[now] = true;
	calc(now);
	
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;
		
		tot = siz[t];
		mx[rt] = 0x3f3f3f3f;
		get_rt(t, now);
		get_rt(rt, now);

		divide(rt);
	}
}

void solve() {
	std::cin >> n;
	int q; std::cin >> q;

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	rep (t, 1, q) {
		int k; std::cin >> k;
		qs.push_back(Query{k, t});
	}

	tot = n;
	mx[rt] = 0x3f3f3f3f;
	get_rt(1, 0);
	get_rt(rt, 0);

	divide(rt);

	rep (t, 1, q) std::cout << (ans[t] ? "AYE" : "NAY") << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	file("P3806_7")

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
