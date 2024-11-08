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

#pragma GCC optimize(2)

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
const i64 mod = 998244353;

int n;
i64 a[maxn];

std::bitset <maxn> np;
std::vector <int> primes;
int minp[maxn];
inline void sieve (int R) {
	minp[1] = 1;
	np[1] = true;

	rep (i, 2, R) {
		if (not np[i]) { primes.push_back (i); minp[i] = i; }

		for (auto p : primes) {
			if (i * p > R) { break; }
			np[i * p] = true;
			minp[i * p] = p;
			if (i % p == 0) { break; } 
		}
	}
}

std::map <int, std::vector <int>> ps; 

inline i64 ksm (i64 a, i64 b) {
	i64 res = 1; a %= mod;
	while (b) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod; b >>= 1;
	}
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	// freopen ("inequality.in", "r", stdin);
	// freopen ("inequality.out", "w", stdout);

	sieve (1000000);

	int T; std::cin >> T;

	while (T--) {
		ps.clear ();

		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }

		rep (i, 1, n) {
			std::map <int, int> pcurr;
			while (a[i] != 1) {
				pcurr[minp[a[i]]] ++;
				a[i] /= minp[a[i]];
			}

			for (auto now : pcurr) {
				ps[now.first].push_back (now.second);
			}
		}

		for (auto now : ps) {
			std::sort (now.second.begin (), now.second.end (), [] (i64 x, i64 y) -> bool { return x > y; });
			rep (i, 1, now.second.size ()) {
				a[i] *= ksm (now.first, now.second[i - 1]); a[i] %= mod;
			}
		}

		i64 ans = 0;
		rep (i, 1, n) { ans += a[i] % mod; ans %= mod; }
		std::cout << ans << "\n";
	}


	return 0;
}
