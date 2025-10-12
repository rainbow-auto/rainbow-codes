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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;
constexpr int maxk = 25;

int n, m, k;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge {u, v, last[u]};
	last[u] = cnt;
}

bool col[maxn];
bool flg[maxn];
bool f[maxk][maxn];

void solve() {
	std::cin >> n >> m >> k;
	
	rep (i, 1, n) {
		char c; std::cin >> c;
		col[i] = c - 'A';
	}

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
	}

	rep (i, 1, n) f[2 * k + 1][i] = (col[i] == 0);

	per (cur, k, 1) {
		{   // Bob
			rep (now, 1, n) {
				for (int i = last[now]; i; i = es[i].pre) {
					int t = es[i].v;
					if (not f[2 * cur + 1][t]) {
						f[2 * cur][now] = 1;
					}
				}
			}
			// db << "Bob Win: "; rep (i, 1, n) if (f[2 * cur][i]) db << i << " "; dbendl;
		}
		{ // Alice
			rep (now, 1, n) {
				for (int i = last[now]; i; i = es[i].pre) {
					int t = es[i].v;
					if (not f[2 * cur][t]) {
						f[2 * cur - 1][now] = 1;
					}
				}
			}
			// db << "Alice Win: "; rep (i, 1, n) if (f[2 * cur - 1][i]) db << i << " "; dbendl;
		}
		// dbendl;
	}

	if (f[1][1]) std::cout << "Alice\n";
	else std::cout << "Bob\n";

	rep (i, 1, n) last[i] = 0;
	cnt = 0;
	rep (i, 1, 2 * k + 1) rep (j, 1, n) f[i][j] = 0;
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
