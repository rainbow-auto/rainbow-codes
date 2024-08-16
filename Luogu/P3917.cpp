#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

const int maxn = 100005;

int n;
int a[maxn], pre[maxn];

i64 cnt[40][2];

int main () {
	fastread

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }
	rep (i, 1, n) { pre[i] = (pre[i - 1] xor a[i]); }

	i64 ans = 0;

	rep (r, 0, n) {
		rep (b, 0, 31) {
			bool curr = (pre[r] & (1 << b));
			ans += cnt[b][curr ^ 1] * (1 << b);
		}

		rep (b, 0, 31) {
			bool curr = (pre[r] & (1 << b));
			cnt[b][curr] ++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}
