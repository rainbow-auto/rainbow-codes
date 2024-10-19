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

const int maxn = 1005;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, m;
int p[maxn][maxn];

int dis[maxn][maxn];
bool vis[maxn][maxn];

inline int bfs(std::pair<int, int> st, std::pair<int, int> ed) {
	std::memset(dis, 0x3f, sizeof dis);
	std::memset(vis, 0, sizeof vis);
	dis[st.first][st.second] = 0;

	std::deque<std::pair<int, int>> q;
	q.push_front(st);

	auto push_front = [&](int x, int y, int d) {
		if (x < 1 or x > n) return;
		if (y < 1 or y > m) return;
		if (dis[x][y] < d) return;
		dis[x][y] = d;
		q.push_front(std::make_pair(x, y));
	};

	auto push_back = [&](int x, int y, int d) {
		if (x < 1 or x > n) return;
		if (y < 1 or y > m) return;
		if (dis[x][y] < d) return;
		dis[x][y] = d;
		q.push_back(std::make_pair(x, y));
	};

	while (not q.empty()) {
		auto _ = q.front(); q.pop_front();
		int x, y; std::tie(x, y) = _;

		if (_ == ed) return dis[x][y];
		if (vis[x][y]) continue;
		vis[x][y] = true;

		push_front(x + dx[p[x][y]], y + dy[p[x][y]], dis[x][y]);

		rep (i, 0, 7) {
			if (i == p[x][y]) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			push_back(nx, ny, dis[x][y] + 1);
		}
	}

	return dis[ed.first][ed.second];
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, n) {
		rep (j, 1, m) {
			char ch; std::cin >> ch;
			p[i][j] = ch - '0';
		}
	}

	int q; std::cin >> q;

	while (q--) {
		std::pair<int, int> st;
		std::cin >> st.first >> st.second;
		std::pair<int, int> ed;
		std::cin >> ed.first >> ed.second;
		
		std::cout << bfs(st, ed) << "\n";
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
