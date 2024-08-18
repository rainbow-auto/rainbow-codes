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
#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "\n";
bool MemST;

const int maxn = 20000005;
const i64 mod = 1e9 + 7;

int n;
i64 g[maxn];

int d[maxn];
int num[maxn];

std::bitset <maxn> np;
std::vector <int> primes;

void sieve (int R) {
	d[1] = 1;
	rep (i, 2, R) {
		if (not np[i]) { 
			primes.push_back (i); 
			d[i] = 2; // 约数仅有 1 和 i
			num[i] = 1;
		}

		for (auto p : primes) {
			if (i * p > R) { break; }
			np[i * p] = true;
			if (i % p == 0) {
				d[i * p] = d[i] / (num[i] + 1) * (num[i] + 2);
				num[i * p] = num[i] + 1;
				break;
			} else {
				d[i * p] = d[i] * 2;
				num[i * p] = 1;

			}
		}
	}
}

int pre[maxn];

inline void init () {
	sieve (n);

	pre[1] = n;
	rep (i, 2, n) { pre[i] = pre[i - 1] + d[i - 1]; pre[i] %= mod; }
}

bool MemED;
int main () {
	fastread
	// lookMem

	i64 A, B, C;
	std::cin >> n >> A >> B >> C >> g[n];

	per (i, n - 1, 1) { g[i] = ((((g[i + 1] * g[i + 1]) % mod * A) % mod + (g[i + 1] * B) % mod) % mod + C) % mod; }

	init ();

	i64 ans = 0;
	rep (i, 1, n) {
		ans += (((n - i + 1) * pre[i]) % mod * g[i]) % mod;
		ans %= mod;
	}
	
	std::cout << ans << "\n";

	return 0;
}
