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

constexpr int maxn = 300005;

constexpr int dx[] = { 0, 1, -1, 0 };
constexpr int dy[] = { 1, 0, 0, -1 };

int n, m;

std::vector<char> a[maxn];
std::vector<bool> vis[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		a[i].resize(m + 1);
		vis[i].resize(m + 1);
		rep (j, 1, m) {
			std::cin >> a[i][j];
		}
	}	

	std::vector<std::pair<int, int>> T = {};
	
	rep (i, 1, n) rep (j, 1, m) if (a[i][j] == '#') {
		vis[i][j] = true;
		T.push_back({i, j});
	}

	auto chk = [&](int x, int y) -> bool {
		int cnt = 0;
		rep (k, 0, 3) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 or nx > n) continue;
			if (ny < 1 or ny > m) continue;
			cnt += a[nx][ny] == '#';
		}	
		return cnt == 1;
	};

	while (true) {
		std::vector<std::pair<int, int>> nT = {};
		for (auto [x, y] : T) {
			rep (k, 0, 3) {                
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 1 or nx > n) continue;
				if (ny < 1 or ny > m) continue;
				if (vis[nx][ny]) continue;

				if (chk(nx, ny)) {
					nT.push_back({nx, ny});
				}
			}
		}

		if (nT.empty()) break;

		for (auto [x, y] : nT) {
			vis[x][y] = true;
			a[x][y] = '#';
		}

		std::swap(T, nT);
	}

	int ans = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			ans += a[i][j] == '#';
		}
	}

	std::cout << ans << '\n';
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
