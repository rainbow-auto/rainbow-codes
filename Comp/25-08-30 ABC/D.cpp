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

constexpr int maxn = 200005;

i64 n;
int m, l;

constexpr i64 dx[] = { 0, 1, -1, 0 };
constexpr i64 dy[] = { -1, 0, 0, 1 };

/*
L 0
D 1
U 2
R 3
*/

struct Node {
	int id;
	i64 d;
};

std::map<i64, std::vector<Node>> tsks;

inline void input(int m, int id) {
	i64 curt = 0;
	rep (i, 1, m) {
		char d; std::cin >> d;
		i64 c; std::cin >> c;
	
		int dd = 0;
		if (d == 'L') dd = 0;
		if (d == 'D') dd = 1;
		if (d == 'U') dd = 2;
		if (d == 'R') dd = 3;
	
		tsks[curt + 1].push_back(Node { id, dd });
		curt += c;
	}
}

void solve() {
	std::pair<i64, i64> pos[2];
	rep (k, 0, 1) std::cin >> pos[k].first >> pos[k].second;
	std::cin >> n >> m >> l;

	input(m, 0);
	input(l, 1);

	i64 ans = 0;

	tsks[n + 1].push_back(Node { 0, 0 });

	std::pair<i64, i64> dir[2];
	
	for (auto it = tsks.begin(); it != std::prev(tsks.end()); it++) {
		auto [t, tsk] = *it;
		i64 nxt = std::next(it) -> first;
		// (t, nxt]

		// db << "[" << t << ", " << nxt - 1 << "]\n";

		i64 x = (nxt - 1) - t + 1;
		// [1, x]
		for (auto x : tsk) {
			dir[x.id] = { dx[x.d], dy[x.d] };
		}

		// db << dir[0].first << " " << dir[0].second << "\n";
		// db << dir[1].first << " " << dir[1].second << "\n";

		// db << "pos:\n";
		// db << pos[0].first << " " << pos[0].second << "\n";
		// db << pos[1].first << " " << pos[1].second << "\n";

		auto chk = [&](i64 v) -> bool {
			return (1 <= v) and (v <= x);
		};

		i64 txl, txr;
		if (dir[0].first - dir[1].first != 0) {
			i64 u = (pos[1].first - pos[0].first);
			i64 v = (dir[0].first - dir[1].first);

			if (u % v == 0 and chk(u / v)) {
				txl = txr = u / v;
			} else {
				txl = 0, txr = -1;
			}
		}
		else if (pos[0].first == pos[1].first) txl = 1, txr = x;
		else txl = 0, txr = -1;
		
		i64 tyl, tyr;
		if (dir[0].second - dir[1].second != 0) {
			i64 u = (pos[1].second - pos[0].second);
			i64 v = (dir[0].second - dir[1].second);
			if (u % v == 0 and chk(u / v)) {
				tyl = tyr = u / v;
			} else {
				tyl = 0, tyr = -1;
			}
		}
		else if (pos[0].second == pos[1].second) tyl = 1, tyr = x;
		else tyl = 0, tyr = -1;

		i64 l = std::max(txl, tyl);
		i64 r = std::min(txr, tyr);

		if (l <= r) {
			ans += (r - l + 1);
			// db << "ans += " << (r - l + 1) << "\n";

			// db << txl << " " << txr << "\n";
			// db << tyl << " " << tyr << "\n";
		}

		pos[0] = { x * dir[0].first + pos[0].first , x * dir[0].second + pos[0].second };
		pos[1] = { x * dir[1].first + pos[1].first , x * dir[1].second + pos[1].second };
	}

	std::cout << ans << "\n";
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
