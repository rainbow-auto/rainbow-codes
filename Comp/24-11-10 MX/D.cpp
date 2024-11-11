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

int n, q;
int a[maxn];

int bel[maxn];
struct Query {
	int l1, r1, l2, r2;
	int id;
	friend bool operator < (Query a, Query b) {
		if (bel[a.l1] != bel[b.l1]) return bel[a.l1] < bel[b.l1];
		else return a.r1 < b.r1;
	}
} qs;

namespace Task1 {
	inline int solve(int l1, int r1, int l2, int r2) {
		std::vector<int> ax;
		std::vector<int> ay;

		rep (i, l1, r1) ax.push_back(a[i]);
		rep (i, l2, r2) ay.push_back(a[i]);

		std::sort(ax.begin(), ax.end()); std::reverse(ax.begin(), ax.end());
		std::sort(ay.begin(), ay.end()); std::reverse(ay.begin(), ay.end());

		int ypos = 0;
		for (auto x : ax) {
			while (ay[ypos] >= x) ypos++;
			int y = ay[ypos]; // y < x
			if ((x >> 1) <= y) return x + y;
		}
		return 0;
	}
}


namespace TaskA {
	inline int solve(int l1, int r1, int l2, int r2) {
		std::vector<int> vec;
		rep (i, l1, r1) vec.push_back(a[i]);

		std::sort(vec.begin(), vec.end()); std::reverse(vec.begin(), vec.end());
		rep (i, 0, (int) vec.size() - 1 - 1) {
			int x = vec[i];
			int y = vec[i + 1]; // y < x
			if ((x >> 1) <= y) return x + y;
		} 
		return 0;
	}
}

namespace Mo {
	i64 ans[maxn];

	inline void solve() {
		int B = std::sqrt(n) + 1;
		rep (i, 1, n) bel[i] = (i / B) + 1;

		std::sort(qs + 1, qs + q + 1);

		int l = 1, r = 0;
		std::multiset<int> num;
		std::multiset<int> anss;

		auto get = [&](int x, int y) {
			if (x > y) std::swap(x, y);
			if ((x >> 1) <= y) return x + y;
			return 0; 
		}

		auto add = [&](int x) -> void {
			auto it = num.upper_bound(x);
		};

		rep (i, 1, q) {
		}
	}
}

void solve() {
	// std::freopen("seer.in", "r", stdin);
	// std::freopen("seer.out", "w", stdout);

	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> a[i];

	bool flg = true;
	rep (i, 1, q) {
		int l1, r1, l2, r2; std::cin >> l1 >> r1 >> l2 >> r2;
		flg &= (l1 == l2 and r1 == r2);
		qs[i] = Query { l1, r1, l2, r2, i };
	}

	if (not flg) {
		rep (i, 1, q) {
			std::cout << TaskA::solve(qs[i].l1, qs[i].r1, qs[i].l2, qs[i].r2) << "\n";
		}
	} else {
		Mo::solve();
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
