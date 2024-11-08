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

const int maxn = 26;
const int maxS = (1 << maxn) + 5;

int n;
int a[maxn];

i64 sum[maxS];
int f[maxS];

inline int lowbit(int x) { return x & -x; }

void solve() {
	std::freopen("cloud.in", "r", stdin);
	std::freopen("cloud.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	per (i, n, 1) a[i] -= a[i - 1];

	int mask = (1 << n) - 1;
	rep (S, 1, mask) {
		sum[S] = sum[S ^ lowbit(S)] + a[__builtin_ctz(S) + 1];
		int cur = S;
		f[S] = 0;
		while (cur) {
			f[S] = std::max(f[S], f[S ^ lowbit(cur)] + (sum[S] == 0));
			cur = (cur ^ lowbit(cur));
		}
	}

	std::cout << n - f[mask] << "\n";
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
