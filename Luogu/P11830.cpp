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

const int maxn = 600005;

int n;

struct Range {
	i64 l, r;
	friend Range operator + (Range x, Range y) {
		return Range { x.l + y.l, x.r + y.r };
	}
	friend Range operator - (Range x, Range y) {
		return Range { x.l - y.l, x.r - y.r };
	}
};

struct Node {
	Range a, b;
} a[maxn];

namespace SubtaskA {
	std::vector<int> add[maxn];
	std::vector<int> rmv[maxn];
	std::vector<i64> vals;

	inline i64 chk(Range cur, Range pre, Range suf) {
		i64 c = cur.r;

		if (c <= 0) return 0;

		i64 p, s;
		if (pre.r < suf.l) {
			p = pre.r;
			s = suf.l;
		} else if (suf.r < pre.l) {
			p = pre.l;
			s = suf.r;
		} else {
			p = std::max(pre.l, suf.l);
			s = std::max(pre.l, suf.l);
		}

		i64 pos = (p + s + c + 1) >> 1;
		if (p + 1 <= pos and pos <= p + c) return 1;
		return 0;
	}

	inline void solve() {
		rep (i, 1, n) vals.push_back(a[i].b.l), vals.push_back(a[i].b.r);

		std::sort(vals.begin(), vals.end());
		vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

		rep (i, 1, n) {
			int pos = std::lower_bound(vals.begin(), vals.end(), a[i].b.l) - vals.begin();
			add[pos].push_back(i);
		}
		
		rep (i, 1, n) {
			int pos = std::lower_bound(vals.begin(), vals.end(), a[i].b.r) - vals.begin();
			rmv[pos].push_back(i);
		}

		Range cur = Range {0, 0}; // l <= now <= r
		Range pre = Range {0, 0}; // r < now
		Range suf = Range {0, 0}; // l > now

		rep (i, 1, n) suf = suf + a[i].a;

		i64 ans = 0;

		i64 last = 0;
		rep (_, 0, (int) vals.size() - 1) {
			i64 i = vals[_];
			// dbg(i);

			if ((i - 1) - (last + 1) + 1 > 0) ans += 1ll * ((i - 1) - (last + 1) + 1) * chk(cur, pre, suf);

			// add
			for (auto x : add[_]) {
				// db << "add " << x << "\n";
				cur = cur + a[x].a;
				suf = suf - a[x].a;
			}

			// db << "pre: " << pre.l << " " << pre.r << "\n";
			// db << "cur: " << cur.l << " " << cur.r << "\n";
			// db << "suf: " << suf.l << " " << suf.r << "\n";

			ans += chk(cur, pre, suf);

			// del
			for (auto x : rmv[_]) {
				// db << "rmv " << x << "\n";
				cur = cur - a[x].a;
				pre = pre + a[x].a;
			}

			last = i;
		}

		std::cout << ans << "\n";

		// db << "=============\n";

		rep (i, 0, (int) vals.size() - 1) if (add[i].size()) add[i].clear();
		rep (i, 0, (int) vals.size() - 1) if (rmv[i].size()) rmv[i].clear();

		// std::memset(add, 0, sizeof add);
		// std::memset(rmv, 0, sizeof rmv);
		// add.clear();
		// rmv.clear();
		vals.clear();
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i].a.l >> a[i].a.r;
		std::cin >> a[i].b.l >> a[i].b.r;
	}

	SubtaskA::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

	int c; std::cin >> c;

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