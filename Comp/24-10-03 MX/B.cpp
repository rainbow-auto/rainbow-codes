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

const int maxn = 15;

int n;
int a[maxn], v[maxn];

int ans;

void sub(int now) {
	if (a[now] < 0) return;
	a[now]--;
	if (a[now] == v[now]) {
		rep (i, 1, n) sub(i);
	}
}

int old_a[maxn];

void dfs(int ansnow) {
	bool st = true;
	rep (i, 1, n) st &= a[i] <= 0;

	if (st)	return ans = std::min(ans, ansnow), void(0);

	rep (i, 1, n) {
		memcpy(old_a, a, sizeof a);
		sub(a[i]);
		dfs(ansnow + 1);
		memcpy(a, old_a, sizeof a);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) v[i] = (a[i] >> 1);

	ans = 0x3f3f3f3f;
	dfs(0);

	std::cout << ans << "\n";
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
