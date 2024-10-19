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

const int maxn = 505;
const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { 1, 0, 0, -1 };

int n, m;
char a[maxn][maxn];

int dis[maxn][maxn];
inline void bfs(std::pair<int, int> st) {
	std::deque<std::pair<int, int>> q;
	q.push_back(st);

	std::memset(dis, -1, sizeof dis);
	dis[st.first][st.second] = 0;

	while (not q.empty()) {
		auto _ = q.front(); q.pop_front();
		int x, y; std::tie(x, y) = _;

		rep (i, 0, 3) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 or nx > n) continue;
			if (ny < 0 or ny > m) continue;
			if (~dis[nx][ny]) continue;

			int w = a[x][y] != a[nx][ny];
			dis[nx][ny] = dis[x][y] + w;

			if (w) q.push_back(std::make_pair(nx, ny));
			else q.push_front(std::make_pair(nx, ny));
		}
	}
}

bool solve() {
	std::cin >> n >> m;

	if (not (n | m)) return false;

	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
		}
	}

	std::pair<int, int> st;
	std::cin >> st.first >> st.second;
	st.first ++; st.second ++;

	bfs(st);

	std::pair<int, int> ed;
	std::cin >> ed.first >> ed.second;
	ed.first ++; ed.second ++;

	std::cout << dis[ed.first][ed.second] << "\n";

	return true;
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

	while (solve());

	return 0;
}
