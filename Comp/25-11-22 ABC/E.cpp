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

void solve() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));

	std::vector<int> X(n);
	std::vector<int> Y(m);

	rep (i, 0, n - 1) std::cin >> X[i];
	rep (j, 0, m - 1) std::cin >> Y[j];

	std::vector<int> Xpos(n * m + 1, -1);
	std::vector<int> Ypos(n * m + 1, -1);
	rep (i, 0, n - 1) {
		if (~Xpos[X[i]]) return std::cout << "No\n", void(0);
		Xpos[X[i]] = i;
	}
	rep (j, 0, m - 1) {
		if (~Ypos[Y[j]]) return std::cout << "No\n", void(0);
		Ypos[Y[j]] = j;
	}

	std::set<int> Xusd, Yusd;
	std::vector<int> rst;

	per (cur, n * m, 1) {
		int x = Xpos[cur], y = Ypos[cur];

		if (not ~x and not ~y) {
			rst.push_back(cur);
			continue;
		}

		if (not ~x) {
			if (Xusd.empty()) return std::cout << "No\n", void(0);
			x = *Xusd.begin();
		} else if (not ~y) {
			if (Yusd.empty()) return std::cout << "No\n", void(0);
			y = *Yusd.begin();
		}

		assert(a[x][y] == 0);
		a[x][y] = cur;
		
		if (~Xpos[cur]) Xusd.insert(Xpos[cur]);
		if (~Ypos[cur]) Yusd.insert(Ypos[cur]);
	}

	std::vector<std::pair<int, std::pair<int, int>>> epty;
	rep (i, 0, n - 1) rep (j, 0, m - 1) if (not a[i][j]) epty.push_back({std::min(X[i], Y[j]), {i, j}});

	std::sort(epty.begin(), epty.end());
	std::reverse(epty.begin(), epty.end());

	assert(epty.size() == rst.size());

	rep (t, 0, (int) epty.size() - 1) {
		auto [x, y] = epty[t].second;
		if (rst[t] > epty[t].first) return std::cout << "No\n", void(0);
		a[x][y] = rst[t];
	}

	std::cout << "Yes\n";
	rep (i, 0, n - 1) {
		rep (j, 0, m - 1) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
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
