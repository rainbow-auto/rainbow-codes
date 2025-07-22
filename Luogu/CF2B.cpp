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

using Num = std::array<int, 2>;

int n;
Num a[maxn][maxn];
std::pair<int, char> f[2][maxn][maxn];

inline Num get(int x) {
	Num res; res.fill(0);
	while (x % 2 == 0) res[0]++, x /= 2;
	while (x % 5 == 0) res[1]++, x /= 5;
	return res;
}

inline void solve(int id) {
	std::memset(f[id], 0x3f, sizeof f[id]);
	f[id][1][1] = { a[1][1][id], 0 };

	rep (i, 1, n) {
		rep (j, 1, n) {
			if (i == 1 and j == 1) continue;
			f[id][i][j] = std::min(f[id][i][j], std::make_pair(f[id][i - 1][j].first + a[i][j][id], 'D'));
			f[id][i][j] = std::min(f[id][i][j], std::make_pair(f[id][i][j - 1].first + a[i][j][id], 'R'));
		}
	}
}

inline void out(int id) {
	std::cout << f[id][n][n].first << "\n";
	int i = n, j = n;
	std::vector<char> ans;
	while (f[id][i][j].second) {
		ans.push_back(f[id][i][j].second);
		if (f[id][i][j].second == 'D') i--;
		else j--;
	}
	std::reverse(ans.begin(), ans.end());
	for (auto x : ans) std::cout << x; 
}

inline void out0(int x, int y) {
	std::cout << 1 << "\n";
	rep (i, 1, x - 1) std::cout << "D";
	rep (j, 1, n - 1) std::cout << "R";
	rep (i, 1, n - x) std::cout << "D";
}

void solve() {

	bool flg = false;
	int x0 = 0, y0 = 0;

	std::cin >> n;
	rep (i, 1, n) {
		rep (j, 1, n) {
			int x; std::cin >> x;
			if (not x) {
				flg = true;
				x0 = i;
				y0 = j;
			} else a[i][j] = get(x);
		}
	}

	solve(0);
	solve(1);

	if (f[0][n][n].first > 1 and f[1][n][n].first > 1 and flg) return out0(x0, y0);

	if (f[0][n][n].first < f[1][n][n].first) {
		out(0);
	} else {
		out(1);
	}
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
