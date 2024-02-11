#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

i64 ksm (i64 a, i64 b, i64 mod) {
	i64 base = a;
	i64 res = 1;

	while (b) {
		if (b & 1) { res = res * base % mod; }
		base = (base  % mod * base % mod) % mod; b >>= 1;
	}

	return res;
}

struct Node {
	i64 l, r;
	mutable i64 val;

	friend bool operator < (Node a, Node b) {
		return a.l < b.l;
	}
};

std::set <Node> s;

inline auto split (int pos) {
	auto it = s.lower_bound (Node { pos, 0, 0 });
	if (it != s.end () and it -> l == pos) { return it; }
	it --;
	if (it -> r < pos) { return s.end (); }
	Node x = *it;
	s.erase (it);
	s.insert (Node { x.l, pos - 1, x.val });
	return s.insert (Node { pos, x.r, x.val }).first;
}

inline void assign (int l, int r, i64 val) {
	auto itr = split (r + 1); auto itl = split (l);
	s.erase (itl, itr);
	s.insert (Node { l, r, val });
}

inline void add (int l, int r, i64 val) {
	auto itr = split (r + 1); auto itl = split (l);
	for (auto now = itl; now != itr; now ++) { now -> val += val; }
}

struct Rank {
	i64 val;
	int len;

	friend bool operator < (Rank a, Rank b) {
		return a.val < b.val;
	}
};

inline i64 kth (int l, int r, int rnk) {
	auto itr = split (r + 1); auto itl = split (l);
	std::vector<Rank> arr;
	for (auto now = itl; now != itr; now ++) { arr.push_back (Rank { now -> val, now -> r - now -> l + 1 }); }
	std::sort (arr.begin (), arr.end ());
	for (auto now : arr) {
		if (rnk - now.len > 0) { rnk -= now.len; continue; }
		return now.val;
	}
}

inline i64 sum (int l, int r, i64 x, i64 mod) {
	auto itr = split (r + 1); auto itl = split (l);
	i64 res = 0;
	for (auto now = itl; now != itr; now ++) { res += 1ll * (now -> r - now -> l + 1) % mod * ksm (now -> val, x, mod) % mod; res %= mod; }
	return res;
}

const int maxn = 100005;

int n, m;

namespace Genrator {
	i64 seed, vmax;

	inline i64 rnd () {
		i64 res = seed;
		seed = (seed * 7ll + 13ll) % 1000000007ll;
		return res;
	}

	inline i64 getVal () {
		return rnd () % vmax + 1;
	}

	struct Query {
		i64 op;
		i64 l, r, x, y;
	};

	inline Query getQuery () {
		i64 op = rnd () % 4ll + 1;
		i64 l = rnd () % n + 1;
		i64 r = rnd () % n + 1;
	
		if (l > r) { std::swap (l, r); }

		i64 x, y = 0;
		if (op == 3) { x = rnd () % (r - l + 1) + 1; }	
		else { x = rnd () % vmax + 1; }
		
		if (op == 4) { y = rnd () % vmax + 1; }

		return Query { op, l, r, x, y };
	}
}

int main () {
	fastread
	
	std::cin >> n >> m >> Genrator::seed >> Genrator::vmax;

	for (int i = 1; i <= n; i++) { i64 now = Genrator::getVal (); s.insert (Node { i, i, now }); }

	for (int i = 1; i <= m; i++) {
		Genrator::Query now = Genrator::getQuery ();

		if (now.op == 1) { add (now.l, now.r, now.x); }
		if (now.op == 2) { assign (now.l, now.r, now.x); }
		if (now.op == 3) { std::cout << kth (now.l, now.r, now.x) << "\n"; }
		if (now.op == 4) { std::cout << sum (now.l, now.r, now.x, now.y) << "\n"; }
	}

	return 0;
}
