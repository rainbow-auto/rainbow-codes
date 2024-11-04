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

const int maxn = 1000005;

int n;
int a[maxn], mn;
std::vector<int> vals;

int to[maxn];

std::bitset<maxn> vis;
i64 dfs(int now) {
	int cnt = 0;
	i64 sum = 0;
	int curmn; std::memset(&curmn, 0x3f, sizeof curmn);
	while (not vis[now]) {
		vis.set(now);
		cnt++; sum += a[now];
		curmn = std::min(curmn, a[now]);
		now = to[now];
	}
	return (sum - curmn) + std::min(1ll * (cnt - 1) * curmn, 1ll * (cnt - 1) * mn + 2ll * (curmn + mn));
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i];
		vals.push_back(a[i]);
	}

	std::sort(vals.begin(), vals.end());

	rep (i, 1, n) to[i] = std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;

	std::memset(&mn, 0x3f, sizeof mn);
	rep (i, 1, n) mn = std::min(mn, a[i]);

	i64 ans = 0;
	rep (i, 1, n) {
		if (vis[i]) continue;
		ans += dfs(i);
	}

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
