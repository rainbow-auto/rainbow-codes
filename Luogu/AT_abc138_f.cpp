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

const int mod = 1e9 + 7;

const int maxn = 63;

bool L[maxn], R[maxn];

int f[maxn][2][2][2];

int dfs(int now, bool llim, bool rlim, bool lead) {
	if (now < 0) return 1;

	int& res = f[now][llim][rlim][lead];
	if (~res) return res;
	res = 0;

	// y - x == y ^ x
	rep (x, 0, 1) {
		rep (y, x, 1) {
			if (llim and x < L[now]) continue;
			if (rlim and y > R[now]) continue;
			if ((lead and (x == 0)) and y == 1) continue;
			(res += dfs(now - 1, llim and (x == L[now]), rlim and (y == R[now]), lead and (x == 0))) %= mod;
		}
	}

	return res;
}

int calc(i64 l, i64 r) {
	memset(f, -1, sizeof(f));
	rep (i, 0, 60) L[i] = bool (l & (1ll << i));
	rep (i, 0, 60) R[i] = bool (r & (1ll << i));

	return dfs(60, true, true, true);
}

void solve() {
	i64 l, r; std::cin >> l >> r;

	std::cout << calc(l, r) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
