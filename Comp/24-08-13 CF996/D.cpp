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

const int maxn = 200005;

int n;
i64 a[maxn];
char s[maxn];
i64 sum[maxn];

int main () {
	fastread
	
	int T; std::cin >> T;

	while (T--) {
		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }
		rep (i, 1, n) { std::cin >> s[i]; }
		rep (i, 1, n) { sum[i] = sum[i - 1] + a[i]; }


		int l = 1;
		int r = n;

		i64 ans = 0;
		while (l <= r) {
			while (l <= r and s[l] != 'L') { l++; }
			while (l <= r and s[r] != 'R') { r--; }

			if (l > r) { break; }

			ans += sum[r] - sum[l - 1];
			l ++; r --;
		}

		std::cout << ans << "\n";
	}

	return 0;
}
