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

const int maxn = 2000005;

std::bitset<maxn> np;
std::vector<int> ps;
int S[maxn];

inline void sieve(int mx) {
	np.set(1);
	S[1] = 1;
	rep (i, 2, mx) {
		if (not np[i]) {
			ps.push_back(i);
			S[i] = i;
		}

		for (auto p : ps) {
			if (i * p > mx) break;
			np.set(i * p);
			if (not (S[i] % p)) S[i * p] = S[i] / p;
			else S[i * p] = S[i] * p;

			if (not (i % p)) break;
		}
	}
}

int cnt[maxn];

void solve() {
	std::freopen("sqrt.in", "r", stdin);
	std::freopen("sqrt.out", "w", stdout);

	int n, m; std::cin >> n >> m;
	if (n < m) std::swap(n, m);

	sieve(n);	

	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) cnt[S[i]]++;
	i64 ans = 0;
	rep (i, 1, m) ans += cnt[S[i]];

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
