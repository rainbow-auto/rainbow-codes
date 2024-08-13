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
#include <bitset>

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "------------------\n";
#else
#define db(x) void (0);
#define dbline(x) void (0);
#endif

const int maxn = 50005;

int mu[maxn];

std::vector <int> primes;
std::bitset <maxn> np;

void sieve (int R) {
	np[1] = true;
	mu[1] = 1;

	rep (i, 2, R) {
		if (not np[i]) { primes.push_back (i); mu[i] = -1; }

		for (auto p : primes) {
			if (i * p > R) { break; }
			np.set (i * p);
			mu[i * p] = mu[i] * -1;
			if (i % p == 0) { mu[i * p] = 0; break; }
		}
	}
}

int n;
int a[maxn];

int cnt[maxn];

int main () {
	fastread
	
	std::cin >> n;

	int mx = 0;
	rep (i, 1, n) { std::cin >> a[i]; cnt[a[i]] ++; mx = std::max (mx, a[i]); }

	sieve (mx);

	i64 ans = 0;
	rep (T, 1, mx) {
		i64 s = 0; rep (i, 1, mx / T) { s += i * cnt[i * T]; }
		i64 f = 0;
		for (int d = 1; d * d <= T; d++) { 
			if (T % d == 0) { 
				f += mu[d] * d;
				if (T / d != d) { f += mu[T / d] * (T / d); }
			} 
		}

		ans += T * f * s * s;
	}	

	std::cout << ans << "\n";

	return 0;
}
