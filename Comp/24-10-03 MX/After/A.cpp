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

const int maxn = 5005;

int n, x, y;

bool f[maxn][maxn];

std::set<int> rst[maxn];

void solve() {
	std::cin >> n >> x >> y;
	
	f[0][0] = true;
	rst[0].insert(0);

	rep (id, 1, n) {
		i64 a, b, c, d; std::cin >> a >> b >> c >> d;
		
		a -= x; b -= x; c -= y; d -= y;

		a = std::max(a, 0ll); b = std::min(b, id - 1); 
		c = std::max(c, 0ll); d = std::min(d, id - 1);

		if (a > b) continue;
		if (c > d) continue;

		per (dx, b, a) {
			std::vector<int> ins01;
			std::vector<int> ins10;

			auto it = rst[dx].lower_bound(c);

			while (it != rst[dx].end()) {
				int dy = *it;
				if (dy > d) break;

				if (not f[dx][dy + 1]) {
					f[dx][dy + 1] = true;
					ins01.push_back(dy);
				}
				if (not f[dx + 1][dy]) {
					f[dx + 1][dy] = true;
					ins10.push_back(dy);
				}

				rst[dx].erase(it++);
			}

			for (auto dy : ins01) rst[dx].insert(dy + 1);
			for (auto dy : ins10) rst[dx + 1].insert(dy);
		}
	}

	int res = 0;
	rep (i, 0, n) {
		rep (j, 0, n) {
			(f[i][j]) && (res = std::max(res, int (i + j)));
		}
	}
	std::cout << res << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
