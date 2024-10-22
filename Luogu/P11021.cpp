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

const int maxn = 200005;

int n, q;
struct Node {
	i64 x, y;
	int id;
	
	friend bool operator < (const Node u, const Node v) {
		return u.x < v.x;
	}
} a[maxn];

std::set<Node> s;

inline i64 mabs(i64 x) {
	return x >= 0 ? x : -x;
}

void solve() {
	std::cin >> n >> q;
	
	rep (i, 1, n) {
		i64 x, y; std::cin >> y >> x;
		a[i] = Node { x, y, i };
		s.insert(a[i]);
	}

	auto calc = [&](Node u, Node v) -> i64 {
		return i64 (mabs(u.y - v.y) / mabs(u.x - v.x));
	};

	std::multiset<i64> ans;
	auto rmv = [&](int x) -> void {
		ans.erase(ans.find(x));
	};

	auto ins = [&](int x) -> void {
		ans.insert(x);
	};

	bool fst = true;
	Node lst;
	for (auto x : s) {
		if (fst) fst = false;
		else ans.insert(calc(x, lst));
		lst = x;
	}

	i64 inf; std::memset(&inf, 0x3f, sizeof inf);

	while (q--) {
		i64 u, v; std::cin >> u >> v;

		auto it = s.find(a[u]);
		if (it != s.begin()) rmv(calc(*it, *std::prev(it)));
		if (it != std::prev(s.end())) rmv(calc(*it, *std::next(it)));
		s.erase(a[u]);

		Node cur = a[u]; cur.x = v;

		it = s.upper_bound(cur);

		i64 A = (it == s.begin()) ? -inf - 114514 : calc(*std::prev(it), cur);
		i64 B = (it == s.end()) ? -inf - 191810 : calc(cur, *it);

		ins(A); ins(B);
		std::cout << (*ans.rbegin()) << "\n";
		rmv(A); rmv(B);

		// recovery
		s.insert(a[u]);
		it = s.find(a[u]);
		if (it != s.begin()) ins(calc(*it, *std::prev(it)));
		if (it != std::prev(s.end())) ins(calc(*it, *std::next(it)));
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