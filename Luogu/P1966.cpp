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

const int maxn = 2000005;
const i64 mod = 1e8 - 3;

int n;

struct Node {
	int val, pos;

	friend bool operator < (Node x, Node y) {
		return x.val < y.val;
	}
} a[maxn], b[maxn];

int x[maxn];

struct BIT {
	i64 tr[maxn];

	inline int lowbit (int x) { return x & (-x); }

	inline void modify (int pos, i64 val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; tr[i] %= mod; } }

	inline i64 _query (int pos) { i64 res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; res %= mod; } return res; }

	inline i64 query (int l, int r) {
		if (l <= r) { return _query (r) - _query (l - 1); }
		else { return 0; }
	}
} tr;

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> a[i].val; a[i].pos = i; }
	for (int i = 1; i <= n; i++) { std::cin >> b[i].val; b[i].pos = i; }

	std::sort (a + 1, a + n + 1);
	std::sort (b + 1, b + n + 1);

	for (int i = 1; i <= n; i++) { x[a[i].pos] = b[i].pos; }

	i64 ans = 0;

	for (int i = n; i >= 1; i--) {
		tr.modify (x[i], 1);
		ans += tr.query (1, x[i] - 1);
		ans %= mod;
	}

	std::cout << ans << "\n";

	return 0;
}

/*
35 23 45 22 7 1 24 50 14 9 17 38 41 34 6 30 20 11 32 4 15 46 16 21 31 29 39 3 13 47 42 26 36 40 25 5 33 12 19 2 43 44 49 10 37 28 8 48 27 18 
*/