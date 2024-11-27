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

const int maxn = 1000005;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::pair<int, int> a[3];

std::vector<int> tr[maxn];

std::bitset<maxn> vis;
int siz[maxn];
int fath[maxn];
void getrt(int now, int &rt) {
	int mxsiz = 0;
	siz[now] = 1;
	vis.set(now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (vis[t]) continue;
		tr[now].push_back(t); tr[t].push_back(now);
		fath[t] = now;
		getrt(t, rt);
		siz[now] += siz[t];
		mxsiz = std::max(mxsiz, siz[t]);
	}

	mxsiz = std::max(mxsiz, n - siz[now]);

	if (mxsiz <= (n >> 1)) rt = now;
}

int col[maxn];
void dfst(int now, int fa, int &x, int c) {
	if (not x) return;
	if (not now) return;
	col[now] = c; x--;
	for (auto t : tr[now]) {
		if (t == fa) continue;
		if (~col[t]) continue;
		dfst(t, now, x, c);
	}
}

void dfsg(int now, int fa, int &x, int c) {
	if (not x) return;
	if (not now) return;
	for (auto t : tr[now]) {
		if (t == fa) continue;
		dfsg(t, now, x, c);
	}
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (~col[t]) continue;
		dfst(t, now, x, c); // 至多经过一条非树边
	}
}
 
void solve() {
	std::cin >> n >> m;
	rep (i, 0, 2) {
		std::cin >> a[i].first;
		a[i].second = i + 1;
	}
	std::sort(a, a + 3);

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		u++, v++;
		addEdge(u, v); addEdge(v, u);
	}

	int rt = -1;
	getrt(1, rt);

	getsiz(rt, -1);

	auto Yes = [&]() -> void {
		rep (i, 1, n) {
			if (~col[i]) std::cout << a[col[i]].second << " "; 
			else std::cout << a[2].second << " ";
		}
	};

	auto No = [&]() -> void {
		rep (i, 1, n) std::cout << "0 ";
	};

	int sub = fath[rt];
	siz[sub] = n - siz[rt];
	std::memset(col, -1, sizeof col);
	col[rt] = 0;
	for (auto t : tr[rt]) {
		if (siz[t] >= a[0].first) {
			dfst(t, rt, a[0].first, 0);
			dfst(rt, -1, a[1].first, 1);
			return Yes(), void(0);
		}
	}
	
	dfst(sub, -1, a[0].first, 0);
	dfsg(sub, rt, a[0].first, 0);
	if (a[0].first) return No(), void(0);
	dfst(rt, -1, a[1].first, 1);	
	Yes();
}

bool MemED;
int main() {
	fastread
	// lookMem	

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