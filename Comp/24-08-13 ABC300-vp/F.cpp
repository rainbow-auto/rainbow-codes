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
#define dbline() void (0);~
#endif

const int maxn = 600005;

i64 n, m, k;
std::string s;

i64 sum[maxn];

int main () {
	fastread

	std::cin >> n >> m >> k;
	std::cin >> s;
	s = " " + s + s;
	
	rep (i, 1, (n << 1)) { sum[i] = sum[i - 1] + (s[i] == 'x'); }	

	i64 tot = 0; rep (i, 1, n) { tot += s[i] == 'x'; }
	
	i64 cnt = k / tot;
	m -= cnt;
	k %= tot;
	
	i64 ans = 0;
	for (i64 l = 1, r = 1; l <= n and r <= (n << 1); l ++) {
		while (r + 1 <= (n << 1) and sum[r + 1] - sum[l - 1] <= k) { r++; }
		
		if (m == 1) { ans = std::max (ans, std::min (r, n) - l + 1); }
		if (m > 1) { ans = std::max (ans, r - l + 1); }
	}

	ans += cnt * n;

	std::cout << ans << "\n";

	return 0;
}
