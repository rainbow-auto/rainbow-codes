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

const int maxn = 2000005;
const i64 mod = 2;
const int mx = 2000000;

int n, m;
int a[maxn];


struct BIT {
	i64 tr[maxn];
	
	inline int lowbit (int x) { return x & (-x); }

	inline void modify (int pos, i64 val) { for (int i = pos; i <= mx; i += lowbit (i)) { tr[i] += val; } }

	i64 query (int pos) { i64 res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }

	i64 query (int l, int r) { return query (r) - query (l - 1); }
} tr;


int main () {
	fastread

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	i64 ans = 0;
	for (int i = 1; i <= n; i++) { ans += tr.query (a[i] + 1, mx); ans %= 2ll; tr.modify (a[i], 1); }

	while (m--) {
		int op; std::cin >> op;

		if (op == 1) {
			i64 l1, r1, l2, r2; std::cin >> l1 >> r1 >> l2 >> r2;

			i64 len = l2 - r1 - 1; // 中间一段的长度
			i64 delta = (r1 - l1 + 1) * len + ((r1 - l1 + 1) + len) * (r2 - l2 + 1);
			delta %= mod;

			ans += delta;
			ans %= mod;

		} else if (op == 2) {
			i64 l, r, k; std::cin >> l >> r >> k;
		
			i64 delta = (r - l + 1) * (k - r);
			delta %= mod;

			ans += delta;
			ans %= mod;
		} else if (op == 3) {
			int val; std::cin >> val;
			ans += tr.query (val + 1, mx); tr.modify (val, 1);
			ans %= mod;
		} else {
			int val; std::cin >> val;
			ans += tr.query (1, val - 1); tr.modify (val, 1);
			ans %= mod;
		}

		std::cout << ((ans % mod) ? "odd" : "even") << "\n";
	}

	return 0;
}
