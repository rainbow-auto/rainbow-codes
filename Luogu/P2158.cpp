#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 40005;

int n;

std::bitset<maxn> np;
int mu[maxn], sum[maxn];
std::vector<int> ps;
inline void sieve(int R) {
	mu[1] = 1;
	np.set(1);
	rep (i, 2, n) {
		if (not np[i]) {
			ps.push_back(i);
			mu[i] = -1;
		}

		for (auto p : ps) {
			if (i * p > R) break;
			np.set(i * p);
			if (i % p == 0) {
				mu[i * p] = 0;
				break;
			} else mu[i * p] = -1 * mu[i];
		}
	}
}

inline i64 calc(int R) {
	i64 res = 0;
	rep (d, 1, R) res += mu[d] * (R / d) * (R / d);
	return res;
}

void solve() {
	std::cin >> n;

	if (n == 1) return std::cout << "0\n", void(0);

	sieve(n);

	i64 ans = 2 + calc(n - 1);

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
