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

const int maxn = 200005;

int n, m;
i64 s;

struct Range {
	int l, r;
} rs[maxn];

i64 w[maxn], v[maxn];

i64 sum[maxn];
i64 sum_v[maxn];

inline i64 query (int l, int r) { return sum[r] - sum[l - 1]; }
inline i64 query_v (int l, int r) { return sum_v[r] - sum_v[l - 1]; }

inline i64 check (i64 W) {
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + i64(w[i] >= W);
		sum_v[i] = sum_v[i - 1] + i64(w[i] >= W) * v[i];
	}

	i64 res = 0;
	for (int i = 1; i <= m; i++) {
		res += query (rs[i].l, rs[i].r) * query_v (rs[i].l, rs[i].r);
	}

	return res;
}

int main () {
	fastread

	std::cin >> n >> m >> s;

	for (int i = 1; i <= n; i++) { std::cin >> w[i] >> v[i]; }

	for (int i = 1; i <= m; i++) { std::cin >> rs[i].l >> rs[i].r; }

	i64 l = 0, r = 1e13;
	i64 ans = 0x3f3f3f3f3f3f3f3f;

	while (l <= r) {
		i64 mid = (l + r) >> 1;

		i64 now = check (mid);

		if (s >= now) {
			r = mid -1;
			ans = std::min (ans, s - now);
		} else {
			l = mid +  1;
			ans = std::min (ans, now - s);
		}
	}

	std::cout << ans << "\n";

	return 0;
}
