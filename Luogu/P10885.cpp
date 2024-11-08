#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

int n;
i64 a[maxn];

i64 s1[maxn], s2[maxn], s3[maxn];
inline void init () {
	rep (i, 1, n) { 
		s1[i] = s1[i - 1] + i; s1[i] %= mod;
		s2[i] = s2[i - 1] + (i * i) % mod; s2[i] %= mod;
		s3[i] = s3[i - 1] + ((i * i) % mod * i) % mod; s3[i] %= mod;
	}
}

// len * st ^ 3 + st ^ 2 * d * s1[len - 1] + st * d ^ 2 * s2[len - 1] + d ^ 3 * s3[len - 1]
inline i64 calc (i64 st, i64 len, i64 d) {
	i64 res = len * st % mod * st % mod * st % mod;
	res += 3 * st * st % mod * d % mod * s1[len - 1] % mod; res %= mod;
	res += 3 * st * d % mod * d % mod * s2[len - 1] % mod; res %= mod;
	res += d * d % mod * d % mod * s3[len - 1] % mod; res %= mod;
	return res;
}

std::bitset <maxn> chk[2];

inline void getchk (int id) {
	chk[id].reset ();

	i64 sum = 0;
	i64 maxx = 0;
	i64 minn = 0x3f3f3f3f;
	rep (i, 1, n) { 
		sum += a[i] * a[i] % mod * a[i] % mod; sum %= mod;
		maxx = std::max (maxx, a[i]);
		minn = std::min (minn, a[i]);

		if (i == 1) { chk[id][i] = true; continue; }

		if ((maxx - minn) % (i - 1) != 0) { chk[id][i] = false; }
		else { chk[id][i] = (calc (minn, i, (maxx - minn) / (i - 1)) == sum); }
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	int T; std::cin >> T;

	while (T--) {
		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }

		init ();

		getchk (0);
		std::reverse (a + 1, a + n + 1);
		getchk (1);

		int ans = 0;
		rep (i, 1, n - 1) {
			ans += chk[0][i] and chk[1][n - i];
		}

		std::cout << ans << "\n";
	}

	return 0;
}
