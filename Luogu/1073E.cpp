#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 25;
const int maxS = (1 << 10) + 5;
const i64 mod = 998244353;

int k;

i64 pw10[maxn];

inline void init () {
	pw10[0] = 1;
	rep (i, 1, 20) { pw10[i] = pw10[i - 1] * 10ll % mod; }
}

inline int popcount (int S) {
	int res = 0; while (S) { res += S & 1; S >>= 1; }
	return res;
}

int a[maxn], len;

std::pair <i64, i64> mem[maxn][maxS];
std::pair <i64, i64> dp (int now, int S, bool lim, bool lead) {
	if (not now) { return { popcount (S) <= k, 0 }; }
	if (not lim and not lead and mem[now][S].first != -1) { return mem[now][S]; }

	std::pair <i64, i64> res = { 0, 0 };

	int mx = lim ? a[now] : 9;
	rep (t, 0, mx) {
		int nS = (lead and t == 0) ? S : (S | (1 << t));

		i64 cnt, sum; 
		std::tie (cnt, sum) = dp (now - 1, nS, lim and t == mx, lead and t == 0);
		
		res.first += cnt; res.first %= mod;
		res.second += (t * pw10[now - 1] % mod * cnt % mod + sum) % mod; res.second %= mod;
	}

	if (not lim and not lead) { mem[now][S] = res; }
	return res;
}

inline i64 solve (i64 val) {
	rep (i, 0, 20) {
		rep (S, 0, 1 << 10) { mem[i][S] = { -1, -1 }; }
	}

	memset (a, 0, sizeof (a));
	len = 0;

	while (val) { a[++len] = val % 10ll; val /= 10ll; }

	return dp (len, 0, true, true).second;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	init ();

	i64 l, r; std::cin >> l >> r >> k;

	std::cout << ((solve (r) - solve (l - 1ll)) % mod + mod) % mod << "\n";

	return 0;
}
