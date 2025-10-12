#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

constexpr int maxn = 15;

int n, m;
int sx, sy;

bool a[maxn][maxn];

struct Node {
	int U, D, L, R;
	int x, y;
	// friend bool operator < (Node a, Node b) {
	// 	if (a.U != b.U) return a.U < b.U;
	// 	if (a.L != b.L) return a.L < b.L;
	// 	if (a.R != b.R) return a.R < b.R;
	// 	if (a.D != b.D) return a.D < b.D;
	// 	if (a.x != b.x) return a.x < b.x;
	// 	if (a.y != b.y) return a.y < b.y;
	// 	return false;
	// }
};

constexpr u64 base = 233;
inline u64 get(Node a) {
	u64 res = 0;
	res = res * base + a.U;
	res = res * base + a.D;
	res = res * base + a.L;
	res = res * base + a.R;
	res = res * base * base + (a.x + 2 * n);
	res = res * base * base + (a.y + 2 * m);
	return res;
}

constexpr int dx[] = { 1, 0, -1, 0 };
constexpr int dy[] = { 0, 1, 0, -1 };

inline bool chk(int tx, int ty, Node cur) {
	if (cur.U <= tx and tx <= cur.D and cur.L <= ty and ty <= cur.R and a[tx][ty]) return false;
	return true;
	// if (tx < cur.U or tx > cur.D or ty < cur.L or ty > cur.R) return true;
	// if (not a[tx][ty]) return true;
	// return false;
}

std::map<u64, int> dis;
std::map<u64, bool> vis;

inline bool clr(Node cur) {
	if (cur.U > cur.D) return true;
	if (cur.L > cur.R) return true;
	rep (i, cur.U, cur.D) rep (j, cur.L, cur.R) if (a[i][j]) return false;
	return true;
}

inline int bfs() {
	std::queue<std::pair<Node, u64>> q;

	auto st = Node{1, n, 1, m, sx, sy}; 
	u64 hst = get(st);
	q.push({st, hst});
	dis[hst] = 0;
	vis[hst] = true;
	
	while (not q.empty()) {
		auto [cur, hcur] = q.front(); q.pop();

		// db << "cur: \n";
		// db << cur.U << " " << cur.D << " " << cur.L << " " << cur.R << " " << cur.x << " " << cur.y << "\n";
		// dbg(dis[cur]);
		
		if (clr(cur)) {
			return dis[hcur];
		}
		
		rep (k, 0, 3) {
			int tx = cur.x + dx[k];
			int ty = cur.y + dy[k];

			if (chk(tx, ty, cur)) {
				int U = std::max(cur.U, 1 + tx - sx);
				int D = std::min(cur.D, n + tx - sx);
				int L = std::max(cur.L, 1 + ty - sy);
				int R = std::min(cur.R, m + ty - sy);

				auto t = Node { U, D, L, R, tx, ty };
				u64 ht = get(t);
				if (not vis.count(ht)) {
					q.push({t, ht});
					dis[ht] = dis[hcur] + 1;
					vis[ht] = true;
					// db << "to: \n";
					// dbg(dx[k]);
					// dbg(dy[k]);
					// db << t.U << " " << t.D << " " << t.L << " " << t.R << " " << t.x << " " << t.y << "\n";
					// dbg(dis[t]);
				}
			}
		}		
	}

	return -1;
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			if (c == 'T') {
				sx = i; 
				sy = j;
			} else if (c == '#') {
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}	

	std::cout << bfs() << "\n";
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
