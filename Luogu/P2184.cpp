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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 100005;

int n, m;

struct FenwickTree {
	int tr[maxn];

	inline int lowbit (int x) { return x & (-x); }

	inline void modify (int pos, int val) {
		for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; }
	}

	inline int query (int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; }
		return res;
	}

	inline int query (int l, int r) {
		return query (r) - query (l - 1);
	}
} tr1, tr2;

int main () {
	fastread

	std::cin >> n >> m;

	int cnt = 0;
	while (m--) {
		int op; std::cin >> op;

		if (op == 1) {
			int l, r; std::cin >> l >> r;
			tr1.modify (l, 1);
			tr2.modify (r, 1);
			cnt ++;
		} else {
			int l, r; std::cin >> l >> r;
			int ans = cnt - tr1.query (r + 1, n) - tr2.query (l - 1);
			std::cout << ans << "\n";
		}
	}

	return 0;
}
