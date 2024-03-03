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

const int maxn = 100005;
const int maxVal = 100001;

int n;
int a[maxn];

int tr[maxn];
inline int lowbit (int x) { return x & (-x); }
inline void modify (int pos, int val) { for (int i = pos; i <= maxVal; i += lowbit (i)) { tr[i] += val; } }
inline int _query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
inline int query (int l, int r) { if (l > r) { return 0; } return _query (r) - _query (l - 1); }

inline void clear () { memset (tr, 0, sizeof (tr)); }

int left_cnt[maxn];
int right_cnt[maxn];

int main () {
	fastread
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	for (int i = 1; i <= n; i++) {
		modify (a[i], 1);
		left_cnt[i] = query (1, a[i] - 1);
	}

	clear ();

	for (int i = n; i >= 1; i--) {
		modify (a[i], 1);

		right_cnt[i] = query (a[i] + 1, maxVal);
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1ll * left_cnt[i] * right_cnt[i];
	}

	std::cout << ans << "\n";

	return 0;
}
