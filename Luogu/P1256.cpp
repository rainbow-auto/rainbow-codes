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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int maxn = 205;

int n, m;
int a[maxn][maxn];

int dis[maxn][maxn];

inline void bfs() {
	std::memset(dis, 0, sizeof dis);

	rep (i, 1, n) {
		rep (j, 1, m) {
			dis[i][j] = -1;
		}
	}

	std::queue<std::pair<int,int>> q;
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (a[i][j] == 1) {
				dis[i][j] = 0;
				q.push(std::make_pair(i, j));
			}
		}
	}

	while (not q.empty()) {
		auto now = q.front(); q.pop();

		rep (i, 0, 3) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (~dis[nx][ny]) continue;

			dis[nx][ny] = dis[now.first][now.second] + 1;
			q.push(std::make_pair(nx, ny));
		}	
	}
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			a[i][j] = c - '0';
		}
	}

	bfs();

	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cout << dis[i][j] << " ";
		}
		std::cout << "\n";
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
