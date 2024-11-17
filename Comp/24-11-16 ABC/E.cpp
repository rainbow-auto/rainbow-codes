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

const int maxn = 500005;

int n, q;

struct Range {
	int l, r;
	int c;
	friend bool operator < (Range a, Range b) {
		return a.l < b.l; // 所有 range 并起来应当是 [1, n] 且 颜色段一定不交
	}
};

std::set<Range> s;

int cnt[maxn];

inline void mdf(int pos, int c) {
	auto it = std::prev(s.upper_bound(Range { pos, 0, 0 }));
	auto cur = *it;

	if (cur.c == c) return;
	
	cnt[cur.c] -= cur.r - cur.l + 1;
	cnt[c] += cur.r - cur.l + 1;

	bool flg = false;
	if (it != s.begin()) {
		auto pre = *std::prev(it);
		if (c == pre.c) {
			s.erase(cur); s.erase(pre);
			cur = Range { pre.l, cur.r, c };
			s.insert(cur);
			flg = true;
		} 
	}

	it = std::prev(s.upper_bound(Range { pos, 0, 0 }));
	if (it != std::prev(s.end())) {
		auto nxt = *std::next(it);
		if (c == nxt.c) {
			s.erase(cur); s.erase(nxt);
			cur = Range { cur.l, nxt.r, c };
			s.insert(cur);
			flg = true;
		}
	}

	if (not flg) {
		s.erase(cur); s.insert(Range { cur.l, cur.r, c });
	}
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) s.insert(Range { i, i, i });
	rep (i, 1, n) cnt[i] = 1;

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int x, c; std::cin >> x >> c;
			mdf(x, c);
		} else {
			int x; std::cin >> x;
			std::cout << cnt[x] << "\n";
		}
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
