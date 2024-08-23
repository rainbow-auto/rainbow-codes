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
const i64 mod = 998244353;

i64 ans[maxn];
i64 mul[maxn];

std::vector <int> query;

std::vector <int> primes;
std::bitset <maxn> np;
int minp[maxn]; // 最小质因子
inline void sieve (int R) {
	np[1] = true;
	minp[1] = 1;
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

i64 cnt[maxn];

inline i64 ksm (i64 a, int b) {
	i64 res = 1;
	a %= mod;
	while (b) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod; b >>= 1;
	}
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

bool MemED;
int main () {
	fastread
	// lookMem

	int R = 0;

	int T; std::cin >> T;
	while (T--) {
		int n; std::cin >> n; 
		query.push_back (n); 
		R = std::max (R, n); 
	}

	sieve (R);

	ans[1] = 1;
	mul[1] = 1;
	rep (i, 2, R) {
		// 分解质因数
		std::map <int, int> ps;
		int curr = i;
		while (curr != 1) {
			int p = minp[curr];
			ps[p] ++;
			curr /= minp[curr];
		}

		mul[i] = mul[i - 1];
		for (auto now : ps) {
			mul[i] *= inv (cnt[now.first] + 1); mul[i] %= mod;
			cnt[now.first] += now.second; cnt[now.first] %= mod;
			mul[i] *= (cnt[now.first] + 1); mul[i] %= mod;
		}

		ans[i] = mul[i];
		for (auto now : ps) {
			ans[i] *= inv (cnt[now.first] + 1); ans[i] %= mod;
			ans[i] *= (cnt[now.first] + now.second + 1) % mod; ans[i] %= mod; 
		}
	}

	for (auto q : query) {
		if (q - 1 == 0) { std::cout << "inf\n"; }
		else { std::cout << ans[q - 1] << "\n"; }
	}

	return 0;
}
