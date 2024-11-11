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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 200005;

int n, m;

struct Range {
	int l, r;
} rgs[maxn];

void solve() {
	std::freopen("tracy.in", "r", stdin);
	std::freopen("tracy.out", "w", stdout);

	std::cin >> n >> m;

	std::map<int, std::vector<int>> a[2];
	std::set<int> ps;
	rep (i, 1, n) {
		int l, r; std::cin >> l >> r;
		a[1][l].push_back(i);
		a[0][r].push_back(i);
		rgs[i] = Range { l, r };
		ps.insert(l); ps.insert(r);
	}

	std::bitset<maxn> finish;

	std::set<std::pair<int, int>> cur; // end time
	for (auto i : ps) {
		// dbg(i);

		// del
		for (auto x : a[0][i]) {
			if (cur.count(std::make_pair(rgs[x].r, x))) {
				cur.erase(std::make_pair(rgs[x].r, x));
				finish.set(x);
			}
		}

		// ins
		for (auto x : a[1][i]) cur.insert(std::make_pair(rgs[x].r, x));

		while (cur.size() > m) {
			cur.erase(*cur.rbegin());
		}

		// for (auto x : cur) db << "(" << x.first << " " << x.second << ") "; dbendl;
	}

	std::cout << finish.count() << "\n";
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
