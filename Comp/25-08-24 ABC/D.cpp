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
 
constexpr int maxn = 1005;

int n, m;
int f[maxn][maxn];

constexpr int dx[] = { 0, 0, 1, -1 };
constexpr int dy[] = { 1, -1, 0, 0 };
constexpr int inf = 0x3f3f3f3f;

struct Node {
	int x, y;
	bool col;
};

int dis[maxn][maxn][2];
inline void bfs(Node st) {
	std::queue<Node> q; q.push(st);

	std::memset(dis, 0x3f, sizeof dis);
	dis[st.x][st.y][st.col] = 0;

	while (not q.empty()) {
		auto now = q.front(); q.pop();

		rep (k, 0, 3) {
			int px = now.x + dx[k];
			int py = now.y + dy[k];
			if (px < 1 or px > n) continue;
			if (py < 1 or py > m) continue;
			bool pc = now.col ^ (f[now.x][now.y] == 4);

			if (f[px][py] == 2) continue;
			if (f[px][py] == 0 and not pc) continue;
			if (f[px][py] == 1 and pc) continue;
		
			if (dis[px][py][pc] != inf) continue;
			dis[px][py][pc] = dis[now.x][now.y][now.col] + 1;
			q.push(Node { px, py, pc });
		}
	}
}

void solve() {
	std::cin >> n >> m;

	Node st = { 0, 0, 0 };
	int gx, gy;
	rep (i, 1, n) rep (j, 1, m) {
		char c; std::cin >> c;
		if (c == 'x') f[i][j] = 0;
		if (c == 'o') f[i][j] = 1;
		if (c == '#') f[i][j] = 2;
		if (c == '.') f[i][j] = 3;
		if (c == '?') f[i][j] = 4;
		if (c == 'S') {
			f[i][j] = 5;
			st = { i, j, 0 };
		}
		if (c == 'G') {
			gx = i; gy = j;
			f[i][j] = 6;
		}
	}

	bfs(st);

	int ans = std::min(dis[gx][gy][0], dis[gx][gy][1]);
	if (ans == inf) std::cout << "-1\n";
	else std::cout << ans << "\n";
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
