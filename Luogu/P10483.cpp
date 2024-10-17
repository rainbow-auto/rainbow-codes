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

const int maxn = 100005;

int n;
int w, c[maxn];

int a[maxn];

int ans;
void dfs(int now, int cnt) {
	if (cnt > ans) return;

	if (now > n) return ans = std::min(ans, cnt), void(0);

	rep (i, 1, cnt) {
		if (a[i] + c[now] <= w) {
			a[i] += c[now];
			dfs(now + 1, cnt);
			a[i] -= c[now];
		}
	}

	a[cnt + 1] += c[now];
	dfs(now + 1, cnt + 1);
	a[cnt + 1] -= c[now];
}

void solve() {
	std::cin >> n >> w;
	rep (i, 1, n) std::cin >> c[i];

	std::sort(c + 1, c + n + 1); std::reverse(c + 1, c + n + 1);

	std::memset(&ans, 0x3f, sizeof ans);
	dfs(1, 0);

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
