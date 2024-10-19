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

const int maxn = 1005;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int n, m;
char a[maxn][maxn];

int dis[maxn][maxn];
bool vis[maxn][maxn];

inline void bfs(std::pair<int, int> st) {
	std::memset(dis, 0x3f, sizeof dis); dis[st.first][st.second] = 0;
	std::memset(vis, 0, sizeof vis);
	std::deque<std::pair<int, int>> q; q.push_front(st);

	while (not q.empty()) {
		auto _ = q.front(); q.pop_front();
		int x, y; std::tie(x, y) = _;
		if (vis[x][y]) continue;
		vis[x][y] = true;

		rep (i, 0, 3) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 or nx > n) continue;
			if (ny < 1 or ny > m) continue;

			int w = a[x][y] != a[nx][ny];
			if (dis[nx][ny] < dis[x][y] + w) continue;

			dis[nx][ny] = dis[x][y] + w;
			if (not w) q.push_front(std::make_pair(nx, ny));
			else q.push_back(std::make_pair(nx, ny));
		}			
	}
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
		}
	}	

	bfs(std::make_pair(1, 1));

	std::cout << dis[n][m] << "\n";
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
